#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include "Company.h"
#include "Employee.h"
#include "Customer.h"

void displayMainMenu() {
    std::cout << "\n----- Main Menu -----" << std::endl;
    std::cout << "1. Employees" << std::endl;
    std::cout << "2. Sales" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Please enter your choice (1-3): ";
}

void displayEmployeeMenu() {
    std::cout << "\n----- Employee Menu -----" << std::endl;
    std::cout << "A. Add Employee" << std::endl;
    std::cout << "M. Main Menu" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Please enter your choice (A/M): ";
}

void displaySalesMenu() {
    std::cout << "\n----- Sales Menu -----" << std::endl;
    std::cout << "A. Add Customer" << std::endl;
    std::cout << "S. Enter Sale" << std::endl;
    std::cout << "V. View Customers" << std::endl;
    std::cout << "M. Main Menu" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Please enter your choice (A/S/V/M): ";
}
/**
 * \brief Saves the company information to a file.
 *
 * This method saves the company information, including the company name,
 * employees, customers, and their order history, to a file specified by the
 * given filename.
 *
 * \param filename The name of the file to save the company information to.
 * \param company The Company object containing the information to save.
 */
void saveCompanyToFile(const std::string& filename, const Company& company) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    // save/write number of employees
    int totalEmployees = std::distance(company.employeeBegin(), company.employeeEnd());
    file << totalEmployees << std::endl;

    // Save employees
    std::vector<Employee>::const_iterator empIt;
    for (empIt = company.employeeBegin(); empIt != company.employeeEnd(); ++empIt) {
        file << empIt->getName() << std::endl;
        file << empIt->getEmail() << std::endl;
        file << empIt->getPhone() << std::endl;
        file << empIt->getSalary() << std::endl;
    }
    std::vector<std::string> orderDetails;

    // save/write number of customers
    int totalCustomers = std::distance(company.customerBegin(), company.customerEnd());
    file << totalCustomers << std::endl;

    std::vector<Customer>::const_iterator custIt;
    for (custIt = company.customerBegin(); custIt != company.customerEnd(); ++custIt) {
        file << custIt->getName() << std::endl;
        file << custIt->getEmail() << std::endl;
        file << custIt->getPhone() << std::endl;

        // Save customer order history
        std::vector<Purchase> orders = custIt->getOrderHistory();

        // save/write number of customer's number of purchases
        file << orders.size() << std::endl;

        for (const auto& order : orders) {
            file << order.getItem() << std::endl;
            file << order.getQty() << std::endl;
            file << order.getCost() << std::endl;

            orderDetails.push_back( order.getItem() + " , " + std::to_string(order.getQty())
                                    + " , " + std::to_string(order.getCost()) + " , " + custIt->getName()
                                    +" , " + custIt->getEmail() + " , " + custIt->getPhone());
        }
    }
    file.close();
}

/**
 * \brief Lists the employees in the company.
 *
 * This method lists the employees in the given Company object to the standard output.
 *
 * \param company The Company object containing the employees to list.
 */void listEmployees(const Company& company) {
    std::cout << "\n----- Employee List -----" << std::endl;
    std::vector<Employee>::const_iterator empIt;
    int counter = 1;
    for (empIt = company.employeeBegin(); empIt != company.employeeEnd(); ++empIt) {
        std::cout << counter << ". Name: " << empIt->getName() << ", Email: " << empIt->getEmail() << ", Phone: " << empIt->getPhone() << std::endl;
        counter++;
    }
    std::cout << "-------------------------" << std::endl;
}

/**
 * \brief Adds an employee to the company.
 *
 * This method prompts the user to enter the details of a new employee, including
 * their name, email, phone, and salary, and adds the employee to the given Company object.
 *
 * \param company The Company object to add the employee to.
 */
