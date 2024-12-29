#include "../include/Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
	{
        _inventory[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
	{
        if (_inventory[i])
            delete _inventory[i];
    }
}

Character::Character(Character const &copy) : _name(copy._name)
{
    for (int i = 0; i < 4; i++)
	{
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character &Character::operator=(Character const &copy)
{
    if (this != &copy)
	{
        for (int i = 0; i < 4; i++)
		{
            if (_inventory[i])
                delete _inventory[i];
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
    for (int i = 0; i < 4; i++)
	{
        if (!_inventory[i])
		{
            _inventory[i] = m->clone();
            return;
        }
    }
    std::cout << "Impossible to equip inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
    else
        std::cout << "No Materia available here" << std::endl;
}