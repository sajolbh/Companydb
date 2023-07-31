#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    double _salary;

public:
    Employee();
    Employee(std::string name, std::string _email, std::string _phone, double _salary);

    double getSalary() const;
    void setSalary(double _salary);
};

#endif  // EMPLOYEE_H