void addEmployee(Company& company) {
    std::string name, email, phone;

    std::cout << "\nEnter the employee details:" << std::endl;
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Phone: ";
    std::getline(std::cin, phone);
    double salary = 0.0;
    while (true) {
        std::cout << "Salary: ";
        if (std::cin >> salary) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a numeric value for Salary." << std::endl;
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Employee employee(name, email, phone, salary);
    company.addEmployee(employee);
    std::cout << "Employee added successfully!" << std::endl;
    listEmployees(company);
}

/**
 * \brief Adds a customer to the company.
 * \param company The Company object to add the customer to.
 */
void addCustomer(Company& company) {
    std::string name, email, phone;
    std::cout << "\nEnter the customer details:" << std::endl;
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Phone: ";
    std::getline(std::cin, phone);

    Customer customer(name, email, phone);
    company.addCustomer(customer);
    std::cout << "Customer added successfully!" << std::endl;
}

/**
 * \brief Allows the user to enter a sale for a customer.
 * \param company The Company object to enter the sale for.
 */
void enterSale(Company& company) {
    if (company.customerBegin() == company.customerEnd()) {
        std::cout << "\nThere are no customers. Please add a customer first." << std::endl;
        return;
    }
    std::cout << "\n----- Enter Sale -----" << std::endl;
    std::cout << "Customers:" << std::endl;
    int counter = 1;
    for (auto custIt = company.customerBegin(); custIt != company.customerEnd(); ++custIt) {
        std::cout << counter << ". Name: " << custIt->getName() << std::endl;
        counter++;
    }
    std::cout << "-----------------------" << std::endl;

    std::cout << "Select a customer (Enter iterator value): ";
    int selection;
    std::cin >> selection;

    if (selection <= 0 || selection > company.customerEnd() - company.customerBegin()) {
        std::cout << "Invalid customer selection." << std::endl;
        return;
    }

    std::vector<Customer>::const_iterator selectedCustomer = company.customerBegin() + (selection - 1);
    std::string itemName;
    int quantity;
    double cost;

    std::cout << "Enter item name: ";
    std::cin.ignore();
    std::getline(std::cin, itemName);
    while (true) {
        std::cout << "Enter quantity: ";
        if (std::cin >> quantity) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a numeric value for Quantity." << std::endl;
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
        }
    }
    while (true) {
        std::cout << "Enter cost: ";
        if (std::cin >> cost) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a numeric value for Cost." << std::endl;
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
        }
    }
    Purchase purchase(itemName, quantity, cost);

    Customer customer(selectedCustomer->getName(), selectedCustomer->getEmail(), selectedCustomer->getPhone(),selectedCustomer->getOrderHistory());
    customer.addPurchase(purchase);
    Customer oldCustomr = company.getCustomer(customer);
    company.replaceCustomer(oldCustomr, customer);
    std::cout << "Sale entered successfully!" << std::endl;
}

/**
 * \brief Displays the list of customers and their details.
 * \param company The Company object to view the customers from.
 */
void viewCustomers(Company& company) {
    if (company.customerBegin() == company.customerEnd()) {
        std::cout << "\nThere are no customers to display." << std::endl;
        return;
    }

    std::cout << "\n----- Customer List -----" << std::endl;
    std::vector<Customer>::const_iterator custIt;
    int counter = 1;
    for (custIt = company.customerBegin(); custIt != company.customerEnd(); ++custIt) {
        std::cout << counter << ". Name: " << custIt->getName() << std::endl;

        counter++;
    }
    std::cout << "--------------------------" << std::endl;

    std::cout << "Select a customer (Enter iterator value): ";
    int selection;
    std::cin >> selection;

    if (selection <= 0 || selection > company.customerEnd() - company.customerBegin()) {
        std::cout << "Invalid customer selection." << std::endl;
        return;
    }

    std::vector<Customer>::const_iterator selectedCustomer = company.customerBegin() + (selection - 1);

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "                        RECEIPT                       " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Customer Name: " << selectedCustomer->getName() << std::endl;
    std::cout << "Email: " << selectedCustomer->getEmail() << std::endl;
    std::cout << "Phone Number: " << selectedCustomer->getPhone() << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    double total = 0.0;
    std::vector<Purchase> orders = selectedCustomer->getOrderHistory();
    if (orders.empty()) {
        std::cout << "No order history available." << std::endl;
    } else {
        std::cout << std::left << std::setw(30) << "Item";
        std::cout << std::left << std::setw(10) << "Quantity";
        std::cout << std::left << std::setw(10) << "Cost";
        std::cout << std::left << std::setw(10) << "Total" << std::endl;
        for (const auto& order : orders) {
            std::cout << std::left << std::setw(30) << order.getItem();
            std::cout << std::left << std::setw(10) << order.getQty();
            std::cout << std::fixed << std::setprecision(2)  << std::setw(10)<< order.getCost();
            std::cout << std::fixed << std::setprecision(2) << std::right << (order.getQty() * order.getCost()) << std::endl;
            total += order.getCost() * order.getQty();
        }
    }
    std::cout << "---------------------------------------------------------" << std::endl;

    // Print total
    std::cout << std::setw(50) << "Total: $" << std::fixed << std::setprecision(2) << std::right << total << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}

