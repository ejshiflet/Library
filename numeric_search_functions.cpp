#include "Search_Functions.h"

bool priceSearch(const Book& book, double price1, double price2) {
    return (price1 < price2 && (book.price >= price1 && book.price <= price2)) || (price1 > price2 && (book.price <= price1 && book.price >= price2));
}
bool InStock(const Book& book) {
    return (book.stock>0);
}

