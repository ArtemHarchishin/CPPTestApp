#include <iostream>
#include <set>
#include <map>

void link();

void pointer();

void bitwiseOp();

bool isActive(bool retVal);

void stdSetOp();

int main() {
//    pointer();
//    link();
//    bitwiseOp();
    stdSetOp();
    return 0;
}

void stdSetOp() {
    std::map<std::string, std::set<std::string>> preferences;
    std::string prefId = "foo";
    std::string value = "bar";

    std::cout << preferences[prefId].count(value) << std::endl;
    preferences[prefId].emplace(value);
    std::cout << preferences[prefId].count(value) << std::endl;
}

void bitwiseOp() {
    bool cCanBuy = false;
    std::cout << "1 - cCanBuy = " << cCanBuy << ", isActive return false" << std::endl;
    cCanBuy &= isActive(false);
    std::cout << "cCanBuy = " << cCanBuy << std::endl;

    cCanBuy = true;
    std::cout << "2 - cCanBuy = " << cCanBuy << ", isActive return true" << std::endl;
    cCanBuy &= isActive(true);
    std::cout << "cCanBuy = " << cCanBuy << std::endl;

    cCanBuy = false;
    std::cout << "3 - cCanBuy = " << cCanBuy << ", isActive return true" << std::endl;
    cCanBuy &= isActive(true);
    std::cout << "cCanBuy = " << cCanBuy << std::endl;

    cCanBuy = true;
    std::cout << "4 - cCanBuy = " << cCanBuy << ", isActive return false" << std::endl;
    cCanBuy &= isActive(false);
    std::cout << "cCanBuy = " << cCanBuy << std::endl;

    bool gCanBuy = false;
    bool sCanBuy = false;
    std::cout << "1 - sCanBuy = " << sCanBuy << ", gCanBuy = " << gCanBuy << std::endl;
    gCanBuy |= sCanBuy;
    std::cout << "gCanBuy = " << gCanBuy << std::endl;

    gCanBuy = true;
    sCanBuy = false;
    std::cout << "2 - sCanBuy = " << sCanBuy << ", gCanBuy = " << gCanBuy << std::endl;
    gCanBuy |= sCanBuy;
    std::cout << "gCanBuy = " << gCanBuy << std::endl;

    gCanBuy = true;
    sCanBuy = true;
    std::cout << "3 - sCanBuy = " << sCanBuy << ", gCanBuy = " << gCanBuy << std::endl;
    gCanBuy |= sCanBuy;
    std::cout << "gCanBuy = " << gCanBuy << std::endl;

    gCanBuy = false;
    sCanBuy = true;
    std::cout << "4 - sCanBuy = " << sCanBuy << ", gCanBuy = " << gCanBuy << std::endl;
    gCanBuy |= sCanBuy;
    std::cout << "gCanBuy = " << gCanBuy << std::endl;
}

bool isActive(bool retVal) {
    std::cout << "isActive()" << std::endl;
    return retVal;
}

bool f(char &a, char *b) {
    a += 1;
    *b += 1;
    std::cout << "f, a = " << a << std::endl;
    std::cout << "f, b = " << b << std::endl;
    return false;
}

void pointer() {
    char x = '1';
    char *pInt = &x;
    char z = *pInt;
    f(*pInt, &x);
    std::cout << "pointer, x = " << x << std::endl;
}

void link() {
    char x = '2';
    char &lInt = x;
    char z = lInt;
    f(lInt, &x);
    std::cout << "link, x = " << x << std::endl;
}
