#pragma once
#include "Pokemon.h"
// A ball where Pokemon sleep.
class Pokeball
{
public:
    // Pokeball(const Pokeball& other)
    //     : _pokemon { std::make_unique<Pokemon>(*other._pokemon) } {}
    bool     empty() const { return _pokemon == nullptr; }
    void     store(std::unique_ptr<Pokemon> pokemon) { _pokemon = std::move(pokemon); }
    Pokemon& pokemon() const { return *_pokemon; }

private:
    std::unique_ptr<Pokemon> _pokemon;
};