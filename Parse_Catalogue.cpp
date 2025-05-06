//coded by Shawn Michaelis
#include "Parse_Catalogue.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<Book> parseCatalogue(const std::string& filename) {
    std::vector<Book> catalogueVector; 
    
    std::ifstream file(filename);

    if (!file.is_open()) { // Send an error message if the file fails to open
        std::cerr << "" << std::endl;
        return catalogueVector;
    }

    std::string line;
    std::getline(file, line); // Skip the header line
    
    while (std::getline(file, line)) {
        
        std::stringstream bookstream(line);
    
        std::string serialString, title, authorFirst, authorLast, genre, priceString, stockString, keywords; // Create strings to store values
        
        // Read values from the CSV
        std::getline(bookstream, serialString, ',');
        int serialNumber = std::stoi(serialString); // Convert serial to integer
        
        std::getline(bookstream, title, ',');
        std::getline(bookstream, authorFirst, ',');
        std::getline(bookstream, authorLast, ',');
        std::getline(bookstream, genre, ',');
        
        std::getline(bookstream, priceString, ',');
        double price = std::stod(priceString); // Convert price to double
        
        std::getline(bookstream, stockString, ',');
        int stock = std::stoi(stockString); // Convert stock to integer
        
        std::getline(bookstream, keywords);

        Book book(serialNumber, title, authorFirst, authorLast, genre, price, stock, keywords); // Create a Book object 
        
        catalogueVector.push_back(book); // Add object to the vector
    }

    file.close();
    return catalogueVector;  
}
