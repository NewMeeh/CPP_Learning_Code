
#pragma once

#include <iostream>
#include <vector>

class Histogram
{
public:
    Histogram();
    Histogram(const Histogram&);
    void analyze(const std::string&); // analyse la string passée en paramètre
    void print() const;               // affiche l'histogramme

private:
    friend std::ostream&      operator<<(std::ostream& out, const Histogram& histo);
    std::vector<unsigned int> _count = std::vector<unsigned int>(
        26, 0); // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
};
