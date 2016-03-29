/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clsKBDisplay.h
 * Author: dshaffer
 *
 * Created on March 9, 2016, 8:23 AM
 */

#ifndef CLSKBDISPLAY_H
#define CLSKBDISPLAY_H

const int KB_MOD_5250 = 1;          //Standard 5250 Jaguar World Trade
const int KB_MOD_LEFTSHIFT = 2;    // Big left shift, no position 45

class clsKBDisplay {
public:
    clsKBDisplay();
    clsKBDisplay(const clsKBDisplay& orig);
    virtual ~clsKBDisplay();
    
    void DisplayKeyboard(int);
    struct position { int X_location; int Y_location; };
    position keyposition[134];
    void Show_Header(void);
private:
    int KeyboardLayout;
    
    void ShowKB_Standard_5250(void);
    void Positions_Standard (void);

};

#endif /* CLSKBDISPLAY_H */

