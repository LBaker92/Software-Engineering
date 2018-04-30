#include "Authenticate.hpp"

bool Authenticate::verifyUser(const std::string& name, const std::string& pass)
{
    return (name == "ICE" && pass == "CREAM");
}

bool Authenticate::verifyCredit(const std::string& cardNumber, const std::string& expDate)
{
    return (cardNumber == "4417-1130-2245-5119" && expDate == "01/20");
}