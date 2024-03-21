#include "Folder.hpp"
#include <iostream>

Folder::Folder(std::string name, Folder *parent)
        : FileObject(name, parent) {}

Folder::~Folder() {
    objects.clear();
    std::cout << "Папка " << name << " удалена (Деструктор)" << std::endl;
}

void Folder::remove() {
    if (name == "root") {
        return;
    } else {
        objects.clear();
        FileObject::remove();
    }
}

void Folder::rename(std::string new_name) {
    if (name == "root") {
        std::cout << "Нельзя переименовать root";
    } else {
        FileObject::rename(new_name);
    }
}

void Folder::move(Folder *old_folder, Folder *new_folder) {
    if (name == "root") {
        std::cout << "Нельзя переместить root" << std::endl;
    } else {
        destination = new_folder->get_destination() + "/" + name;
        new_folder->add_object(this);
        old_folder->remove_element(name);
        set_parent(new_folder);
        modify_date();
    }
}

void Folder::remove_element(std::string element_name) {
    for (int i = 0; i < objects.size(); ++i) {
        if (objects[i]->get_name() == element_name) {
            objects.erase(objects.begin() + i);
            //objects[i]->set_parent(nullptr);
            //delete objects[i];
            break;
        }
    }
    modify_date();
    std::cout << "Объект успешно удалён" << std::endl;
}

void Folder::add_object(FileObject *object) {
    objects.push_back(object);
    object->set_destination(destination + "/" + object->get_name());
    object->set_parent(this);
    modify_date();
    std::cout << "Объект успешно добавлен" << std::endl;
}

void Folder::toString() {
    std::cout << "Тип: Папка" << std::endl;
    FileObject::toString();
}

void Folder::print_inner() {
    std::cout << "Папка " << name <<" содержит: " << std::endl;
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->toString();
    }
}
