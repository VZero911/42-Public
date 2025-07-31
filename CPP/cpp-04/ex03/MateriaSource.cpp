#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        learned[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.learned[i])
            learned[i] = other.learned[i]->clone();
        else
            learned[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (learned[i])
            {
                delete learned[i];
                learned[i] = 0;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (other.learned[i])
                learned[i] = other.learned[i]->clone();
            else
                learned[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (learned[i])
            delete learned[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!learned[i])
        {
            learned[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (learned[i] && learned[i]->getType() == type)
        {
            return learned[i]->clone();
        }
    }
    return 0;
}