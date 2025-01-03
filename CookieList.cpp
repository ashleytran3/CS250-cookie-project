#include "CookieList.h"

#include <iostream>
using namespace std;

void CookieList::addCookie(const Cookie &newCookie)
{
    if (count == 0)
    {
        last = new Node(newCookie, nullptr);
        first = last;
    }
    else
    {
        last->setNext(new Node(newCookie, nullptr));
        last = last->getNext();
    }

    ++count;
}

void CookieList::addCookie(const std::string &newName,
                           size_t newCalories, size_t newServings,
                           const std::set<std::string> newIngredients)
{
    addCookie(Cookie(newName, newCalories,
                     newServings, newIngredients));
}

size_t CookieList::getCount() const
{
    return count;
}

bool CookieList::isEmpty() const
{
    return (count == 0);
}

bool CookieList::searchCookie(const std::string &cookieName) const
{
    Node *current = first;

    while (current != nullptr)
    {
        if (current->getCookie().getName() == cookieName)
        {
            return true;
        }
        current = current->getNext();
    }

    return false;
}

void CookieList::printAllCookies() const
{
    Node *current = first;

    while (current != nullptr)
    {
        cout << "    " << current->getCookie().getName() << endl;
        current = current->getNext();
    }
}

void CookieList::printCookiesSelection() const
{
    Node *current = first;
    int num = 1;

    while (current != nullptr)
    {
        cout << "    " << num << ": "
             << current->getCookie().getName() << endl;
        current = current->getNext();
        ++num;
    }
}

void CookieList::printRecipe(size_t cookieSelection) const
{
    cout << "    ";
    getCookieLocation(cookieSelection)->getCookie().printRecipe();
    cout << endl;
}

void CookieList::printCalories(size_t cookieSelection) const
{
    getCookieLocation(cookieSelection)->getCookie().printCalories();
}

void CookieList::printLimitedCalories(size_t maxNumOfCalories) const
{
    Node *curr = first;
    while (curr != nullptr)
    {
        if (curr->getCookie().getCalories() <= maxNumOfCalories)
        {
            cout << "    ";
            curr->getCookie().printCalories();
        }
        curr = curr->getNext();
    }
}

bool CookieList::checkSufficientServings(size_t cookieSelection, size_t partySize) const
{
    return (getCookieLocation(cookieSelection)->getCookie().getServings() > partySize);
}

void CookieList::clearList()
{
    Node *temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;
    count = 0;
}

CookieList::~CookieList()
{
    if (count != 0)
    {
        clearList();
    }
}

CookieList::CookieList(const CookieList &otherCookieList)
{
    first = nullptr;
    last = nullptr;
    Node *current = otherCookieList.first;

    while (current != nullptr)
    {
        addCookie(current->getCookie());
        current = current->getNext();
    }

    count = otherCookieList.count;
}

CookieList &CookieList::operator=(const CookieList &otherCookieList)
{
    if (&otherCookieList == this)
    {
        cerr << "Attempted assignment to itself.";
    }
    else
    {
        if (count != 0)
        {
            clearList();
        }

        Node *temp = otherCookieList.first;

        while (temp != nullptr)
        {
            addCookie(temp->getCookie());
            temp = temp->getNext();
        }

        count = otherCookieList.count;
    }

    return *this;
}

Node *CookieList::getCookieLocation(size_t cookieSelection) const
{
    Node *curr = first;

    for (size_t i = 0; i < cookieSelection - 1; ++i)
    {
        curr = curr->getNext();
    }

    return curr;
}
