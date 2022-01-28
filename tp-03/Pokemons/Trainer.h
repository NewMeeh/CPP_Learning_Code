#pragma once
#include "PC.h"
#include "Pokeball.h"
// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(std::string name, PC& pc)
        : _name { name }
        , _pc { pc } {}

    std::string name() { return _name; }

    std::array<Pokeball, 6>& pokeballs() { return _pokeballs; }

private:
    std::string             _name;
    PC&                     _pc;
    std::array<Pokeball, 6> _pokeballs { Pokeball(), Pokeball(), Pokeball(),
                                         Pokeball(), Pokeball(), Pokeball() };
};
