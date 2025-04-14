#ifndef ADD_REMOVE_FUNCTIONS_H
#define ADD_REMOVE_FUNCTIONS_H

#include "Book.h"
#include <vector>

using namespace std;

void removeBook(vector<Book>& bookVector);//should return nothing but a book from the object vector and books file

void addBook(vector<Book>& bookVector);//should return nothing but will allow the user to add a book and append it to the book vector and books.txt file

#endif
