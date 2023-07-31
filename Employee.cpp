#include "Employee.h"

Employee::Employee() :  Person() {
    // Default constructor
    setSalary(0.0);
}

Employee::Employee(std::string name, std::string _email, std::string _phone, double _salary)
        : Person(name, _email, _phone)  {
    // Constructor with parameters
    setSalary(_salary);
}

double Employee::getSalary() const {
    return _salary;
}

void Employee::setSalary(double _salary) {
    this->_salary = _salary;
}