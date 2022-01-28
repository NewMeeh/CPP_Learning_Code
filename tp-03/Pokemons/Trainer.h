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
    void                     capture(std::unique_ptr<Pokemon> pokemon) {
        pokemon->trainer(this);
        for (int i = 0; i < 6; i++)
        {
            if (_pokeballs[i].empty())
            {
                _pokeballs[i].store(std::move(pokemon));
                return;
            }
        }
        _pc.receive(std::move(pokemon));
    }

    void store_in_pc(int index) {
        if (0 <= index && index < 6 && !_pokeballs[index].empty())
        { _pc.receive(std::move(_pokeballs[index].release())); }
    }

private:
    std::string             _name;
    PC&                     _pc;
    std::array<Pokeball, 6> _pokeballs {};
};
