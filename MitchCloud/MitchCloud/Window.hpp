#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "User.hpp"
#include "Menu.hpp"
#include "Item.hpp"
#include "Cart.hpp"

class Window
{
public:

    //Accessors
    std::string getUsername() const;
    std::string getPassword() const;

    //functions
    void welcome();
    void loginStatus(const bool&);
    void creditStatus(const bool&);

    int showUserOptions(const User::Permission& permission);
    int getSelection() const;
    Item getItemSelection(const Menu&);
    Item getItemSelection(const Cart&);
    std::string getCreditNumber() const;
    std::string getCreditExpDate() const;

    void printMenu(const Menu& menu);
    void printItemList(const std::vector<Item>& productList);

    void askForQty();
    void askAddToCart();
    void askContShopping();
    void askRemoveItem();
    void askPaymentType();

    void displayCheckout(const Cart& userCart);
    void displayCart(const Cart& userCart);
    void displayCheckoutOptions();
private:
};

#endif