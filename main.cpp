#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

const int columnCount = 5 ;


void readCatalogue(const string fileName, int catalogue[100][columnCount], int &lineCount) {
    ifstream catalogueFile(fileName);
    if (!catalogueFile.is_open()) {//check if file has opened properly, if not, terminate the method early
        cout << "Error: Could not open file " << fileName << endl;
        return;
    }

    lineCount = 0;
    string currentLine;
    while (getline(catalogueFile, currentLine, '\n')) {//should seperate the file by \n into strings containing each book's properties
        stringstream lineStream(currentLine);
        string currentColumn;
        int attributeIndex = 0;

        while (getline(lineStream, currentColumn, ',') && attributeIndex < columnCount) {//then each line is converted back into a datastream and seperated by comma into the inner arrays
            catalogue[lineCount][attributeIndex] = stoi(currentColumn);
            attributeIndex++;
        }

        lineCount++;
    }

    catalogueFile.close();
}


int main()
{   
    
    //read datdabase file into a datastream, and convert it into a vector
   
    
    
    char selector;
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
    if
        
        
    }else if(selector=='4'){//--------------------------------------

        
        
    }else if(selector=='5'){//--------------------------------------

        
        
    }else if(selector=='6'){//--------------------------------------

        
    
    }else{
        cout<<"Invalid Number entered, please try again."<<endl;
    }
    
    }
    
    
   
}
