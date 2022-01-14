#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    using namespace std;

    if (argc < 2)
    {
        cerr << "Error : Where is the size of the array ?" << endl;
        return -1;
    }

    int length = stoi(argv[1]);
    if (length <= 0)
    { cerr << "The length cannot be null or negative" << endl; }

    vector<int> array;

    for (int i = 0; i < length; i++)
    { array.emplace_back(i + 1); }

    for (int value : array)
    { cout << value << endl; }

    // int array[length] = {};

    // for (int i = 0; i < length; i++)
    // { array[i] = i + 1; }

    // for (int i : array)
    // { cout << i << endl; }

    return 0;
}
