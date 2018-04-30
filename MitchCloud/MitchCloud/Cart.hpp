#ifndef CART_HPP
#define CART_HPP

#include <vector>
#include "Item.hpp"

//Taxrate for Ohio as of 2017.
constexpr double tax = .0725;

class Cart
{
public:
    Cart() : cID(1), subTotal(0), grandTotal(0) {}

    //GETTERS
    int getCartID() const { return cID; }
    double getSubTotal() const { return subTotal; }
    double getGrandTotal() const { return grandTotal; }
    std::vector<Item> getCart() const { return cItems; }

    //SETTERS
    void setCartID(int ID) { cID = ID; }
    void setSubTotal(double sTotal) { subTotal = sTotal; }
    void setGrandTotal(double gTotal) { grandTotal = gTotal; }

    void addToCart(Item& product);
    void removeFromCart(Item& item);

    /*
    Iterates through the cItems, adding the price of each item before tax is applied.
    After getting the subTotal, tax is applied to get the grandTotal.
    */
    void calculateTotals();
private:
    //Id of the given cart.
    int cID;
    double subTotal, grandTotal;
    std::vector<Item> cItems;
};

#endif