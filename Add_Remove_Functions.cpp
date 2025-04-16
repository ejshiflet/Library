//add_remove_functions.cpp
#include "Add_Remove_Functions.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include <string>

using namespace std;

//=========================================================================================================================================

int getSerialNumber(vector<Book>& bookVector){
    //cin.ignore();
    while(true){
    std::string serialNumberString;
    int serialNumber;
    bool valid_input = false;
    int i=0;
        while (!valid_input) {//this while loop will make sure the user input has no spaces and is an integer
            cout << "Enter a book serial number: ";
            getline(cin, serialNumberString);//get input
            
            for(char element:serialNumberString){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will goto the end of the outer while(true) loop and start again
                    cout<<"Invalid input. No spaces should be entered."<<endl;
                    goto outerLoop;
                }
            }
            try {//this will try to convert the serial number entered to a string
                serialNumber = stoi(serialNumberString);//convert
                valid_input = true;//if it works make the input valid
            } catch (const invalid_argument& e) {
                cerr << "Invalid input. Please enter an integer." << endl;
            } catch (const out_of_range& e) {
                cerr << "Input out of range. Please enter an integer within the valid range." << endl;
            }
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
            else{
                continue;
            }
            outerLoop:
            continue;
        }
}
    
//=========================================================================================================================================


string getTitle(vector<Book>& bookVector){//this function will get the book title 
    string title;
    cout<<"Please enter the book title: ";
    getline(cin, title);
    return title;
}

//=========================================================================================================================================

string getFirstName(vector<Book>& bookVector){//this function will get the book author first name
    string firstName;
    int i;//this will count non alphabetical characters
    cout<<"Please enter the author's first name: ";
    while(true){
        i=0;//reset count
        getline(cin, firstName);
        for (char letter : firstName) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        
        }
        for(char element:firstName){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will add 1 to 'i' which won't allow it to return the input
                    i++;
                }
                else{
                    continue;
                }
        }
                
        if(i==0){//if count equals 0 it will return first name
            return firstName;
        }
        else{
            cout<<"Invalid input. Please enter the author's first name with only letters and no spaces: ";
            continue;
        }
    }
}

//=========================================================================================================================================

string getLastName(vector<Book>& bookVector){//this function will get the book author last name
    string lastName;
    int i;//this will count non alphabetical characters
    cout<<"Please enter the author's last name: ";
    while(true){
        i=0;//reset count
        getline(cin, lastName);
        for (char letter : lastName) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        
        }
        for(char element:lastName){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will add 1 to 'i' which won't allow it to return the input
                    i++;
                }
                else{
                    continue;
                }
        }
                
        if(i==0){//if count equals 0 it will return first name
            return lastName;
        }
        else{
            cout<<"Invalid input. Please enter the author's last name with only letters and no spaces: ";
            continue;
        }
    }
}
  
//=========================================================================================================================================

string getGenre(vector<Book>& bookVector){//this function will get the genre
    string genre;
    int i;//this will count non alphabetical characters
    cout<<"Please enter the genre: ";
    while(true){
        i=0;//reset count
        getline(cin, genre);
        for (char letter : genre) {//for loop will count non alphabetical characters
            if (isalpha(letter) || letter ==' ') {
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

//=========================================================================================================================================

int getPrice(vector<Book>& bookVector){
    string priceString;
    float price;
    while(true){
    bool valid_input = false;
    int i=0;
        while (!valid_input) {//this while loop will make sure the user input has no spaces and is an integer
            cout << "Enter a price: ";
            getline(cin, priceString);//get input
            
            for(char element:priceString){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will goto the end of the outer while(true) loop and start again
                    cout<<"Invalid input. No spaces should be entered."<<endl;
                    goto outerLoop;
                }
            }
            try {//this will try to convert the serial number entered to a string
                price = stof(priceString);//convert
                valid_input = true;//if it works make the input valid
            } catch (const invalid_argument& e) {
                cerr << "Invalid input. Please enter an integer." << endl;
            } catch (const out_of_range& e) {
                cerr << "Input out of range. Please enter an integer within the valid range." << endl;
            }
            outerLoop:
            continue;
        }
        return price;
    }
}

//=========================================================================================================================================

string getKeyWords(){//this function will get the book author first name
    string allKeyWords;
    string keyWordOne;
    string keyWordTwo;
    string keyWordThree;
    
    int i;//this will count non alphabetical characters
    cout<<"Please enter three keywords. Keyword One: ";
    while(true){
        i=0;//reset count
        getline(cin, keyWordOne);
        for (char letter : keyWordOne) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        
        }
        for(char element:keyWordOne){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will add 1 to 'i' which won't allow it to return the input
                    i++;
                }
                else{
                    continue;
                }
        }
                
        if(i==0){//if count equals 0 it will return first name
            break;
        }
        else{
            cout<<"Invalid input. Please enter the author's first name with only letters and no spaces: ";
            continue;
        }
    }
    cout<<"Keyword Two: ";
    while(true){
        i=0;//reset count
        getline(cin, keyWordTwo);
        for (char letter : keyWordTwo) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        
        }
        for(char element:keyWordTwo){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will add 1 to 'i' which won't allow it to return the input
                    i++;
                }
                else{
                    continue;
                }
        }
                
        if(i==0){//if count equals 0 it will return first name
            break;
        }
        else{
            cout<<"Invalid input. Please enter the author's first name with only letters and no spaces: ";
            continue;
        }
    }
    cout<<"Keyword Three: ";
    while(true){
        i=0;//reset count
        getline(cin, keyWordThree);
        for (char letter : keyWordThree) {//for loop will count non alphabetical characters
            if (isalpha(letter)) {
            continue;
            }
            else {
                i++;
            }
        
        }
        for(char element:keyWordThree){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will add 1 to 'i' which won't allow it to return the input
                    i++;
                }
                else{
                    continue;
                }
        }
                
        if(i==0){//if count equals 0 it will return first name
            break;
        }
        else{
            cout<<"Invalid input. Please enter the author's first name with only letters and no spaces: ";
            continue;
        }
    }
    allKeyWords = (keyWordOne + " " + keyWordTwo + " "+ keyWordThree);
    return allKeyWords;
}


//=========================================================================================================================================

void addBook(vector<Book>& bookVector){//should return nothing but will allow the user to add a book and append it to the book vector and books.txt file
    int serialNumber = getSerialNumber(bookVector);
    cout<<serialNumber;
    string title = getTitle(bookVector);
    string authorFirstName = getFirstName(bookVector);
    string authorLastName = getLastName(bookVector);
    string genre = getGenre(bookVector);
    float price = getPrice(bookVector);
    string keyWords = getKeyWords();
    
}
    

void removeBook(vector<Book>& bookVector){//should return nothing but will remove a book from the object vector and books file
    
}


    
    


    
    
