#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Search_Functions.h"
#include "Book.h"
#include "Validation.h"

using namespace std;

vector<Book> parseCatalogue(const string& filename) {
    vector<Book> catalogueVector; 
    
    ifstream file(filename);

    if (!file.is_open()) {//send an error message if the file fails to open
        cerr << "Error opening file!" << endl;
        return catalogueVector;
    }

    string line;
    getline(file, line);//skip the header line
    
    while (getline(file, line)) {
        
        stringstream bookstream(line);
    
        string serialString, title, authorFirst, authorLast, genre, priceString, stockString, keywords; //create strings to store values
        
        // Read values from the CSV
        getline(bookstream, serialString, ',');
        int serialNumber = stoi(serialString);// Convert serial to integer
        
        getline(bookstream, title, ',');
        getline(bookstream, authorFirst, ',');
        getline(bookstream, authorLast, ',');
        getline(bookstream, genre, ',');
        
        getline(bookstream, priceString, ',');
        double price = stod(priceString);// Convert price to double
        
        getline(bookstream, stockString, ',');
        int stock = stoi(stockString);  // Convert stock to integer
        
        getline(bookstream, keywords);

        
        Book book(serialNumber, title, authorFirst, authorLast, genre, price, stock, keywords);// Create a Book object 
        
        catalogueVector.push_back(book);  // Add object to the vector
    }

    file.close();
    return catalogueVector;  
}
int main()
{   
    /*
    //books entered manually for testing purposes, file will be used in the future
    Book book1(1, "Fourth Wing", "Rebecca", "Yarros", "Fantasy", 7.99, 1, "journey dragon kingdom");
    Book book2(2, "Sunrise on the Reaping", "Suzanne", "Collins", "Science Fiction", 10.99, 1, "district love fight");
    Book book3(3, "Think and Grow Rich", "Napoleon", "Hill", "Motivational", 9.99, 1, "money mind intelligence");
    Book book4(4, "The Law of Success", "Napoleon", "Hill", "Motivational", 8.99, 1, "mind work succeed");
    Book book5(5, "The Grey Wolf", "Louise", "Penny", "Mystery", 9.99, 1, "murder threat terrorism");

    vector<Book> catalogue_Vector = {book1, book2, book3, book4, book5};
    */
    vector<Book> catalogue_Vector = parseCatalogue("books.txt");
    
    char selector;
    char searchSelector;
    while(selector!=6){
    
    cout<<"______Welcome to the Catalogue_______"<<endl;
    cout<<"1.Add Book(WIP)"<<endl;
    cout<<"2.Remove Book(WIP)"<<endl;
    cout<<"3.Search"<<endl;
    cout<<"4.Checkout"<<endl;
    cout<<"5.Purchase"<<endl;
    cout<<"6.Exit"<<endl;
    selector = validateChar("What operation would you like to perform?");
    
    if (selector=='1'){     //--------------------------------------
        
        cout<<"Nothing Here yet"<<endl;//###
        
    }else if(selector=='2'){//--------------------------------------

        cout<<"Nothing Here yet"<<endl;//###
        
    }else if(selector=='3'){//--------------------------------------
        string genre;
        string authorFirstName;
        string authorLastName;
        double price1;
        double price2;
        while(searchSelector!='5'){
            
            cout<<"_____________Search Menu_____________"<<endl;
            cout<<"Edit filters?"<<endl;
            cout<<"1.Genre(WIP)"<<endl;
            cout<<"2.Author(WIP)"<<endl;
            cout<<"3.Price"<<endl;
            cout<<"4.Confirm Search"<<endl;
            cout<<"5.Back"<<endl;
            searchSelector = validateChar("What operation would you like to perform?");
            if (searchSelector=='1'){     //******************
                cout<<"Enter desired Genre:"<<endl;
                cin>>genre;
                
            }else if(searchSelector=='2'){//******************
                cout<<"Enter Author's first name:"<<endl;
                cin>>authorFirstName;
                cout<<"Enter Author's Last name:"<<endl;
                cin>>authorLastName;
        
            }else if(searchSelector=='3'){//******************
                price1 = validateDouble("Enter minimum price:");
                price2 = validateDouble("Enter maximum price:");
                
            }else if(searchSelector=='4'){//******************
                bool noResults = true;
                
                cout<<"___________Search Results___________"<<endl;
                for (const Book& book : catalogue_Vector) {
                
                    if(/*genreSearch(book,genre) && authorSearch(book,authorFirstName,authorLastName) && */priceSearch(book,price1,price2) && inStock(book)){
                    book.print();
                    noResults=false;
                    }
                }
                if (noResults){
                    cout<< "We don't seem to have any books in stock that match those filters."<<endl;
                }
                
            
            
            }else if(searchSelector=='5'){//******************
                selector = 1;
            }else{
                cout<<"Invalid Number entered, please try again."<<endl;
            }
        }
        
        
    }else if(selector=='4'){//--------------------------------------
        int checkoutNumber;
        bool validInput = false;
        checkoutNumber = validateInt("Enter the serial number of a book to check it out:");

        for (const Book& book : catalogue_Vector) {
                
            if(book.serialNumber == checkoutNumber){
            cout<< "You have checked out "<< book.title <<", Thank you for visiting!"<<endl;
            validInput = true;
            }
        }
        if (!validInput){ 
            cout<< "We don't seem to have a book with that serial number."<<endl;
            
        }
        
    }else if(selector=='5'){//--------------------------------------
        int purchaseNumber;
        bool validInput = false;
        cout<<"Enter the serial number of a book to check it out:";
        cin>>purchaseNumber;
        
        for (const Book& book : catalogue_Vector) {    
            if(book.serialNumber == purchaseNumber){
            cout<< "You have Purchased "<< book.title <<", $"<< book.price << " has been deducted from your accout, Thank you for visiting!"<<endl;
            validInput = true;
            }
        }
        if (!validInput){ 
            cout<< "We don't seem to have a book with that serial number."<<endl;
            
        }
        
        
        
    }else if(selector=='6'){//--------------------------------------
        
        cout<<"Exiting Program...";
        return 0;
    
    }else{
        cout<<"Invalid Number entered, please try again."<<endl;
    }
    
    }
    
    
   
}
