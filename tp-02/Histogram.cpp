#include "Histogram.h"

std::ostream& operator<<(std::ostream& out, const Histogram& histo) {
    for (unsigned long i = 0; i < histo._count.size(); i++)
    { out << (char)('a' + i) << " : " << histo._count[i] << std::endl; }
    return out;
}

Histogram::Histogram() {
}

Histogram::Histogram(const Histogram& other)
    : _count { other._count } {
    std::cout << "copie" << std::endl;
}

void Histogram::analyze(const std::string& str) {
    for (auto c : str)
    {
        if (('a' <= c) && (c <= 'z'))
            _count[c - 'a'] += 1;
    }
}

void Histogram::print() const {
    for (unsigned long i = 0; i < _count.size(); i++)
    { std::cout << (char)('a' + i) << " : " << _count[i] << std::endl; }
}
