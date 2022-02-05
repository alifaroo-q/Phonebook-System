#include "Contact.h"

Contact::Contact(int id, int phone, std::string name, std::string email) {
    this->id = id;
    this->phone = phone;
    this->name = name;
    this->email = email;
}

Contact::~Contact() {}

int Contact::getId() {
    return id;
}

void Contact::setId(int id) {
    this->id = id;
}

int Contact::getPhone() {
    return phone;
}

void Contact::setPhone(int phone) {
    this->phone = phone;
}

std::string Contact::getName() {
    return name;
}

void Contact::setName(std::string name) {
    this->name = name;
}

std::string Contact::getEmail() {
    return email;
}

void Contact::setEmail(std::string email) {
    this->email = email;
}
