#pragma once

#include "Link.hpp"
#include <iostream>


class SymbolicLink : public Link {
public:
    SymbolicLink(std::string name, Folder *parent, FileObject *target)
            : Link(name, parent, target) {}

    void toString() override;
};