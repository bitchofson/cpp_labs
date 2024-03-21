#include "FileObject.hpp"
#include "Link.hpp"

#include <iostream>


Link::Link(std::string name, Folder *parent, FileObject *target)
        : FileObject(name, parent), target(target) {}

Link::~Link() {
    std::cout << "Ссылка " << name << " удалена(Деструктор)" << std::endl;
}

void Link::move(Folder *old_folder, Folder *new_folder) {
    destination = new_folder->get_destination() + "/" + name;
    new_folder->add_object(this);
    old_folder->remove_element(name);
    set_parent(new_folder);
    modify_date();
}

void Link::toString() {
    FileObject::toString();
    std::cout << "Ссылается на: " << std::endl;
    target->toString();
}

void Link::set_target(FileObject *new_target) {
    target = new_target;
    modify_date();
}

FileObject *Link::get_target() {
    return target;
}