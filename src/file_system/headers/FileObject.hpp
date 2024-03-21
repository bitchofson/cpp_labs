#pragma once

#include <string>

class Folder;

class FileObject
{
private:

protected:
    std::string name;
    std::string destination;

    std::string created_time;
    std::string modified_time;

    Folder* parent;

public:
    FileObject(const std::string name, Folder *parent);

    virtual ~FileObject();

    virtual void remove();
    virtual void rename(const std::string new_name);
    virtual void toString();

    void set_parent(Folder* new_parent);
    void set_destination(std::string new_destination);
    void modify_date();

    std::string get_created_time();
    std::string get_modified_time();
    std::string get_name();
    std::string get_destination();
};