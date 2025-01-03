#include "Interface.h"
#include "Testing.h"

#include <iostream>

using namespace std;

int main() 
{
    //Part C
    CookieList cookieList1;
    createCookieList(cookieList1);
    displayMenu();
    processChoice(cookieList1);

    cout << endl;

    return 0;
}
