#include "Company.h"

Company::Company(std::string name) : name(name) {
    // Constructor
}

std::string Company::getName() const {
    return name;
}

void Company::setName(std::string name) {
    this->name = name;
}

void Company::addEmployee(const Employee& employee) {
    _employees.push_back(employee);
}

void Company::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void Company::replaceCustomer(const Customer& oldCustomer, const Customer& newCustomer) {
    // Find the iterator pointing to the old customer in the customers vector
    auto it = std::find_if(customers.begin(), customers.end(), [&](const Customer& customer) {
        return customer.getName() == oldCustomer.getName() &&
               customer.getEmail() == oldCustomer.getEmail() &&
               customer.getPhone() == oldCustomer.getPhone();
    });

    // If the old customer is found, replace it with the new customer
    if (it != customers.end()) {
        *it = newCustomer;
    }
}

bool equalsIgnoreCase(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    for (std::size_t i = 0; i < str1.length(); ++i) {
        if (std::tolower(str1[i]) != std::tolower(str2[i])) {
            return false;
        }
    }

    return true;
}

void removeSpaces(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), str.end());
}

Customer Company::getCustomer(const Customer& customerToMatch) const {
    for (const auto& customer : customers) {
        std::string matchName = customerToMatch.getName();
        std::string existingName = customer.getName();
        std::string matchEmail = customerToMatch.getEmail();
        std::string existingEmail = customer.getEmail();
        removeSpaces(matchName);
        removeSpaces(existingName);
        removeSpaces(matchEmail);
        removeSpaces(existingEmail);

        if (existingName == matchName && existingEmail == matchEmail) {
            return customer;
        }
    }

    // Customer not found, return a default-constructed Customer object
    return Customer();
}


std::vector<Employee>::const_iterator Company::employeeBegin() const {
    return _employees.begin();
}

std::vector<Employee>::const_iterator Company::employeeEnd() const {
    return _employees.end();
}

std::vector<Customer>::const_iterator Company::customerBegin() const {
    return customers.begin();
}

std::vector<Customer>::const_iterator Company::customerEnd() const {
    return customers.end();
}





