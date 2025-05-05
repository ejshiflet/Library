#include "Search_Functions.h"
#include "Book.h"
#include <algorithm>
#include <cctype>
#include <string>

// Utility function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

// Search for a book by genre (case insensitive)
bool genreSearch(const Book& book, const std::string& genre) {
    return toLower(book.genre).find(toLower(genre)) != std::string::npos;
}

// Search for a book by author's first or last name (case insensitive)
bool authorSearch(const Book& book, const std::string& firstName, const std::string& lastName) {
    const std::string bookFirstLower = toLower(book.authorFirstName);
    const std::string bookLastLower = toLower(book.authorLastName);
    const std::string searchFirstLower = toLower(firstName);
    const std::string searchLastLower = toLower(lastName);

    return bookFirstLower.find(searchFirstLower) != std::string::npos ||
           bookLastLower.find(searchLastLower) != std::string::npos;
}

// Search for a book by title (case insensitive)
bool titleSearch(const Book& book, const std::string& title) {
    if (title.empty()) {
        return false;
    }

    return toLower(book.title).find(toLower(title)) != std::string::npos;
}

// Search for a book by keyword (case insensitive)
bool keywordSearch(const Book& book, const std::string& keyword) {
    if (keyword.empty()) {
        return false;
    }

    return toLower(book.keywords).find(toLower(keyword)) != std::string::npos;
}
