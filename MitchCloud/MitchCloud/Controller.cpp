#include "Controller.hpp"

void Controller::login()
{
    std::string username, password;
    ui.welcome();
    username = ui.getUsername();
    password = ui.getPassword();
    bool validLogin = auth.verifyUser(username, password);
    if (validLogin)
    {
        store.setUserUsername(username);
        store.setUserPassword(password);
        if (username == "ICE" && password == "CREAM")
        {
            store.setUserRights(User::customer);
        }
        //ADD THE OTHER PERMISSIONS FOR THE OTHER USER TYPES
    }
    ui.loginStatus(validLogin);
    std::cout << std::endl;
}

void Controller::userOptions()
{
    int choice = ui.showUserOptions(store.getUser().getRights());
    switch (choice)
    {
    case 1:
        startTrans();
        break;
    }
}

void Controller::startTrans()
{
    bool done = false;
    int yes = 1, no = 2;
    while (!done)
    {
        ui.printMenu(store.getMenu());
        Item menuSelection = ui.getItemSelection(store.getMenu());
        ui.askForQty();
        int qtySelection = ui.getSelection();
        menuSelection.calculatePrice();
        for (int i = 0; i < qtySelection; ++i)
        {
            store.addToUserCart(menuSelection);
        }
        ui.askContShopping();
        int contShopping = ui.getSelection();
        if (contShopping == no)
        {
            done = true;
        }
    }
    endTrans();
}

void Controller::endTrans()
{
    bool checkingOut = false;
    while (!checkingOut)
    {
        ui.displayCheckout(store.getUser().getCart());
        Item cartItem;
        int checkoutOption = ui.getSelection();
        switch (checkoutOption)
        {
        case 1:
            ui.askRemoveItem();
            cartItem = ui.getItemSelection(store.getUser().getCart());
            store.removeUserItem(cartItem);
            break;
        case 2:
            checkingOut = true;
            break;
        case 3:
            exit(0);
            break;
        }
    }
    getPayment();
}

void Controller::getPayment()
{
    bool validPayment = false;
    std::string cNumber, cExpDate;
    ui.askPaymentType();
    int paymentChoice = ui.getSelection();
    switch (paymentChoice)
    {
    case 1:
        cNumber = ui.getCreditNumber();
        cExpDate = ui.getCreditExpDate();
        validPayment = auth.verifyCredit(cNumber, cExpDate);
        if (validPayment)
        {
            ui.creditStatus(validPayment);
        }
        break;
    }
}