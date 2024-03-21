#pragma once

#include "FileObject.hpp"
#include "Folder.hpp"

#include <iostream>
#include <string>

class Link : public FileObject {
protected:
    FileObject *target;

public:
    Link(std::string name, Folder *parent, FileObject *target);

    ~Link();

    void move(Folder *old_folder, Folder *new_folder);

    virtual void toString() override;

    void set_target(FileObject *new_target);

    FileObject *get_target();
};