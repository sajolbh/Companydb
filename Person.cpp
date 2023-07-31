#include "Person.h"

Person::Person() {
    // Default constructor
}

Person::Person(std::string name, std::string _email, std::string _phone)
        : name(name), _email(_email), _phone(_phone) {
    // Constructor with parameters
}

std::string Person::getName() const {
    return name;
}

void Person::setName(std::string name) {
    this->name = name;
}

std::string Person::getEmail() const {
    return _email;
}

void Person::setEmail(std::string _email) {
    this->_email = _email;
}

std::string Person::getPhone() const {
    return _phone;
}

void Person::setPhone(std::string _phone) {
    this->_phone = _phone;
}
