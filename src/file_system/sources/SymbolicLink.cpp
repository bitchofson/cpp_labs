#include "SymbolicLink.hpp"
#include <iostream>

void SymbolicLink::toString() {
    std::cout << "Тип: Символьная ссылка" << std::endl;
    Link::toString();
}