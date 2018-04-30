#include "Cart.hpp"

void Cart::removeFromCart(Item & item)
{
    int i = 0;
    for (auto it : cItems)
    {
        if (it.getID() == item.getID())
        {
            cItems.erase(cItems.begin() + i);
            calculateTotals();
            return;
        }
        i++;
    }
}

void Cart::addToCart(Item& product)
{
    cItems.push_back(product);
    calculateTotals();
}

void Cart::calculateTotals()
{
    for (auto it : cItems)
    {
        subTotal += it.getPrice();
    }
    grandTotal = subTotal + subTotal * tax;
}