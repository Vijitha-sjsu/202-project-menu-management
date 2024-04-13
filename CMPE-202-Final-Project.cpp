#include <iostream>
#include "MenuItem.h"
#include "Enums.h"
#include "MenuItemAdapter.h"

int main() {
    // Create a vector of menu items to test saving and loading
    std::vector<MenuItem> originalItems = {
        MenuItem("Pasta", 9.99, "/images/pasta.jpg", "Delicious Italian pasta", Category::MainCourse, {DietaryRestriction::Vegan}, Availability::Available),
        MenuItem("Burger", 11.99, "/images/burger.jpg", "Juicy beef burger", Category::MainCourse, {DietaryRestriction::GlutenFree}, Availability::Available),
        MenuItem("Cheesecake", 5.50, "/images/cheesecake.jpg", "Creamy cheesecake with strawberry", Category::Dessert, {DietaryRestriction::Vegetarian}, Availability::Available)
    };

    // File path for testing
    std::string filename = "test_menu.csv";

    // Save the menu items to CSV
    try {
        MenuItemAdapter::saveMenuItemsToCSV(originalItems, filename);
        std::cout << "Menu items saved successfully to " << filename << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error saving menu items: " << e.what() << std::endl;
        return -1;
    }

    // Load the menu items from CSV
    std::vector<MenuItem> loadedItems;
    try {
        loadedItems = MenuItemAdapter::loadMenuItemsFromCSV(filename);
        std::cout << "Menu items loaded successfully from " << filename << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error loading menu items: " << e.what() << std::endl;
        return -1;
    }

    // Display loaded items to verify correctness
    for (const auto& item : loadedItems) {
        std::cout << "Loaded Item: " << item.getName() << " - $" << item.getPrice() << " - "
                  << item.getDescription() << " - Category: " << categoryToString(item.getCategory())
                  << " - Availability: " << availabilityToString(item.getAvailability()) << std::endl;
    }

    return 0;
}
