#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Search_Functions.h"
#include "Book.h"
#include "Validation.h"
#include "Parse_Catalogue.h"
#include "Add_Remove_Functions.h"


using namespace std;

int main()
{   

    vector<Book> catalogue_Vector = parseCatalogue("books.txt");
    
    char selector;
    char searchSelector;
    while(selector!=6){
    cout<<"______Welcome to the Catalogue_______"<<endl;
    cout<<"1.Add Book"<<endl;
    cout<<"2.Remove Book"<<endl;
    cout<<"3.Search"<<endl;
    cout<<"4.Checkout"<<endl;
    cout<<"5.Purchase"<<endl;
    cout<<"6.Exit"<<endl;
    selector = validateChar("What operation would you like to perform?");
    
    if (selector=='1'){     //--------------------------------------
        addBook(catalogue_Vector);
        
    }else if(selector=='2'){//--------------------------------------
        removeBook(catalogue_Vector);
        
    }else if(selector=='3'){//--------------------------------------
        string genre;
        string authorFirstName;
        string authorLastName;
        string searchText;
        double price1 = 0.0;
        double price2 = 999999999.0;
        while(searchSelector!='5'){
            
            cout<<"_____________Search Menu_____________"<<endl;
            cout<<"Edit filters?"<<endl;
            cout<<"1.Genre Filter"<<endl;
            cout<<"2.Author Filter"<<endl;
            cout<<"3.Price Filter"<<endl;
            cout<<"4.Keyword Search"<<endl;
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
                cout<<"What would you like to search for?";
                cin>>searchText;
                
                for (const Book& book : catalogue_Vector) {
                
                    if(genreSearch(book,genre) && authorSearch(book,authorFirstName,authorLastName) && priceSearch(book,price1,price2) 
                    && inStock(book) && ( titleSearch(book, searchText) || keywordSearch(book, searchText) ) ){
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
