#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Purchase.h"
#include "Employee.h"

class Customer  {
private:
    std::string _name; //Private string to store name
    std::string _email;//Private string to store email
    std::string _phone;//Private string to store phone
    std::vector<Purchase> _history;// Private vector to store purchase history

public:
    using const_iterator = std::vector<Purchase>::const_iterator;//using iterator on the vector purchase

    Customer();
    Customer(std::string name, std::string email, std::string phone);
    Customer(std::string name, std::string email, std::string phone,std::vector<Purchase> history);

    void addPurchase(const Purchase& purchase);

    const_iterator purchaseBegin() const;
    const_iterator purchaseEnd() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;
    void setName(std::string _name);
    void setEmail(std::string _email);
    void setPhone(std::string _phone);

    std::vector<Purchase> getOrderHistory() const;
};

#endif  // CUSTOMER_H
