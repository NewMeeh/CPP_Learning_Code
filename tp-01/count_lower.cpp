#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned int> count_lower(const std::string& str) {
    std::vector<unsigned int> res(26, 0);
    for (auto c : str)
    {
        if (('a' <= c) && (c <= 'z'))
            res[c - 'a'] += 1;
    }
    return res;
}

void display_lower_occ(const std::vector<unsigned int>& array) {
    for (unsigned long i = 0; i < array.size(); i++)
    { std::cout << (char)('a' + i) << " : " << array[i] << std::endl; }
}

int main() {
    std::string str, full_str;
    do
    {
        full_str += str;
        std::cin >> str;
    }
    while (str != "QUIT");

    display_lower_occ(count_lower(full_str));
    std::cout << full_str << std::endl;
    return 0;
}
