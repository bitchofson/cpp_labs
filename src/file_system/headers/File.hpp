#pragma once

#include "FileObject.hpp"
#include "Folder.hpp"

#include <iostream>


class File : public FileObject 
{
private:
    std::string extension;
    size_t size;

public:
    File(std::string name, Folder *parent, std::string extension, size_t size)
            : FileObject(name, parent), extension(extension), size(size) {}

    ~File();

    void set_extentsion(std::string new_extension);

    void move(Folder *old_folder, Folder *new_folder);

    void toString() override;

    std::string get_extension();

    size_t get_size();
};