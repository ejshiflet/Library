#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Search_Functions.h"
#include "Book.h"

using namespace std;


int main()
{   
    
    //books entered manually for testing purposes, file will be used in the future
    Book book1(1, "Fourth Wing", "Rebecca", "Yarros", "Fantasy", 7.99, 1, "journey dragon kingdom");
    Book book2(2, "Sunrise on the Reaping", "Suzanne", "Collins", "Science Fiction", 10.99, 1, "district love fight");
    Book book3(3, "Think and Grow Rich", "Napoleon", "Hill", "Motivational", 9.99, 1, "money mind intelligence");
    Book book4(4, "The Law of Success", "Napoleon", "Hill", "Motivational", 8.99, 1, "mind work succeed");
    Book book5(5, "The Grey Wolf", "Louise", "Penny", "Mystery", 9.99, 1, "murder threat terrorism");

    vector<Book> catalogue_Vector = {book1, book2, book3, book4, book5};
    
    
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
    cout<<"What operation would you like to perform?";
    cin>>selector;
    
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
            cout<<"Proceed when Ready:"<<endl;
            cin>>searchSelector;
            if (searchSelector=='1'){     //******************
                cout<<"Enter desired Genre:"<<endl;
                cin>>genre;
            }else if(searchSelector=='2'){//******************
                cout<<"Enter Author's first name:"<<endl;
                cin>>authorFirstName;
                cout<<"Enter Author's Last name:"<<endl;
                cin>>authorLastName;
        
            }else if(searchSelector=='3'){//******************
                cout<<"Enter minimum price:"<<endl;
                cin>>price1;
                cout<<"Enter maximum price:"<<endl;
                cin>>price2;                
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
        cout<<"Enter the serial number of a book to check it out:";
        cin>>checkoutNumber;
        
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
