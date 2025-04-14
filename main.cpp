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
    cout<<"1.Add Book"<<endl;
    cout<<"2.Remove Book"<<endl;
    cout<<"3.Search"<<endl;
    cout<<"4.Checkout"<<endl;
    cout<<"5.Purchase"<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"What operation would you like to perform?";
    cin>>selector;
    
    if (selector=='1'){     //--------------------------------------
        
        
        
    }else if(selector=='2'){//--------------------------------------

        
        
    }else if(selector=='3'){//--------------------------------------
        string genre;
        string authorFirstName;
        string authorLastName;
        double price1;
        double price2;
        while(searchSelector!='5'){
            
            cout<<"_____________Search Menu_____________"<<endl;
            cout<<"Edit filters?"<<endl;
            cout<<"1.Genre"<<endl;
            cout<<"2.Author"<<endl;
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
            
            }else if(searchSelector=='5'){//******************
                selector = 1;
            }else{
                cout<<"Invalid Number entered, please try again."<<endl;
            }
        }
        
        
    }else if(selector=='4'){//--------------------------------------

        
        
    }else if(selector=='5'){//--------------------------------------

        
        
    }else if(selector=='6'){//--------------------------------------
        
        cout<<"Exiting Program...";
        return 0;
    
    }else{
        cout<<"Invalid Number entered, please try again."<<endl;
    }
    
    }
    
    
   
}
