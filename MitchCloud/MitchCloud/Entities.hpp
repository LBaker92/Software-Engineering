#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "User.hpp"
#include "Menu.hpp"

class Entities
{
public:
    //GETTERS
    User getUser() const { return eUser; }
    Menu getMenu() const { return eMenu; }

    //SETTERS
    void setUserUsername(std::string& un) { eUser.setUsername(un); }
    void setUserPassword(std::string& pw) { eUser.setPass(pw); }
    void setUserRights(User::Permission rights) { eUser.setRights(rights); }

    void addToUserCart(Item& item) { eUser.addToCart(item); }
    void removeUserItem(Item& item) { eUser.removeFromCart(item); }
private:
    User eUser;
    Menu eMenu;
};

#endif