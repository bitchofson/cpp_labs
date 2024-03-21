#pragma once

#include "Link.hpp"
#include <iostream>

class HardLink : public Link {
public:
    HardLink(std::string name, Folder* parent, FileObject* target)
            : Link(name, parent, target) {}

    void remove() override;

    void toString() override;
};