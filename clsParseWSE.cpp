/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clsParseWSE.cpp
 * Author: dshaffer
 * 
 * Created on March 15, 2016, 9:42 AM
 */


#include <iostream>
#include <string>
#include <vector>
#include "clsParseWSE.h"
#include <fstream>

using namespace std;

clsParseWSE::clsParseWSE() {
}

clsParseWSE::clsParseWSE(const clsParseWSE& orig) {
}

clsParseWSE::~clsParseWSE() {
}


void clsParseWSE::GetWSE(std::string WSEFileToCheck) {

    ifstream inputFile(WSEFileToCheck);
        if (inputFile.good()) {
            clsParseWSE::WSEPath = WSEFileToCheck;
            cout << "Good WSE" << endl;
        }
        else {
            clsParseWSE::WSEPath = "";
            cout << "BAD WSE" << endl;
            return;
        }         
    
        
 }

std::vector<std::string> clsParseWSE::parseline (std::string testline) {
    
    int x,y;
    string currentvalue;
    vector<string> values;
    values.clear();
            
            
            
    for (x=0; x<=testline.length(); ++x) {
 
      
        if (testline[x] != ' ' && testline[x] != '\n' && x != testline.length()) {
//            cout << "char " << testline[x] << "   ";
            currentvalue = currentvalue+testline[x];
    
        }
        
        else
        {
            if (currentvalue.length() > 0) {
                values.push_back(currentvalue);
  //              cout << "got one --";
            }
            currentvalue.clear();
        }
         
       
    }

     /*
    for(string t : values) // dump vector
    {
        cout << t << endl;
    }
    cout << endl;
      * */
    return values;

  //     cout << endl;
}