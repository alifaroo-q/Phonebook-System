#include "Contact.h"

Contact::Contact(int id, std::string phone, std::string name, std::string email) {
    this->id = id;
    this->phone = phone;
    setName(name);
    this->email = email;
}

Contact::~Contact() {}

int Contact::getId() {
    return id;
}

void Contact::setId(int id) {
    this->id = id;
}

std::string Contact::getPhone() {
    return phone;
}

void Contact::setPhone(std::string phone) {
    this->phone = phone;
}

std::string Contact::getName() {
    return name;
}

void Contact::setName(std::string name) {
    char space = ' ';
    char rep = '-';

    for (int i = 0; i < name.size(); i++) {
        if (name[i] == space) {
            name[i] = rep;
        }
    }

    this->name = name;
}

std::string Contact::getEmail() {
    return email;
}

void Contact::setEmail(std::string email) {
    this->email = email;
}

std::string Contact::toString() {
    std::string str = std::to_string(id) + " " + phone + " " + name + " " + email;
    return str;
}
