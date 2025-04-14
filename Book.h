#ifndef BOOK_H
#define BOOK_H

#include <string>
struct Book {
    int serialNumber;
    std::string title;
    std::string authorFirstName;
    std::string authorLastName;
    std::string genre;
    double price;
    int stock;
    std::string keywords;

    Book(int serial, const std::string& t, const std::string& authorFirst, const std::string& authorLast, const std::string& g, double p, int s, const std::string& k)
         : serialNumber(serial), title(t), authorFirstName(authorFirst), authorLastName(authorLast), genre(g), price(p), stock(s), keywords(k) {}
};
#endif
