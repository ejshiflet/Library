#include "Validation.h"

int validateInt(const std::string& prompt) {
    int value;
    
    std::cout << prompt;//ask question
    
    while (!(std::cin >> value)) {//attempt to store input in int value, if failed, prompt for a new input
        std::cout << "Invalid input. Please enter a valid number: ";
        
        std::cin.clear();//clear errors to allow new input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//clear previous input
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//clear input line to prevent any overflow
    
    return value;
}


double validateDouble(const std::string& prompt) {
    double value;
    
    std::cout << prompt;//ask question
    
    while (!(std::cin >> value)) {//attempt to store valid double
        std::cout << "Invalid input. Please enter a valid decimal number: ";
        
        std::cin.clear();//clear errors to allow new input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//clear line
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    return value;
}


char validateChar(const std::string& prompt) {
    char c;
    
    std::cout << prompt;//ask question
    
    std::cin >> c; //store the result
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear the rest of the line
    return c;
}
