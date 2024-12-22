/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:24:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 21:24:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_Shell_State
{
	char	current_path[1024];
	char	**envp;
	int		last_exit_status;
	int		num_pipes;
	int		index;
}	t_state;

// Structure temporaire pour stocker les tokens et commandes
typedef struct s_command
{
	char				**args; // Liste des arguments
	char				*infile; // Redirection d'entrée (<)
	char				*outfile; // Redirection de sortie (>)
	char				*limiter; // EOF pour le heredoc
	int					heredoc; // Flag pour redirection heredoc (<<)
	int					append; // Flag pour redirection append (>>)
	int					is_pipe; // Flag pour un pipe (|)
	struct s_command	*next; // liste chainer de commandes
	struct s_command	*prev; // // liste chainer de prev de commandes
}	t_command;

// Structure pour un token en liste chaînée
typedef struct s_token
{
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

void		handle_cd_command(char **argv, t_state *state);
void		handle_pwd_command( t_state *state);
void		handle_env_command(char **envp);
void		handle_echo_command(t_command *cmd);
void		handle_unset_command(char **argv, char **envp);
void		handle_export_command(char **argv, t_state *state);
void		handle_neosnitch_command(char **argv, t_state *state);

void		exec_shell(t_command *cmd, t_state *state);
void		handle_external_cmd(t_command *cmd, char **argv, t_state *state);
void		handle_multiples_pipes(t_command *cmd, t_state *state);
int			exec_builtins(t_command *cmd, t_state *state);
char		*join_key_value(const char *key, const char *value);
void		replace_env_entry(char **envp, int index, const char *key,
				const char *value);
char		*get_command_path(char *cmd);
void		reset_state(t_state *state);

char		**copy_environment(char **envp);
char		**set_env_var(char **envp, const char *key, const char *value);
char		**realloc_tab(char **envp, const char *new_entry);

// Parsing
t_command	*parse_input(t_command **cmd, const char *input, char **envp);
t_command	*init_command(void);
int			handle_redirections(t_command *cmd);
t_token		*create_and_add_token(t_token **head, char *content);
int			handle_token(t_token **head, const char *input,
				int *i, char **envp);
t_token		*tokenize_input(const char *input, char **envp);
int			skip_spaces(const char *input, int i);
char		*parse_quoted_token(const char *input, int *i, char **envp);
char		*expand_variable(char *input, int *i, char **envp);
int			check_unclosed_quotes(const char *input);
int			handle_heredoc(t_command *cmd);
int			handle_redirection(t_command *current_cmd, t_token *current);
char		*parse_single_quote(const char *input, int *i);
char		*parse_double_quote(const char *input, int *i, char **envp);
int			is_special_char(char c);
int			handle_arguments(t_command *current_cmd,
				t_token *current, int *arg_index);
int			handle_pipe(t_command **current_cmd, int *arg_index);
t_command	*add_new_node(void);
int			fill_command_args(t_command *cmd, t_token *current, int *index);

// Signals
void		handle_sigint(int signo);
void		handle_sigquit(int signo);
void		setup_signals(void);

// Utils
void		free_command(t_command *cmd);
void		free_command_list(t_command *cmd);

//debug
void		print_command_list(t_command *cmd);

//free
void		free_command_list(t_command *cmd);
void		free_tokens(t_token *head);
void		free_environment(char **envp);

#endif