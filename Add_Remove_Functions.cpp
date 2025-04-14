//add_remove_functions.cpp
#include "Add_Remove_Functions.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

int getSerialNumber(vector<Book>& bookVector){
    int serialNumber;
    while(true){
        cout<<"Please enter a book serial number: ";
        int i=0;
        
        while (!(cin>>serialNumber)) {//this while loop will verify that the input is an integer
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        for(auto&book : bookVector){//this for loop will will verify that the serial number entered does not exist
            if(serialNumber==book.serialNumber){
                cout<<"This serial number already exist."<<endl;
                i++;//this add 1 if the number already exist
            }
            else{
                continue;
            }
        }
        if(i==0){//if the number does not exist then it will continue to get other inputs
            return(serialNumber);
        }
        
    }
}


string getTitle(vector<Book>& bookVector){//this function will get the book title 
    string title;
    cout<<"Please enter the book title: ";
    cin>>title;
    return title;
}



string getFirstName(vector<Book>& bookVector){//this function will get the book author first name
    string firstName;
    int i;//this will count non alphabetical characters
    cout<<"Please enter the author's first name: ";
    while(true){
        i=0;//reset count
        cin>>firstName;
        for (char letter : firstName) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        }
        if(i==0){//if count equals 0 it will return first name
            return firstName;
        }
        else{
            cout<<"Invalid input. Please enter the author's first name with only letters: ";
            continue;
        }
    }
}


string getLastName(vector<Book>& bookVector){//this function will get the book author last name
    string lastName;
    int i;//this will count non alphabetical characters
    cout<<"Please enter the author's last name: ";
    while(true){
        i=0;//reset count
        cin>>lastName;
        for (char letter : lastName) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        }
        if(i==0){//if count equals 0 it will return last name
            return lastName;
        }
        else{
            cout<<"Invalid input. Please enter the author's last name with only letters: ";
            continue;
        }
    }
}
  

string getGenre(vector<Book>& bookVector){//this function will get the genre
    string genre;
    int i;//this will count non alphabetical characters
    cout<<"Please enter the genre: ";
    while(true){
        i=0;//reset count
        cin>>genre;
        for (char letter : genre) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        }
        if(i==0){//if count equals 0 it will return genre
            return genre;
        }
        else{
            cout<<"Invalid input. Please enter the genre with only letters: ";
            continue;
        }
    }
}





void addBook(vector<Book>& bookVector){//should return nothing but will allow the user to add a book and append it to the book vector and books.txt file
    int serialNumber = getSerialNumber(bookVector);
    string title = getTitle(bookVector);
    string authorFirstName = getFirstName(bookVector);
    string authorLastName = getLastName(bookVector);
    string genre = getGenre(bookVector);
}
    

void removeBook(vector<Book>& bookVector){//should return nothing but will remove a book from the object vector and books file
    
}


    
    
