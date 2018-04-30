#include "Item.hpp"

Item::Item(int ID, double WEIGHT, std::string NAME, std::string DESC, Type TYPE)
{
    iID = ID;
    iWeight = WEIGHT;
    iName = NAME;
    iDesc = DESC;
    iType = TYPE;
}

std::ostream & operator<<(std::ostream& os, Item& item)
{
    std::cout << item.iID << ". " << item.iName << '\n';
    if (item.iID > 0 && item.iID < 10)
    {
        std::cout << "     - ";
    }
    else if (item.iID > 9 && item.iID < 100)
    {
        std::cout << "     - ";

    }
    std::cout << item.iDesc << '\n' << std::endl;
    return os;
}

void Item::calculatePrice()
{

    if (iType == pie)
    {
        iPrice = 26.95;
    }
    else if (iType == cake)
    {
        iPrice = 29.95;
    }
    else if (iType == iceCream)
    {
        iPrice = iWeight;
    }
    else if (iType == speciality)
    {
        iPrice = 5.95;
    }
}

Item& Item::operator=(const Item& newItem)
{
    iID = newItem.iID;
    iWeight = newItem.iWeight;
    iName = newItem.iName;
    iDesc = newItem.iDesc;
    iType = newItem.iType;
    return *this;
}