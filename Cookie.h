#ifndef COOKIE_H
#define COOKIE_H

#include <string>
#include <vector>
#include <set>

class Cookie
{
public:
    Cookie() : name("NA"), calories(0), servings(0) {}
    Cookie(const std::string &newName, size_t newCalories,
           size_t newServings, const std::set<std::string> &newIngredients) : name(newName), calories(newCalories),
                                                                              servings(newServings), ingredients(newIngredients) {}

    std::string getName() const;
    size_t getCalories() const;
    size_t getServings() const;
    std::set<std::string> getIngredients() const;
    Cookie getCookie() const;

    void setName(const std::string &newName);
    void setCalories(size_t newCalories);
    void setServings(size_t newServings);
    void setIngredients(const std::vector<std::string> &
                            newIngredients);

    void printRecipe() const;
    void printIngredients() const;
    void printCalories() const;

    ~Cookie() {}

private:
    std::string name;
    size_t calories;
    size_t servings;
    std::set<std::string> ingredients;
};

#endif
