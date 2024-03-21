#include <iostream>

#include "File.hpp"
#include "SymbolicLink.hpp"

class FileSystem {
private:
    Folder root;

public:
    FileSystem() : root("root", &root) {}

    Folder *get_root() {
        return &root;
    }
};

int main() {

    FileSystem file_system;

    std::cout << "--------------------------------------" << std::endl;
    Folder *root = file_system.get_root();

    Folder home("home", root);
    root->toString();
    std::cout << "--------------------------------------" << std::endl;
    root->add_object(&home);
    root->print_inner();
    std::cout << "--------------------------------------" << std::endl;
    home.rename("dev");
    root->print_inner();
    std::cout << "--------------------------------------" << std::endl;

    File file("data", root, "txt", 256);
    std::cout << "--------------------------------------" << std::endl;
    root->add_object(&file);
    std::cout << "--------------------------------------" << std::endl;
    file.move(root, &home);
    std::cout << "--------------------------------------" << std::endl;
    home.print_inner();
    std::cout << "--------------------------------------" << std::endl;


    return 0;
}