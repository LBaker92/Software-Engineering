#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "Cart.hpp"

class User
{
public:
    enum Permission
    {
        uninitialized = -1,
        customer,
        clerk,
        localManager,
        cloudManager,
        saleAnalyst,
    };

    User() : uID(-1), uUsername(""), uPass(""), uRights(uninitialized) {}

    //Accessors
    int getID() const { return uID; }
    std::string getName() const { return uUsername; }
    std::string getPass() const { return uPass; }
    Permission getRights() const { return uRights; }
    Cart getCart() const { return uCart; }

    //Mutators
    void setID(int ID) { uID = ID; }
    void setUsername(std::string name) { uUsername = name; }
    void setPass(std::string pass) { uPass = pass; }
    void setRights(Permission rights) { uRights = rights; }

    //Functions
    void addToCart(Item& item) { uCart.addToCart(item); }
    void removeFromCart(Item& item) { uCart.removeFromCart(item); }
private:
    int uID;
    std::string uUsername, uPass;
    Permission uRights;
    Cart uCart;
};

#endif