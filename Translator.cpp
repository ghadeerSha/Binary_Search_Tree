/*
 * Translator.cpp
 * 
 * Description: Drives the testing of the BST, the BSTNode, 
 *              the WordPair and all the exceptions classes. 
 *
 * Author: AL
 * Last Modification Date: Feb. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "Dictionary.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"


void display(const WordPair& anElement) {
  cout << anElement.getEnglish() << ":" << anElement.getTranslation() << endl;
} // end of display


// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {

  Dictionary<WordPair>* testing = new Dictionary<WordPair>();
    
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "myDataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  
  ifstream myfile (filename); 
  if (myfile.is_open()) {
  	cout << "Reading from a file:" << endl; 
    while ( getline (myfile,aLine) )
    {
       pos = aLine.find(delimiter);
       englishW = aLine.substr(0, pos);
       aLine.erase(0, pos + delimiter.length());
       translationW = aLine;

       WordPair aWordPair(englishW, translationW);
	   // insert aWordPair into "testing" using a try/catch block
       try{
           testing->put(aWordPair);
           }catch(ElementAlreadyExistsException& anException){
               cout << aWordPair.getEnglish() << ":" << aWordPair.getTranslation() << endl;
                // throw "Element already inserted";
                //cout <<"Element already inserted"<< endl;

           }
    }
  }
    myfile.close();


    // If user entered "Display" at the command line ...
    if ( ( argc > 1 ) && (strcmp(argv[1], "Display"))) {
         
         testing->displayContent(display);
       
        // ... then display the content of the BST.
    }
    else if (argc == 1) {
       // while user has not entered CTRL+D

       while ( getline(cin, aWord) ) {  
          
            WordPair aWordPair(aWord);
        try {
              translated = testing->get(aWordPair);
              cout << translated.getEnglish() << ":" << translated.getTranslation() << endl;
          }
          catch (ElementDoesNotExistException()) {
              cout << "Translation for '" << aWordPair.getEnglish() << "' not found!" << endl;
            // cout << aWordPair;
          // retrieve aWordPair from "testing" using a try/catch block
		  // print aWordPair

       }
    }
  }
  else 
    cout << "Unable to open file"; 

  return 0;
}