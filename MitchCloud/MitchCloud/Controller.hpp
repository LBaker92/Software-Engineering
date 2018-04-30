#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Entities.hpp"
#include "Window.hpp"
#include "Authenticate.hpp"

class Controller
{
public:
    /*
    Obtains the user's credentials and passes them to the authenticator for verification.
    */
    void login();

    /*
    Displays a list of options for the user to choose from after logging in.
    The list of options to choose from will change based on the user's permissions.
    EG: A user with admin permissions will have options to change other user's profile, etc, whereas a customer will not.
    */
    void userOptions();

    /*
    Shows the menu to the user, allowing the user to add/remove items, along with their quantities, from their cart until they signify that they are done shopping.
    */
    void startTrans();

    /*
    Displays the user's cart information followed by a list of options for the user.
    The user can either: make changes to his cart, finalize their order, or logout.
    */
    void endTrans();

    /*
    Obtains the payment information from the user and verifies it with the authenticator.
    */
    void getPayment();
private:
    Entities store;
    Window ui;
    Authenticate auth;
};

#endif