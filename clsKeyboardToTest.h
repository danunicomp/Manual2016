/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clsKeyboardToTest.h
 * Author: dshaffer
 *
 * Created on April 4, 2016, 10:23 AM
 */

#ifndef CLSKEYBOARDTOTEST_H
#define CLSKEYBOARDTOTEST_H

#include <vector>
#include <string>

#ifndef KB_MOD_5250
//////// TEMPORARY FOR LAYOUT
const int KB_MOD_5250 = 1;          //Standard 5250 Jaguar World Trade
const int KB_MOD_LEFTSHIFT = 2;    // Big left shift, no position 45
////////////////////////////////
#endif

class clsKeyboardToTest {
public:
    clsKeyboardToTest();
    clsKeyboardToTest(const clsKeyboardToTest& orig);
    virtual ~clsKeyboardToTest();
    
// FROM PARSE //////////////////
        void GetWSE(std::string);
    std::vector<std::string> parseline (std::string) ;
      std::string WSEPath;
////////////////////////////////
    
///////////  FROM KBDisply    /////////
    void DisplayKeyboard(int);
    struct position { int X_location; int Y_location; };
    position keyposition[134];
    void DisplayFramework(void);
    void ClearKBArea(void);
    void DisplayMain(void);
//////      END KBDisply     //////////    
    
private:
    int KeyboardLayout;
 /////////     KBDISPLAY    ///////////
    void ShowKB_Standard_5250(void);
    void Positions_Standard (void);
////////    END KBDISPLAY     ///////
};

#endif /* CLSKEYBOARDTOTEST_H */

