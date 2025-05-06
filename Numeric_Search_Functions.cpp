//Coded by Shawn Michaelis
#include "Search_Functions.h"
#include "Book.h"

bool priceSearch(const Book& book, double price1, double price2) {
    return (price1 < price2 && (book.price >= price1 && book.price <= price2)) || (price1 > price2 && (book.price <= price1 && book.price >= price2));
}
bool inStock(const Book& book) {
    return (book.stock>0);
}
