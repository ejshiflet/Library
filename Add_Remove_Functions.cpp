//add_remove_functions.cpp

/*

    Coded by Evan Shiflet 

*/
#include "Book.h"
#include "Add_Remove_Functions.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Validation.h"

using namespace std;

//=========================================================================================================================================

int getSerialNumber(vector<Book>& bookVector){
    while(true){
    string serialNumberString;
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
                //the if statement below will keep users from entering letter after the serial number which stoi() does not detect
                if(element == '0' ||element == '1'|| element == '2' ||element == '3' ||element == '4' ||element == '5' ||element == '6' ||element == '7' ||element == '8' ||element == '9' ){
                    continue;
                }
                else{
                    cout<<"Invalid input. Only numbers should be entered."<<endl;
                    goto outerLoop;
                }
            }
            serialNumber = stoi(serialNumberString);//convert
            valid_input = true;//if it works make the input valid
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

double getPrice(vector<Book>& bookVector){
    string priceString;
    double price;
    while(true){
    bool valid_input = false;
        while (!valid_input) {//this while loop will make sure the user input has no spaces and is an integer
            cout << "Enter a price: ";
            getline(cin, priceString);//get input
            int decimalCount=0;
            for(char element:priceString){//for loop will check every line for spaces
                if(element== ' '){//if there is a space it will goto the end of the outer while(true) loop and start again
                    cout<<"Invalid input. No spaces should be entered."<<endl;
                    goto outerLoop;
                }
                if(element =='.'){//counts how many decimals are in the user input
                    decimalCount = decimalCount + 1;
                }
                if(decimalCount>1){//if there is more than one decimal it will go back to the outer loop
                    cout<<"Invalid input. Too many decimals were entered."<<endl;
                    goto outerLoop;
                }
                //the if and else statement below will keep users from entering letter after the serial number which stof() does not detect
                if(element == '0' ||element == '1'|| element == '2' ||element == '3' ||element == '4' ||element == '5' ||element == '6' ||element == '7' ||element == '8' ||element == '9'|| element =='.' ){
                    ;
                }
                else{
                    cout<<"Invalid input. Only numbers and a '.' should be entered."<<endl;
                    goto outerLoop;
                }
            }
            try {//this will try to convert the serial number entered to a string
                price = stod(priceString);//convert
                valid_input = true;//if it works make the input valid
            } catch (const invalid_argument& e) {
                cerr << "Invalid input. Please enter an integer." << endl;
            } catch (const out_of_range& e) {
                cerr << "Input out of range. Please enter an integer within the valid range." << endl;
            }
            outerLoop:
            continue;
        }
        stringstream ss;
        ss<<fixed<<setprecision(2)<<price;//string stream will set fixed precision to two decimal places
        ss>>price;
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
            cout<<"Invalid input. Please enter a keyword only letters and no spaces: ";
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
            cout<<"Invalid input. Please enter a keyword only letters and no spaces: ";
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
            cout<<"Invalid input. Please enter a keyword only letters and no spaces: ";
            continue;
        }
    }
    allKeyWords = (keyWordOne + " " + keyWordTwo + " "+ keyWordThree);
    return allKeyWords;
}



//=========================================================================================================================================

int writeVectorToFile(vector<Book>& bookVector){
    string filename = "books.txt";
    ofstream file(filename);
    // Check if the file was opened successfully
    if (file.is_open()) {
        // Write the header row
        file << "serialNumber,title,authorFirstName,authorLastName,genre,price,stock,keywords\n";

        // Write each object to a new row in the txt file
        for (auto& book : bookVector) {
            file<< to_string(book.serialNumber)+","+book.title+","+book.authorFirstName+","+book.authorLastName+","+book.genre+",";
            file<< fixed << setprecision(2) <<book.price;
            file<< ","+to_string(book.stock)+","+book.keywords+"\n";
            
        }
        file.close();//close file
        return 0;
    } 
    else {
        return 1;
    }

}

//=========================================================================================================================================

