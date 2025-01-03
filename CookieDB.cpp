#include "CookieDB.h"

#include <iostream>
using namespace std;

void getData(std::string &newName, size_t &newCalories,
             size_t &newServings, std::set<std::string> &newIngredients,
             size_t idx)
{
    vector<string> names = {
        "Lemon Square Bars",
        "Biscotti",
        "Nutella Brownies",
        "Butter Snow Flakes",
        "Chocolate Chip Cookies",
        "Oatmeal Cookies",
        "Walnut Tassies",
        "Jam Thumbprints",
        "Gingersnaps",
        "Meringues",
        "Pizzelles",
        "Snickerdoodles",
    };

    vector<size_t> calories = {
        136,
        104,
        204,
        105,
        183,
        128,
        159,
        126,
        121,
        62,
        102,
        120,
    };

    vector<size_t> servings = {
        32,
        36,
        16,
        36,
        16,
        36,
        36,
        24,
        30,
        36,
        24,
        36,
    };

    vector<set<string>> ingredients = {
        // Lemon Square Bars
        {"flour", "sugar", "butter", "eggs", "lemon juice"},
        // Biscotti
        {"flour", "butter", "sugar", "eggs", "almonds"},
        // Nutella Brownies
        {"butter", "Nutella", "flour", "sugar", "vanilla", "chocolate chips"},
        // Butter Snow Flakes
        {"cinnamon", "butter", "flour", "cream cheese", "sugar", "eggs", "vanilla"},
        // Chocolate Chip Cookies
        {"butter", "sugar", "eggs", "applesauce", "vanilla", "flour", "cinnamon"},
        // Oatmeal Cookies
        {"butter", "sugar", "eggs", "vanilla", "flour", "oats chips"},
        // Walnut Tassies
        {"sugar", "walnuts", "butter", "eggs", "vanilla", "cream cheese", "flour"},
        // Jam Thumbprints
        {"butter", "sugar", "eggs", "vanilla", "flour", "walnuts", "strawberry jam"},
        // Gingersnap Cookies
        {"flour", "ginger", "cinnamon", "sugar", "molasses", "cinnamon"},
        // Meringue Cookies
        {"eggs", "sugar", "vanilla", "chocolate", "chips", "peanuts"},
        // Pizzelles
        {"sugar", "vanilla", "butter", "flour", "baking powder"},
        // Snickerdoodles
        {"sugar", "butter", "flour", "cream of tartar", "cinnamon"},
    };

    newName = names[idx];
    newCalories = calories[idx];
    newServings = servings[idx];
    newIngredients = ingredients[idx];
}
