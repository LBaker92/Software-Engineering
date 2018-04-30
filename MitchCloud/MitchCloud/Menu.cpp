#include "Menu.hpp"

Menu::Menu()
{
    //FORMAT: ID, WEIGHT, NAME, DESC, TYPE

    //FLAVORS
    productList.push_back(Item(1, 1.0, "Vanilla", "Made with Madagascar...", Item::iceCream));
    productList.push_back(Item(2, 1.0, "Chocolate", "Made with organic...", Item::iceCream));
    productList.push_back(Item(3, 1.0, "Butter Pecan", "Butterscotch-pecan...", Item::iceCream));
    productList.push_back(Item(4, 1.0, "Mango Sorbet", "Made from intensely...", Item::iceCream));
    productList.push_back(Item(5, 1.0, "Raspberry Sorbet", "Made from select...", Item::iceCream));
    productList.push_back(Item(6, 1.0, "Cinnamon", "Vietnamese cinnamon warmed...", Item::iceCream));
    productList.push_back(Item(7, 1.0, "Wildberry Crumble", "Vanilla Bean ice cream...", Item::iceCream));

    //PIES
    productList.push_back(Item(8, 0.0, "Turtle", "Chocolate graham crust, iced with...", Item::pie));
    productList.push_back(Item(9, 0.0, "Fresh Mint Chocolate Chunk", "Chocolate graham crust...", Item::pie));
    productList.push_back(Item(10, 0.0, "Cookies and Cream", "Chocolate graham crust...", Item::pie));
    productList.push_back(Item(11, 0.0, "Chocolate Peanut Butter Cup", "Chocolate graham crust...", Item::pie));

    //CAKES
    productList.push_back(Item(12, 0.0, "Vanilla Bean", "Chocolate cake topped with a...", Item::cake));
    productList.push_back(Item(13, 0.0, "Black Raspberry Chocolate Chunk", "Chocolate cake...", Item::cake));
    productList.push_back(Item(14, 0.0, "Fresh Mint Chocolate Chunk", "Chocolate cake...", Item::cake));
    productList.push_back(Item(15, 0.0, "Cookies and Cream", "Chocolate cake topped with...", Item::cake));
    productList.push_back(Item(16, 0.0, "Chocolate Peanut Butter Cup", "Chocolate cake topped...", Item::cake));

    //SPECIALTIES
    productList.push_back(Item(17, 0.0, "TURTLE SUNDAE", "Vanilla Bean ice cream, hot fudge...", Item::speciality));
    productList.push_back(Item(18, 0.0, "PEANUT BUTTER FUDGE", "Your choice of ice cream, peanut...", Item::speciality));
}

std::vector<Item> Menu::filteredList(std::string& search)
{
    std::vector<Item> filterMenu;
    for (auto it : productList)
    {
        if (it.getName() == search)
            filterMenu.push_back(it);
    }
    return filterMenu;
}
std::vector<Item> Menu::filteredList(Item::Type type) const
{
    std::vector<Item> filterMenu;
    for (auto it : productList)
    {
        if (it.getType() == type)
            filterMenu.push_back(it);
    }
    return filterMenu;
}