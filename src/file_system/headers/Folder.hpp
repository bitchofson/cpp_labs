#pragma once

#include "FileObject.hpp"
#include <vector>


class Folder : public FileObject {
private:
    std::vector<FileObject *> objects;

public:
    Folder(std::string name, Folder *parent);

    ~Folder() override;

    void remove() override;

    void rename(std::string new_name) override;

    void move(Folder *old_folder, Folder *new_folder);

    void remove_element(std::string element_name);

    void add_object(FileObject *object);

    void toString() override;

    void print_inner();
};