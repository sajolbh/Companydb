#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>

class Purchase {
private:
    std::string item;
    int _qty;
    double _cost;

public:
    Purchase(std::string _item, int _qty, double _cost);

    std::string getItem() const;
    int getQty() const;
    double getCost() const;
    double total() const;
};

#endif  // PURCHASE_H
