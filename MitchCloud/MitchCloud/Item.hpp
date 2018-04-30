#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

class Item
{
public:
    //Type refers to what kind of product the item is.
    enum Type
    {
        uninit = -1,
        iceCream,
        cake,
        pie,
        speciality
    };

    //CONSTRUCTORS
    Item() : iID(-1), iWeight(0.0), iPrice(0.0), iName(""), iDesc(""), iType(uninit) {}
    Item(int ID, double WEIGHT, std::string NAME, std::string DESC, Type TYPE);

    //GETTERS
    int getID() const { return iID; }
    double getWeight() const { return iWeight; }
    double getPrice() const { return iPrice; }
    std::string getName() const { return iName; }
    std::string getDesc() const { return iDesc; }
    Type getType() const { return iType; }

    //SETTERS
    void setID(int ID) { iID = ID; }
    void setWeight(double weight) { iWeight = weight; }
    void setName(std::string name) { iName = name; }
    void setDesc(std::string desc) { iDesc = desc; }
    void setType(Type type) { iType = type; }

    //OVERLOADED OPERATORS

    /*
    Allows for the output of an item using cout.
    */
    friend std::ostream& operator<< (std::ostream& outStream, Item& item);

    /*
    Assigns an item the variables of another item.
    EX: item1 = item2;
    */
    Item& operator= (const Item& item);

    //Sets the price of the item based on its Type.
    void calculatePrice();
private:
    int iID;
    double iWeight, iPrice;
    std::string iName, iDesc;
    Type iType;
};

#endif