int addBook(vector<Book>& bookVector){//should return nothing but will allow the user to add a book and append it to the book vector and books.txt file
    bool isValid = false;
    bool skipStructCreation;
    int serialNumber;
    string title;
    string authorFirstName;
    string authorLastName;
    string genre;
    double price;
    string keyWords;
    
    
    
    while(!isValid){
        
        isValid = false;
        skipStructCreation = false;
        
        int serialNumber = getSerialNumber(bookVector);//gets serial number and stores in variable
        string title = getTitle(bookVector);//gets title and stores in variable
        string authorFirstName = getFirstName(bookVector);//gets author first name and stores in file
        string authorLastName = getLastName(bookVector);//gets author last name and stores in file
        
        for(auto&book : bookVector){//this for loop will will verify that the book entered does not exist
            if(title==book.title and authorFirstName==book.authorFirstName and authorLastName==book.authorLastName){//checks if title and author are the same
                cout<<"This book has already been added to the catologue."<<endl;
                skipStructCreation = true;
                goto skipInputs;//skip over the rest of inputs
            }
            else{
                continue;
            }
        }
        
        genre = getGenre(bookVector);//get genre
        price = getPrice(bookVector);//get price
        keyWords = getKeyWords();//get keywords
        
        skipInputs:;
        if(skipStructCreation == true){//will skip over struct creation if book has same tite and author
            ;
        }
        else{
            //add book to txt file and vector here
            Book book(serialNumber, title, authorFirstName, authorLastName, genre, price, 1, keyWords);
            bookVector.push_back(book);
            writeVectorToFile(bookVector);
        }
        string stopOrContinue;
        
        cout<<"If you would like to continue entering books type '1' or '2' to return to main menu:";
        
        while(true){//while loop will ask the user if they want to continue or back to main menu
            getline(cin,stopOrContinue);
            if(stopOrContinue=="1"){
                isValid = false;
                break;
            }
            else if(stopOrContinue == "2"){
                isValid = true;
                break;
            }
            else{
                cout<<"Invalid input. Please enter '1' or '2': ";
            }
        }
    }

    return 0;
}
    

int removeBook(vector<Book>& bookVector){//should return nothing but will remove a book from the object vector and books file
    string serialNumberToRemove;//will hold serial number to be removed
    int bookIndex;//will count book index
    bool bookFound;//will become true if a book with serial number exist
    string stopOrContinue;//will get input for removing more books or not
    bool noMoreRemoving = false;//will set to true if user does not want to enter more books
    
    while(!noMoreRemoving){
        if(bookVector.size() == 0){
            cout<<"No books have been added. Returning to main menu.";
            break;
        }
        cout<<"\n";
        bookFound = false;
        bookIndex = 0;//keep book index set to zero
        
        for(auto&book : bookVector){//for loop to print out book info
            cout<<"Serial Number: " + to_string(book.serialNumber) + " | Title: " + book.title + " | Author: " + book.authorFirstName + " " + book.authorLastName << endl;
        }
        cout<<"\nPlease enter the serial number of the book you would like to remove from the data base: ";
        while(true){//while true loop till user enters valid serial number
            getline(cin,serialNumberToRemove);
            for(auto&book : bookVector){//for loop to iterate through all books
                if(to_string(book.serialNumber) == serialNumberToRemove){//if the serial exist remove it
                    cout<<book.title + " has been removed.";
                    bookVector.erase(bookVector.begin() + bookIndex);//erase book
                    bookVector.shrink_to_fit();//remove spaces
                    bookFound = true;//set book fount to true
                }
                else{
                    bookIndex = bookIndex + 1;
                }
            }
            if(bookFound == true){//if book is found loop will break and ask if more book want to be removed
                break;
            }
            else{
                cout<<"No serial number found. Please enter the serial number of the book with no spaces as shown from the list:";
            }
        }
        
        cout<<" If you would like to continue removing books type '1' or '2' to return to main menu:";

            
        while(true){//while loop will ask the user if they want to continue or back to main menu
            getline(cin,stopOrContinue);
            if(stopOrContinue=="1"){
                noMoreRemoving = false;
                break;
            }
            else if(stopOrContinue == "2"){
                noMoreRemoving = true;//when it is set to true it will break the enter loop 
                break;
            }
            else{
                cout<<"Invalid input. Please enter '1' or '2': ";
            }
        }
    }
    writeVectorToFile(bookVector);//adds the new vector info to the file
    return 0;
}
