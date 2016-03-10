/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dshaffer
 *
 * Created on March 9, 2016, 8:22 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>
#include <unistd.h> // for usleep

#include "clsKBDisplay.h"

using namespace std;

const string VERSION = "2.0.20160309.A";

/*
 * 
 */
int main(int argc, char** argv) {

    clsKBDisplay ShowKeyboard;
    ShowKeyboard.DisplayKeyboard(KB_MOD_5250);
    
    int x = 1;
    int order[134] = {
        0,122,123,124,125,126,127,128,129,130,131,132,133,
        121,120,119,118,117,116,115,114,113,112,111,110,
        70,65,1,2,3,4,5,6,7,8,9,10,11,12,13,15, 75,80,85,   90,95,100,105,
        106,101,96,91,  86,81,76,   28,27,26,25,24,23,22,21,20,19,18,17,16, 66,71,
        72,67,  30,31,32,33,34,35,36,37,38,39,40,41,42,43,  82, 92,97,102,107,
        108,103,98,93,  88,83,78,   57,55,54,53,52,51,50,49,48,47,46,45,44, 68,73,
        74,69,  58,60,61,62,64, 84, 99,104
    };
    
    initscr();
    noecho();
    
    for (x=1;x<=133; ++x) {
        move(ShowKeyboard.keyposition[order[x]].Y_location, ShowKeyboard.keyposition[order[x]].X_location );    
        addch(ACS_CKBOARD);
        usleep(100000);
         refresh();
    }
   
    endwin(); 
    
    
    return 0;
}

