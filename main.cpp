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
#include "clsGetCodes.h"

using namespace std;

const string VERSION = "2.0.20160310.A";

/*
 * 
 */
int main(int argc, char** argv) {

    clsKBDisplay ShowKeyboard;
    ShowKeyboard.DisplayKeyboard(KB_MOD_5250);
    usleep(100000);
    
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

    ////////////////////////////////////////////
    // TEST GETTING BUFFER
    
    // sample codes
    struct scancode { int position; bool makebreak; vector<int> codesstream;  };
    //scancodes codelist[134];
    vector<scancode> codelist;
    scancode temp;
    
    temp.position = 122;
    temp.makebreak = 1;
    temp.codesstream.push_back(42);
    temp.codesstream.push_back(59);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();
    
    temp.position = 122;
    temp.makebreak = 0;
    temp.codesstream.push_back(170);
    temp.codesstream.push_back(187);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();
    
    temp.position = 123;
    temp.makebreak = 1;
    temp.codesstream.push_back(42);
    temp.codesstream.push_back(60);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();
    
    temp.position = 123;
    temp.makebreak = 0;
    temp.codesstream.push_back(170);
    temp.codesstream.push_back(188);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();
    
    temp.position = 124;
    temp.makebreak = 1;
    temp.codesstream.push_back(42);
    temp.codesstream.push_back(61);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();
    
    temp.position = 124;
    temp.makebreak = 0;
    temp.codesstream.push_back(170);
    temp.codesstream.push_back(189);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();    
    
    temp.position = 125;
    temp.makebreak = 1;
    temp.codesstream.push_back(42);
    temp.codesstream.push_back(62);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();
    
    temp.position = 125;
    temp.makebreak = 0;
    temp.codesstream.push_back(170);
    temp.codesstream.push_back(190);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();  

    temp.position = 126;
    temp.makebreak = 1;
    temp.codesstream.push_back(42);
    temp.codesstream.push_back(63);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();
    
    temp.position = 126;
    temp.makebreak = 0;
    temp.codesstream.push_back(170);
    temp.codesstream.push_back(191);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    temp.codesstream.push_back(0);
    codelist.push_back(temp);
    temp.codesstream.clear();     
    
    
 //   cout << codelist[0].position << endl;

        initscr();
    noecho();
        start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    
    // test to iterate thru test codelist
    int currentposition;
    clsGetCodes GetUnicode;
    std::vector<int> wholebuffer;
    vector<int> trimmedbuffer;
for (int i=0; i<codelist.size(); i++) {
     system("stty -echo");  
             move(ShowKeyboard.keyposition[codelist[i].position].Y_location, ShowKeyboard.keyposition[codelist[i].position].X_location );    
        attron(COLOR_PAIR(4));
             addch(ACS_CKBOARD);    refresh();
    wholebuffer = GetUnicode.GetUnicodeBuffer();
                  for (x=0; x<6; ++x)  {
                      trimmedbuffer.push_back(wholebuffer[x]);
                      // cout << wholebuffer[x] << "\t";
                  }
  //  move(20,0);
    if (codelist[i].codesstream == trimmedbuffer) {
        move(ShowKeyboard.keyposition[codelist[i].position].Y_location, ShowKeyboard.keyposition[codelist[i].position].X_location );    
        attron(COLOR_PAIR(3));
        addch(ACS_CKBOARD);    refresh();
        move(18,1);

        printw("Position %i good", codelist[i].position);
        refresh();
        //  cout << "Position: " << codelist[i].position << " GOOD" << endl;
    }
    else
    {
        move(ShowKeyboard.keyposition[codelist[i].position].Y_location, ShowKeyboard.keyposition[codelist[i].position].X_location );    
        attron(COLOR_PAIR(2));
        addch(ACS_CKBOARD);    refresh();
      //  cout << "Position: " << codelist[i].position << " BAD";
      //  cout << "   Expected: " << codelist[i].codesstream[0] << " " << codelist[i].codesstream[1]<< "   Read: " << trimmedbuffer[0] << " " << trimmedbuffer[1]<< " " << trimmedbuffer[2]<< " " << trimmedbuffer[3]<< " " << trimmedbuffer[4]<< " " << trimmedbuffer[5] << endl;
        if (codelist[i].makebreak == 1) {   
            move(18,1);
            printw("Position %i MAKE FAIL", codelist[i].position);
            move(19,1);

            printw("Read: ");
            int tmp;
            for (tmp=0; tmp<6; ++tmp) {
                printw("%i ", trimmedbuffer[tmp]);
                //addch(' ');
            }
            move(20,1);
            printw("Expected: ");
            for (tmp=0; tmp<6; ++tmp) {
                printw("%i ", codelist[i].codesstream[tmp]);
                //addch(' ');
            }            
            refresh();
               system("stty echo");
               GetUnicode.clean_up(GetUnicode.getfd(NULL));
               break;
            
        }
    }
                  wholebuffer.clear();
                  trimmedbuffer.clear();
            system("stty echo");
   // cout << codelist[i].position << endl;
}

        endwin(); 
    return 0;
    
 /*   
    clsGetCodes GetUnicode;
    std::vector<int> wholebuffer;
          int exits = 0;
        while(1 && exits < 3) {
              system("stty -echo");
            wholebuffer = GetUnicode.GetUnicodeBuffer();
            if (wholebuffer[0] == 45) ++exits;
            else exits = 0;
            for (x=0; x<6; ++x)  {
                cout << wholebuffer[x] << "\t";
            }
            if (wholebuffer[18] == 1999) {
                cout << "MAKE" << endl;
            }
            else if (wholebuffer[18] == 999) {
                cout << "BREAK" << endl << endl;
            }
            else {
                cout << endl;
            }
            wholebuffer.clear();
            system("stty echo");
//            free(wholebuffer)  ;
        }
   
  */ 
/*    
    initscr();
    noecho();
    
    for (x=1;x<=133; ++x) {
        move(ShowKeyboard.keyposition[order[x]].Y_location, ShowKeyboard.keyposition[order[x]].X_location );    
        addch(ACS_CKBOARD);
        usleep(100000);
         refresh();
    }
   
    endwin(); 
 */   
    
    return 0;
}

