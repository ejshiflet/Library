#ifndef BOOK_H
#define BOOK_H
struct Book {
    int serialNumber;
    string title;
    string authorFirstName;
    string authorLastName;
    string genre;
    double price;
    int stock;
    string keywords;
    
    
    Book(int serial, const string& t, const string& authorFirst, const string& authorLast, const string& g, double p, int s, const string& k)
        : serialNumber(serial), title(t), authorFirstName(authorFirst), authorLastName(authorLast), genre(g), price(p), stock(s), keywords(k) {}
}

#endif