/**
 * \brief Parses company data from a file and returns a Company object.
 * \param filename The name of the file to parse the company data from.
 * \return The parsed Company object.
 */
Company parseCompanyData(const std::string& filename) {
    std::ifstream file(filename+".dat");
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return Company(filename);;
    }
    Company data = Company(filename);
    // Read the number of employees
    int numEmployees;
    file >> numEmployees;
    file.ignore();  // Ignore the newline character

    // Read employee records
    for (int i = 0; i < numEmployees; ++i) {
        std::string name, email, phone;
        double salary;

        std::getline(file, name);
        std::getline(file, email);
        std::getline(file, phone);
        file >> salary;
        file.ignore();  // Ignore the newline character

        // Create and add an Employee object
        Employee employee(name, email, phone, salary);
        data.addEmployee(employee);
    }

    // Read the number of customers
    int numCustomers;
    file >> numCustomers;
    file.ignore();  // Ignore the newline character

    // Read customer records
    for (int i = 0; i < numCustomers; ++i) {
        std::string name, email, phone;
        int numPurchases;
        std::vector<Purchase> purchases;

        std::getline(file, name);
        std::getline(file, email);
        std::getline(file, phone);
        file >> numPurchases;
        file.ignore();  // Ignore the newline character

        // Read purchase records
        for (int j = 0; j < numPurchases; ++j) {
            std::string item;
            int quantity;
            double cost;

            std::getline(file, item);
            file >> quantity >> cost;
            file.ignore();  // Ignore the newline character

            // Create and add a Purchase object
            Purchase purchase(item, quantity, cost);
            purchases.push_back(purchase);
        }

        // Create and add a Customer object
        Customer customer(name, email, phone, purchases);
        data.addCustomer(customer);
    }

    file.close();
    return data;
}

/**
 * \brief The main entry point of the program.
 * \return The exit status of the program.
 */
int main() {
    std::string companyName;
    std::cout << "Enter the company name: ";
    std::getline(std::cin, companyName);

    Company company(companyName);
    std::string filename = companyName + ".dat";
    std::ifstream file(companyName + ".dat");
    std::ifstream inFile(companyName + ".dat");
    if(file) {
        company = parseCompanyData(companyName);
        file.close();
    }

    char choice;
    while (true) {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case '1': {
                listEmployees(company);
                char empChoice;
                while (true) {
                    displayEmployeeMenu();
                    std::cin >> empChoice;
                    std::cin.ignore();
                    if (empChoice == 'A' || empChoice == 'a') {
                        addEmployee(company);
                    } else if (empChoice == 'M' || empChoice == 'm') {
                        break;
                    } else {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                    }
                }
                break;
            }
            case '2': {
                char salesChoice;
                while (true) {
                    displaySalesMenu();
                    std::cin >> salesChoice;
                    std::cin.ignore();

                    if (salesChoice == 'A' || salesChoice == 'a') {
                        addCustomer(company);
                    } else if (salesChoice == 'S' || salesChoice == 's') {
                        enterSale(company);
                    } else if (salesChoice == 'V' || salesChoice == 'v') {
                        viewCustomers(company);
                    } else if (salesChoice == 'M' || salesChoice == 'm') {
                        break;
                    } else {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                    }
                }
                break;
            }
            case '3': {
                saveCompanyToFile(filename, company);
                std::cout << "\nCompany data saved to " << filename << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}

