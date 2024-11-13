#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _materias[i] = (0);
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete _materias[i];
}

void MateriaSource::learnMateria(AMateria* m)  {
    if (!m) return;
    for (int i = 0; i < 4; ++i) 
    {
        if (_materias[i] == (0)) 
        {
            _materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)  {
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            // std::cout << "creation of : " << _materias[i]->getType() << std::endl;
            return _materias[i]->clone();
        }
    }
    return (0);
}
