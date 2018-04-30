#ifndef AUTHENTICATE_HPP
#define AUTHENTICATE_HPP

#include <string>

class Authenticate
{
public:
    bool verifyUser(const std::string& userName, const std::string& userPassword);
    bool verifyCredit(const std::string& cardNumber, const std::string& expirationDate);
private:

};

#endif