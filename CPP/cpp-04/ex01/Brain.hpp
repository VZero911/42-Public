#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif