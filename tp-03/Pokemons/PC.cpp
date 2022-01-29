#include "PC.h"

#include "Trainer.h"

void PC::give_back(Trainer& trainer, const std::string& pokemon_name) {
    for (int i = 0; i < (int)_pokemons.size(); i++)
    {
        const std::unique_ptr<Pokemon>& pokemon = _pokemons[i];
        if (pokemon->trainer() == &trainer && pokemon->name() == pokemon_name)
        {
            trainer.capture(std::move(_pokemons[i]));
            _pokemons.erase(_pokemons.begin() + i);
            break;
        }
    }
}
