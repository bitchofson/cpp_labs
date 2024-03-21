#include "HardLink.hpp"
#include <iostream>

void HardLink::remove() {
    delete target;
    FileObject::remove();
}

void HardLink::toString() {
    std::cout << "Тип: Жёсткая ссылка" << std::endl;
    Link::toString();
}