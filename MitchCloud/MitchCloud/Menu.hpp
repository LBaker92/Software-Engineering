#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include "Item.hpp"

class Menu
{
public:
    //CONSTRUCTOR
    Menu();
    
    //GETTERS
    std::vector<Item> getMenu() const { return productList; }

    //Returns a vector of items where the item name matches the string a user searched for.
    std::vector<Item> filteredList(std::string& searchString);

    //Returns a vector of items based on the item's Type.
    std::vector<Item> filteredList(Item::Type itemType) const;
private:
    std::vector<Item> productList;
};

#endif