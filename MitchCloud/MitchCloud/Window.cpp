#include "Window.hpp"

void Window::welcome()
{
    std::cout << "Welcome to Mitchell's Ice Cream!\n\n";
    std::cout << "--------------------\n";
    std::cout << "LOGIN:\n";
    std::cout << "--------------------\n";
}

std::string Window::getUsername() const
{
    std::string name;
    std::cout << "USERNAME: ";
    std::cin >> name;
    return name;
}

std::string Window::getPassword() const
{
    std::string password;
    std::cout << "PASSWORD: ";
    std::cin >> password;
    return password;
}

void Window::loginStatus(const bool& status)
{
    std::cout << std::endl;
    if (status)
    {
        std::cout << "Login successful.";
    }
    else {
        std::cout << "Invalid username or password.";
    }
    std::cout << std::endl;
}

int Window::showUserOptions(const User::Permission& rights)
{
    int choice;
    switch (rights)
    {
    case User::customer:
        std::cout
            << "--------------------\n"
            << "OPTIONS:\n"
            << "--------------------\n"
            << "1. View Menu\n"
            << "2. Manage Profile\n"
            << "3. Logout\n\n"
            << "SELECTION: ";
        choice = getSelection();
        std::cout << std::endl;
        break;
    }
    return choice;
}

void Window::printMenu(const Menu& menu) {
    std::vector<Item> iceCreamList = menu.filteredList(Item::iceCream);
    std::vector<Item> cakeList = menu.filteredList(Item::cake);
    std::vector<Item> pieList = menu.filteredList(Item::pie);
    std::vector<Item> specList = menu.filteredList(Item::speciality);
    std::cout << "MENU:\n\n";
    std::cout << "---------------------\n";
    std::cout << "FLAVORS\n";
    std::cout << "---------------------\n\n";
    printItemList(iceCreamList);
    std::cout << "---------------------\n";
    std::cout << "PIES\n";
    std::cout << "---------------------\n\n";
    printItemList(pieList);
    std::cout << "---------------------\n";
    std::cout << "CAKES\n";
    std::cout << "---------------------\n\n";
    printItemList(cakeList);
    std::cout << "---------------------\n";
    std::cout << "SPECIALTIES\n";
    std::cout << "---------------------\n\n";
    printItemList(specList);
    std::cout << "SELECTION: ";
}

void Window::printItemList(const std::vector<Item>& items)
{
    for (auto it : items)
    {
        std::cout << it;
    }
}

int Window::getSelection() const
{
    int choice;
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

Item Window::getItemSelection(const Menu& menu)
{
    Item selection;
    int idChoice;
    std::cin >> idChoice;
    std::cout << std::endl;
    for (auto it : menu.getMenu())
    {
        if (it.getID() == idChoice)
        {
            selection = it;
            return selection;
        }
    }
    return selection;
}

Item Window::getItemSelection(const Cart& cart)
{
    Item selection;
    int idChoice;
    std::cin >> idChoice;
    std::cout << std::endl;
    for (auto it : cart.getCart())
    {
        if (it.getID() == idChoice)
        {
            selection = it;
            return selection;
        }
    }
    return selection;
}

void Window::askForQty()
{
    std::cout << "SELECT QUANTITY: ";
}

void Window::askAddToCart()
{
    std::cout
        << "Add to cart?\n"
        << "1. Yes\n"
        << "2. No\n\n"
        << "SELECTION: ";
}

void Window::askContShopping()
{
    std::cout
        << "Continue shopping?\n"
        << "1. Yes\n"
        << "2. No\n\n"
        << "Selection: ";
}

void Window::displayCheckout(const Cart& cart)
{
    std::cout << "---------------------\n";
    std::cout << "CHECKOUT\n";
    std::cout << "---------------------\n\n";
    displayCart(cart);
    displayCheckoutOptions();
}

void Window::displayCart(const Cart& cart)
{
    std::cout << "YOUR CART:\n\n";
    std::cout << "---------------------\n\n";
    printItemList(cart.getCart());
    std::cout << "---------------------\n\n";
    std::cout << std::setprecision(3);
    std::cout
        << "Subtotal:\t$" << cart.getSubTotal() << '\n'
        << "Grandtotal:\t$" << cart.getGrandTotal() << '\n'
        << std::endl;

    std::cout << "---------------------\n\n";
}

void Window::displayCheckoutOptions()
{
    std::cout
        << "1. Remove Item\n"
        << "2. Check Out\n"
        << "3. Logout\n\n"
        << "SELECTION: ";
}

void Window::askRemoveItem()
{
    std::cout << "Enter the ID of the item to remove: ";
}

void Window::askPaymentType()
{
    std::cout
        << "Please select payment method:\n"
        << "1. Credit/Debt\n"
        << "2. Paypal\n"
        << "3. Cash in store\n"
        << "4. Cancel\n\n"
        << "SELECTION: ";
}

std::string Window::getCreditNumber() const
{
    std::string cNumber;
    std::cout << "Enter card number [EX: 4417-1130-2245-5119]: ";
    std::cin >> cNumber;
    return cNumber;
}

std::string Window::getCreditExpDate() const
{
    std::string expDate;
    std::cout << "Enter expiration date [EX: 01/20]: ";
    std::cin >> expDate;
    std::cout << std::endl;
    return expDate;
}

void Window::creditStatus(const bool& status)
{
    if (status)
    {
        std::cout
            << "Payment accepted.\n"
            << "Thank you for using Mitchell's Ice Cream!";
    }
    else {
        std::cout << "Payment denied.";
    }
    std::cout << std::endl;
}

void getPaypalInfo()
{

}