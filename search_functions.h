#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H
#include <vector>

bool titleSearch(const std::vector<std::string>& vec, const std::string& title);//should return true if any of the entered text is found within the book's title

bool keywordSearch(const std::vector<std::string>& vec, const std::string& title);//should return true if any of the entered text is found within the book's keyword section


bool genreSearch(const std::vector<std::string>& vec, const std::string& genre);//should return true if the genre entered matches the books genre

bool authorSearch(const std::vector<std::string>& vec, const std::string& firstName, const std::string& lastName);//should return true if the author's first or last name is found in the book


bool priceSearch(const std::vector<std::string>& vec, const std::double& price1, const std::double& price2);//should return true if the book's price is between the two entered values ((P1<C<P2) or (P1>C>P2))

bool InStock(const std::vector<std::string>& vec);//should return true if the book is in stock (stock>0)



#endif
