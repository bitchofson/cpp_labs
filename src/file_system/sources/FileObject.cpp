#include "FileObject.hpp"

#include <iostream>
#include <ctime>
#include <string>

FileObject::FileObject(const std::string name, Folder* parent) {
    
    this->name = name;
    time_t currDate = time(0);
    
    this->created_time = ctime(&currDate);
    this->modified_time = ctime(&currDate);

    this->destination = name;
    this->parent = parent;
}

FileObject::~FileObject() {
}

void FileObject::remove() {
    set_parent(nullptr);
    delete this;
}

void FileObject::modify_date() {
    time_t currDate = time(0);
    this->modified_time = ctime(&currDate);
    std::cout << "Дата изменина" << std::endl;
}

std::string FileObject::get_name() {
    return name;
}

std::string FileObject::get_modified_time() {
    return modified_time;
}

std::string FileObject::get_created_time() {
    return created_time;
}

std::string FileObject::get_destination() {
    return destination;
}

void FileObject::set_destination(std::string new_destination) {
    destination = new_destination;
}


void FileObject::set_parent(Folder *new_parent) {
    parent = new_parent;
}

void FileObject::rename(const std::string new_name) {
    name = new_name;
    size_t slashIndex = new_name.find_last_of('/');
    destination = new_name.substr(0, slashIndex + 1);
    modify_date();
    std::cout << "Имя изменено на: " << new_name << std::endl;
}

void FileObject::toString() {
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Путь: " << destination << std::endl;
    std::cout << "Дата создания: " << created_time;
    std::cout << "Дата изменения: " << modified_time;
}