#ifndef __INGREDIENTSTOCK_HPP__
#define __INGREDIENTSTOCK_HPP__
#include "Ingredient.hpp"
#include <vector>
#include <string>


class IngredientStock{
private:
    std::vector<Ingredient*> stock;
    const std::string file;
protected:
public:
    // Extracts contents from files and places info into stock vector
    IngredientStock();
    // Takes current ingredient stock and writes contents to file
    ~IngredientStock();
    // Return formatted str containing the ingredients in Ingredient::stock
    std::string str();
    // Get the ingredient held in stock at index
    Ingredient* get(int) const;
    // Gets an ingredient of type INGREDIENT
    Ingredient* getForUse(INGREDIENT) const;
    // Returns size of stock
    const unsigned size() const;
    // Will add the ingredient to the stock
    void add(Ingredient *);
    // Override IngredientFile's contents with IngredientStock::stock contents
    void writeToFile() const;
    // Will expend and delete ingredient from IngredientStock and IngredientFile
    void use(Ingredient*);
    // Will expend and delete the set of ingredients from IngredientStock and IngredientFile
    void use(std::vector<Ingredient*> &);
    // Will no longer allow argument to be used in other entrees.
    void reserve(Ingredient*);
    // Will no longer allow argument vector to be used in other entrees.
    void reserve(std::vector<Ingredient*> &);
    // Will allow arguement to be used in entrees again.
    void unreserve(Ingredient*);
};

#endif