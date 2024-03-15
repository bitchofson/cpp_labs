#pragma once

#include <iostream>
#include <ctime>

class FileSystemElement
{
private:

protected:

    std::string name;
    
    time_t create_time;
    time_t modify_time;

public:

    FileSystemElement(std::string name) : 
    
    name(name), 
    create_time(time(nullptr)), 
    modify_time(time(nullptr)) 

    { }

    ~FileSystemElement();

    virtual void rename(std::string name) const = 0;
    virtual void move(std::string path) const = 0;
    virtual void remove() const = 0;
    
    std::string get_name() { return this->name; };

    time_t get_create_time() { return this->create_time; };
    time_t get_modify_time() { return this->modify_time; };

};
