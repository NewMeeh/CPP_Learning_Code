// #include <iostream>
// #include <memory>
// #include <utility>
// #include <vector>

// std::unique_ptr<int> passthrough(std::unique_ptr<int> ptr) {
//     std::unique_ptr<int> local = std::move(ptr);
//     return local;
// }

// void display(const std::string& variable_name, const std::unique_ptr<int>& variable) {
//     if (variable == nullptr)
//     { std::cout << variable_name << " is empty." << std::endl; }
//     else
//     { std::cout << variable_name << " contient " << *variable << std::endl; }
// }

// int main() {
//     std::unique_ptr<int> i1, i2;
//     i1 = std::make_unique<int>(1);
//     i2 = std::make_unique<int>(2);

//     display("i1", i1);
//     display("i2", i2);

//     i2 = passthrough(std::move(i1));

//     display("i1", i1);
//     display("i2", i2);n
// }

// // int main() {
// //     std::vector<std::string> many_ints;

// //     auto value = "prout";

// //     if (value != nullptr)
// //     { std::cout << "value is " << value << std::endl; }
// //     else
// //     { std::cout << "value is empty" << std::endl; }

// //     many_ints.emplace_back(std::move(value));

// //     if (value != nullptr)
// //     { std::cout << "value is " << value << std::endl; }
// //     else
// //     { std::cout << "value is empty" << std::endl; }

// //     std::cout << many_ints[0] << std::endl;

// //     return 0;
// // }

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Resource
{
    Resource(const std::string& content)
        : _content { content } {}

    std::string _content;
};

// Index objects of type Resource and handle their lifespans.
class ResourceManager
{
public:
    // Create a new resource.
    // Return the index where the resource was created.
    size_t create(const std::string& content) {
        _resources.emplace_back(std::make_unique<Resource>(content));
        return _resources.size() - 1;
    }

    // Destroy the resource at the given index.
    // The other elements keep the same index, we do not reorganize the array.
    void destroy(size_t index) {
        if (_resources.size() > index && _resources[index] != nullptr)
        {
            _resources[index].reset();
            _resources[index] = nullptr;
        }
    }

    // Take the ownership of an existing resource.
    // Return the index where the resource was placed.
    size_t acquire(std::unique_ptr<Resource> resource) {
        _resources.emplace_back(std::move(resource));
        return _resources.size() - 1;
    }

    // Transfer the resource at the given index to the caller.
    std::unique_ptr<Resource> yield(size_t index) {
        if (index < _resources.size() && _resources[index] != nullptr)
        { return std::move(_resources[index]); }
        return nullptr;
    }

    // Provide access to the resource at the given index.
    Resource& get(size_t index) const { return *_resources[index]; }

private:
    std::vector<std::unique_ptr<Resource>> _resources;
};

int main() {
    ResourceManager manager;
    manager.create("coucou");
    manager.create("les");
    manager.destroy(manager.create("amis"));
    std::cout << manager.yield(0)->_content << std::endl;
    std::cout << manager.get(1)._content << std::endl;

    return 0;
}
