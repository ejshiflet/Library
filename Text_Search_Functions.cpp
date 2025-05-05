#include "Search_Functions.h"
#include "Book.h"
#include <algorithm>
#include <cctype>
/* 
The following code was the responsibility of Tyler Zheng, 
however, as he never completed it, this stand-in created by ChatGPT is working in replacement
*/
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lowerStr;
}

bool genreSearch(const Book& book, const std::string& genre) {
    std::string bookGenreLower = toLower(book.genre);
    std::string searchGenreLower = toLower(genre);
    return bookGenreLower.find(searchGenreLower) != std::string::npos;
}

bool authorSearch(const Book& book, const std::string& firstName, const std::string& lastName) {
    std::string bookFirstLower = toLower(book.authorFirstName);
    std::string bookLastLower = toLower(book.authorLastName);
    std::string searchFirstLower = toLower(firstName);
    std::string searchLastLower = toLower(lastName);

    return bookFirstLower.find(searchFirstLower) != std::string::npos ||
           bookLastLower.find(searchLastLower) != std::string::npos;
}
/*
The following code was the responsibility of  Luis Llerena Sanchez, 
however, as he never delivered it, this stand-in created by ChatGPT is working in replacement
*/
bool titleSearch(const Book& book, const std::string& title) {
    if (title.empty()) return false;

    std::string bookTitleLower = toLower(book.title);
    std::string searchTitleLower = toLower(title);
    return bookTitleLower.find(searchTitleLower) != std::string::npos;
}

bool keywordSearch(const Book& book, const std::string& keyword) {
    if (keyword.empty()) return false;

    std::string bookKeywordsLower = toLower(book.keywords);
    std::string searchKeywordLower = toLower(keyword);
    return bookKeywordsLower.find(searchKeywordLower) != std::string::npos;
}
