#include <bits/stdc++.h>
using namespace std;

// Base Interfaces
class IVegetarianMenu {
public:
    virtual vector<string> getVegetarianItems() const = 0;
    virtual ~IVegetarianMenu() = default; // virtual destructor
};

class INonVegetarianMenu {
public:
    virtual vector<string> getNonVegetarianItems() const = 0;
    virtual ~INonVegetarianMenu() = default;
};

class IDrinkMenu {
public:
    virtual vector<string> getDrinkItems() const = 0;
    virtual ~IDrinkMenu() = default;
};

// Veg Restaurant
class VegRestaurant : public IVegetarianMenu, public IDrinkMenu {
public:
    vector<string> getVegetarianItems() const override {
        return {"Vegetable Curry", "Paneer Tikka", "Salad"};
    }

    vector<string> getDrinkItems() const override {
        return {"Water", "Mango Juice"};
    }
};

// Non-Veg Restaurant
class NonVegRestaurant : public INonVegetarianMenu, public IDrinkMenu {
public:
    vector<string> getNonVegetarianItems() const override {
        return {"Chicken Curry", "Chicken 65", "Mutton Biryani"};
    }

    vector<string> getDrinkItems() const override {
        return {"Water", "Litchi Juice"};
    }
};

// Mixed Restaurant
class MixRestaurant : public IVegetarianMenu, public INonVegetarianMenu, public IDrinkMenu {
public:
    vector<string> getVegetarianItems() const override {
        return {"Paneer Curry", "Paneer Masala", "Salad"};
    }

    vector<string> getNonVegetarianItems() const override {
        return {"Chicken Kebab", "Chicken Fry"};
    }

    vector<string> getDrinkItems() const override {
        return {"Water", "Apple Juice"};
    }
};

// Helper display functions
void displayVegMenu(const IVegetarianMenu& menu) {
    cout << "Veg Menu:\n";
    for (const auto& item : menu.getVegetarianItems()) {
        cout << "- " << item << endl;
    }
}

void displayNonVegMenu(const INonVegetarianMenu& menu) {
    cout << "NonVeg Menu:\n";
    for (const auto& item : menu.getNonVegetarianItems()) {
        cout << "- " << item << endl;
    }
}

void displayDrinksMenu(const IDrinkMenu& menu) {
    cout << "Drinks Menu:\n";
    for (const auto& item : menu.getDrinkItems()) {
        cout << "- " << item << endl;
    }
}

int main() {
    VegRestaurant vegMenu;
    NonVegRestaurant nonVegMenu;
    MixRestaurant mixRestaurant;

    // Veg Restaurant
    displayVegMenu(vegMenu);
    displayDrinksMenu(vegMenu);

    // NonVeg Restaurant
    displayNonVegMenu(nonVegMenu);
    displayDrinksMenu(nonVegMenu);

    // Mixed Restaurant
    displayVegMenu(mixRestaurant);
    displayNonVegMenu(mixRestaurant);
    displayDrinksMenu(mixRestaurant);

    return 0;
}
