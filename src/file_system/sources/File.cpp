#include "File.hpp"
#include <iostream>


File::~File() {
    std::cout << "Файл " << name << " удалён (Деструктор)" << std::endl;
}

void File::set_extentsion(std::string new_extension) {
    extension = new_extension;
    modify_date();
    std::cout << "Расширение файла изменено на" << extension << std::endl;
}

void File::move(Folder *old_folder, Folder *new_folder) {
    destination = new_folder->get_destination() + "/" + name;
    new_folder->add_object(this);
    old_folder->remove_element(name);
    set_parent(new_folder);
    modify_date();
}

void File::toString() {
    std::cout << "Тип: Файл" << std::endl;
    FileObject::toString();
    std::cout << "Расширение: " << extension << std::endl;
    std::cout << "Размер: " << size << std::endl;
}

std::string File::get_extension() {
    return extension;
}

size_t File::get_size() {
    return size;
}
