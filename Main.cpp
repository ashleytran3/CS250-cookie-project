#include "Interface.h"
#include "Testing.h"

#include <iostream>

using namespace std;

int main() 
{
    CookieList cookieList1;
    createCookieList(cookieList1);
    displayMenu();
    processChoice(cookieList1);

    cout << endl;

    return 0;
}
