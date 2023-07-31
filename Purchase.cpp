#include "Purchase.h"

Purchase::Purchase(std::string _item, int _qty, double _cost)
        : item(_item), _qty(_qty), _cost(_cost) {
    // Constructor with parameters
}

std::string Purchase::getItem() const {
    return item;
}

int Purchase::getQty() const {
    return _qty;
}

double Purchase::getCost() const {
    return _cost;
}

double Purchase::total() const {
    return _qty * _cost;
}
