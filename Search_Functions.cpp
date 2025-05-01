#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H

#include "Book.h"
#include <vector>
#include <sstream>
using namespace std;

bool titleSearch(vector<Book>& bookVector, const std::string& title){
    for (Book book : bookVector) {
        if (book.title == title) {
            std::cout << "Book found Title " << book.title << " code:" << book.serialNumber << " author: " << book.authorLastName << std::endl;
            return true;
        }
    }

    return false;
}

bool keywordSearch(vector<Book>& bookVector, const std::string& title){
    std::string segment;
    std::stringstream scoreTest(title);

    std::string keyword1;
    std::string keyword2;
    std::string keyword3;
    int i=0;
    while (std::getline(scoreTest, segment, ' ')) {
        if (i==0){
            keyword1 = segment;
        }
        else if(i==1){
            keyword2 = segment;
        }
        else if(i==2){
            keyword3 = segment; 
        }
        i++;
    } 
    

    for (Book book : bookVector) {
        if (book.keywords == keyword1 || book.keywords == keyword2 || book.keywords == keyword3) {
            std::cout << "Book found Title " << book.title << " code:" << book.serialNumber<< " author: " << book.authorLastName << std::endl;
            return true;
        }
    }
    return false;
}

#endif