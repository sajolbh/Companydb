#include "Customer.h"

Customer::Customer(){}

Customer::Customer(std::string name, std::string email, std::string phone)
        : _name(name), _email(email), _phone(phone) {}
Customer::Customer(std::string name, std::string email, std::string phone, std::vector<Purchase> history)
        : _name(name), _email(email), _phone(phone), _history(history) {}

void Customer::addPurchase(const Purchase& purchase)  {
    _history.push_back(purchase);
}

Customer::const_iterator Customer::purchaseBegin() const {
    return _history.begin();
}

Customer::const_iterator Customer::purchaseEnd() const {
    return _history.end();
}

std::vector<Purchase> Customer::getOrderHistory() const {
    return _history;
}

std::string Customer::getName() const {
    return _name;
}

std::string Customer::getEmail() const {
    return _email;
}

std::string Customer::getPhone() const {
    return _phone;
}

void Customer::setName(std::string _name) {
    this->_name = _name;
}

void Customer::setEmail(std::string _email) {
    this->_email = _email;
}

void Customer::setPhone(std::string _phone) {
    this->_phone = _phone;
}
