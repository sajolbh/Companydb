#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>
#include "Employee.h"
#include "Customer.h"

class Company {
private:
    std::vector<Employee> _employees; //Private vector to store employee
    std::vector<Customer> customers;//Private vector to store customers
    std::string name; //Private string to store company name

public:
    Company(std::string name); //Constructor

    std::string getName() const; //Getter method
    void setName(std::string name); //setter method

    void addEmployee(const Employee& employee); //Method to add employee
    void addCustomer(const Customer& customer);// Method to add customer

    std::vector<Employee>::const_iterator employeeBegin() const;//Using Iterators to get the beginning of employee vector
    std::vector<Employee>::const_iterator employeeEnd() const; //Using Iterator to get the end of employee vector
    std::vector<Customer>::const_iterator customerBegin() const; //Using Iterator to get the beginning of customer vectot
    std::vector<Customer>::const_iterator customerEnd() const;// using Iterator to get the end of Customer vector

    void replaceCustomer(const Customer &oldCustomer, const Customer &newCustomer);//Method to replace customer to a new customer

    Customer getCustomer(const Customer& customerToMatch) const; //Method to retrieve customer matching a given customer object
};

#endif  // COMPANY_H
