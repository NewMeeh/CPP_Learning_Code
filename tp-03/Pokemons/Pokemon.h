#pragma once

#include <string>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(std::string name)
        : _name { name }
        , _trainer { nullptr } {}

    std::string name() { return _name; }
    Trainer*    trainer() { return _trainer; }
    void        trainer(Trainer* trainer) { _trainer = trainer; }

private:
    std::string _name;
    Trainer*    _trainer;
};
