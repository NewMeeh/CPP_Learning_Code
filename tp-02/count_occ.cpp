#include "Histogram.h"

int main() {
    Histogram h1, h2;
    Histogram h3 { Histogram { h1 } };
    return 0;
}
