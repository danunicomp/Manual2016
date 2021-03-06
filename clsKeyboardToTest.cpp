/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clsKeyboardToTest.cpp
 * Author: dshaffer
 * 
 * Created on April 4, 2016, 10:23 AM
 */

#include <ncurses.h>
#include <sstream>
#include <unistd.h> // for usleep
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsKeyboardToTest.h"

clsKeyboardToTest::clsKeyboardToTest() {
}

clsKeyboardToTest::clsKeyboardToTest(const clsKeyboardToTest& orig) {
}

clsKeyboardToTest::~clsKeyboardToTest() {
}
using namespace std;

void clsKeyboardToTest::DisplayKeyboard(int model) {
    switch (model) {
        case KB_MOD_5250:
            ShowKB_Standard_5250();
            Positions_Standard();
           //   getch();
            break;
         case KB_MOD_LEFTSHIFT:
             break;
         default:
             break;
    }
}

void clsKeyboardToTest::ClearKBArea(void) {
     initscr();
    noecho();
    ////////////////////
    for (int y=1; y<=16; ++y) {
        for (int x=0; x<80; ++x) {
            move(y,x);
            addch(' '); 
        }
    }
    ////////////////////
    refresh();   
    endwin();   
}

void clsKeyboardToTest::DisplayFramework(void) {
    initscr();
    noecho();
    
////////////////////
    start_color();
    init_pair(10, COLOR_BLACK, COLOR_WHITE); //Black text, white background
    init_pair(9, COLOR_WHITE, COLOR_BLACK );    // white text, black background
    attron(COLOR_PAIR(10));
    //refresh();
    
    move(0,0);
    for (int x=1; x<=80; ++x) {
       addch(' ');      // clear top row
    }
    refresh();
    std::string uniheader = "Unicomp Manual Test";
    int centerx;
    centerx = (80-uniheader.length())/2;
    move( 0, centerx);
    printw ("%s",uniheader.c_str() );
    
    attron(COLOR_PAIR(10));
    move (17,0);
        for (int x=1; x<=80; ++x) {
       addch(' ');      // clear top row
    }
    
    move (28,0);
    for (int x=1; x<=80; ++x) {
       addch(' ');      // clear top row
    }    
    //printw("%i", KeyboardLayout);
   
////////////////////
    refresh();   
    endwin();    
}

void clsKeyboardToTest::ShowKB_Standard_5250(void) {
 //   this->DisplayFramework();
    initscr();
    noecho();

    int StartX = 12;
    int StartY = 0;

    move(0,0);
    
    attron(COLOR_PAIR(1));
    
    // START TOP FUNCTION KEYS    
    move(StartY+1, StartX+8);
    addch(ACS_ULCORNER); 
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_URCORNER) ;
    move(StartY+2, StartX+8);
    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');
    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');
    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');
    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');
    addch(ACS_VLINE);
     move(StartY+3, StartX+8);
    addch(ACS_LTEE);
    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);
    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);
    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_PLUS);    addch(ACS_HLINE);addch(ACS_RTEE);
    
    move(StartY+4, StartX+8);
    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');
    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');
    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');    addch(ACS_VLINE); addch(' ');
    addch(ACS_VLINE);
    
    move(StartY+5, StartX+8);
    addch(ACS_LLCORNER); 
    addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_HLINE); addch(ACS_BTEE) ;
    addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_HLINE); addch(ACS_BTEE) ;
    addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_HLINE); addch(ACS_BTEE) ;
    addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_HLINE); addch(ACS_BTEE) ;
    addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_HLINE); addch(ACS_BTEE) ;
    addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_HLINE); addch(ACS_LRCORNER) ;
    
// END TOP FUNCTION KEYS    
    
// START LEFT FUNCTIOn KEYS    
    move(StartY+6, StartX);
    addch(ACS_ULCORNER); addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_URCORNER);  
    move(StartY+7, StartX);
    addch(ACS_VLINE); addch(' '); addch(ACS_VLINE); addch(' '); addch(ACS_VLINE);                  
    move(StartY+8, StartX);
    addch(ACS_LTEE); addch(ACS_HLINE); addch(ACS_PLUS); addch(ACS_HLINE); addch(ACS_RTEE); 
    move(StartY+9, StartX);
    addch(ACS_VLINE); addch(' '); addch(ACS_VLINE); addch(' '); addch(ACS_VLINE);                 
    move(StartY+10, StartX);
    addch(ACS_LTEE); addch(ACS_HLINE); addch(ACS_PLUS); addch(ACS_HLINE); addch(ACS_RTEE); 
    move(StartY+11, StartX);
    addch(ACS_VLINE); addch(' '); addch(ACS_VLINE); addch(' '); addch(ACS_VLINE);               
    move(StartY+12, StartX);
    addch(ACS_LTEE); addch(ACS_HLINE); addch(ACS_PLUS); addch(ACS_HLINE); addch(ACS_RTEE); 
    move(StartY+13, StartX);
    addch(ACS_VLINE); addch(' '); addch(ACS_VLINE); addch(' '); addch(ACS_VLINE);                   
    move(StartY+14, StartX);
    addch(ACS_LTEE); addch(ACS_HLINE); addch(ACS_PLUS); addch(ACS_HLINE); addch(ACS_RTEE); 
    move(StartY+15, StartX);
    addch(ACS_VLINE); addch(' '); addch(ACS_VLINE); addch(' '); addch(ACS_VLINE);                   
    move(StartY+16, StartX);
    addch(ACS_LLCORNER); addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_HLINE); addch(ACS_LRCORNER);  
//END LEFT FUNCTIOn KEYS    
    
    
// BEGIN TOP ROW
    move(StartY+6, StartX+6);
    addch(ACS_ULCORNER); 
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE); addch(ACS_TTEE); addch(ACS_HLINE); addch(ACS_TTEE) ;
    addch(ACS_HLINE);addch(ACS_TTEE);   addch(ACS_HLINE);   addch(ACS_HLINE);
    addch(ACS_HLINE);addch(ACS_URCORNER) ;
    
    move(StartY+7, StartX+6);
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' ');      
     addch(ACS_VLINE);  addch(' '); 
     addch(ACS_VLINE);  addch(' ');addch(' ');addch(' ');
     addch(ACS_VLINE);
     
     // START QWERTY ROW
     move(StartY+8, StartX+6);
     addch(ACS_LTEE);  addch(ACS_HLINE); addch(ACS_BTEE); addch(ACS_TTEE);
     addch(ACS_BTEE);  addch(ACS_TTEE);  addch(ACS_BTEE); addch(ACS_TTEE);
     addch(ACS_BTEE);  addch(ACS_TTEE);  addch(ACS_BTEE); addch(ACS_TTEE);     
     addch(ACS_BTEE);  addch(ACS_TTEE);  addch(ACS_BTEE); addch(ACS_TTEE);
     addch(ACS_BTEE);  addch(ACS_TTEE);  addch(ACS_BTEE); addch(ACS_TTEE);
     addch(ACS_BTEE);  addch(ACS_TTEE);  addch(ACS_BTEE); addch(ACS_TTEE);     
     addch(ACS_BTEE);  addch(ACS_TTEE);  addch(ACS_BTEE); addch(ACS_TTEE);   
    addch(ACS_HLINE);  addch(ACS_HLINE); addch(ACS_RTEE);
    
            //  QWERTY MIDDLE
   
     move(StartY+9, StartX+6);
     addch(ACS_VLINE);
    addch(' '); addch(' ');
     addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);
     addch(' '); addch(ACS_VLINE);     
      addch(' '); addch(' ');addch(ACS_VLINE);  
     // END QWERTY
      
 // BEGIN ASDF
    move(StartY+10, StartX+6);
    addch(ACS_LTEE);
    addch(ACS_HLINE);addch(ACS_HLINE);
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE); 
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE); 
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_TTEE); 
    addch(ACS_BTEE);addch(ACS_TTEE);
    addch(ACS_BTEE);addch(ACS_URCORNER) ;
    addch(' '); addch(ACS_VLINE);
 
 // MIDDLE ASDF     
     move(StartY+11, StartX+6);
     addch(ACS_VLINE);
     addch(' ');addch(' ');addch(' ');
     addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);
     addch(' ');addch(ACS_VLINE);

// BOTTOM ASDF     
     move(StartY+12, StartX+6);
    addch(ACS_LTEE);      
    addch(ACS_HLINE);   addch(ACS_HLINE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_HLINE);   addch(ACS_BTEE);
    addch(ACS_HLINE);   addch(ACS_RTEE);
 
    // BOTTOM ZXCV ROW
    move(StartY+13, StartX+6);
    addch(ACS_VLINE);
    addch(' ');  addch(' ');
    addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' '); addch(ACS_VLINE);
    addch(' ');addch(' ');addch(' ');addch(' '); addch(ACS_VLINE);
     
     
     //////
     move(StartY+14, StartX+6);
    addch(ACS_LTEE);    addch(ACS_HLINE);   addch(ACS_HLINE);
    addch(ACS_BTEE);    addch(ACS_TTEE);    addch(ACS_BTEE);
    addch(ACS_TTEE);    addch(ACS_BTEE);    addch(ACS_HLINE);
    addch(ACS_PLUS);    addch(ACS_HLINE);   addch(ACS_BTEE);     
    addch(ACS_HLINE);   addch(ACS_BTEE);    addch(ACS_HLINE);
    addch(ACS_BTEE);    addch(ACS_HLINE);   addch(ACS_BTEE);     
    addch(ACS_HLINE);   addch(ACS_BTEE);    addch(ACS_HLINE);
    addch(ACS_BTEE);    addch(ACS_TTEE);    addch(ACS_BTEE);          
    addch(ACS_HLINE);   addch(ACS_PLUS);    addch(ACS_HLINE);
    addch(ACS_TTEE);    addch(ACS_HLINE);   addch(ACS_HLINE);
    addch(ACS_RTEE);
        
     move(StartY+15, StartX+6);
    addch(ACS_VLINE);
    addch(' '); addch(' ');  addch(' ');   // CONTROL
    addch(ACS_VLINE);
    addch(' ');
    addch(ACS_VLINE);
    addch(' '); addch(' '); // ALT
    addch(ACS_VLINE);
    addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');addch(' ');
    addch(ACS_VLINE);
    addch(' ');addch(' ');addch(ACS_VLINE);
    addch(' ');addch(ACS_VLINE);
    addch(' ');addch(' ');addch(ACS_VLINE);
         
     
    move(StartY+16, StartX+6);
    addch(ACS_LLCORNER);        
    addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);
    addch(ACS_LRCORNER);
    addch(' '); 
    addch(ACS_LLCORNER);
    addch(ACS_HLINE);
    addch(ACS_HLINE);
    addch(ACS_BTEE);
    addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);
    addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);
    addch(ACS_BTEE);
    addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_LRCORNER);
    addch(' '); 
    addch(ACS_LLCORNER);
    addch(ACS_HLINE);addch(ACS_HLINE);
    addch(ACS_LRCORNER);
      
   // END MAIN QWERTY SECTION   
      
   // BEGIN CENTER BLOCK
    move(StartY+6, StartX+38);
    addch(ACS_ULCORNER);
    addch(ACS_HLINE);    addch(ACS_TTEE);
    addch(ACS_HLINE);    addch(ACS_TTEE);    
    addch(ACS_HLINE);    addch(ACS_URCORNER);
   
    move(StartY+7, StartX+38);
    addch(ACS_VLINE);
    addch(' '); 
    addch(ACS_VLINE);
    addch(' '); 
    addch(ACS_VLINE);
    addch(' '); 
    addch(ACS_VLINE);    

    move(StartY+8, StartX+38);
    addch(ACS_LTEE);
    addch(ACS_HLINE);    addch(ACS_PLUS);
    addch(ACS_HLINE);    addch(ACS_PLUS);
    addch(ACS_HLINE);addch(ACS_RTEE);
    
    move(StartY+9, StartX+38);
    addch(ACS_VLINE);
    addch(' '); 
    addch(ACS_VLINE);
    addch(' '); 
    addch(ACS_VLINE);
    addch(' '); 
    addch(ACS_VLINE); 
    
    
    move(StartY+10, StartX+38);
    addch(ACS_LLCORNER);
    addch(ACS_HLINE);    addch(ACS_PLUS);
    addch(ACS_HLINE);    addch(ACS_PLUS);    
    addch(ACS_HLINE);    addch(ACS_LRCORNER);
    
    // END CENTER BLOCK
    
   // BEGIN ARROWS
    move(StartY+11, StartX+40);
    addch(ACS_VLINE);
    addch(' '); 
    addch(ACS_VLINE);

    move(StartY+12, StartX+38);
    addch(ACS_ULCORNER);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);   
    addch(ACS_PLUS); 
    addch(ACS_HLINE); 
    addch(ACS_URCORNER);
  
    move(StartY+13, StartX+38);
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);

    move(StartY+14, StartX+38);
    addch(ACS_LLCORNER);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_LRCORNER);

    move(StartY+15, StartX+40);
    addch(ACS_VLINE);
    addch(' ');   // down arrow
    addch(ACS_VLINE);

    move(StartY+16, StartX+40);
    addch(ACS_LLCORNER); 
    addch(ACS_HLINE);
    addch(ACS_LRCORNER);

// END ARROWS

// BEGIN NUMPAD
    move(StartY+6, StartX+46);
    addch(ACS_ULCORNER); 
    addch(ACS_HLINE); addch(ACS_TTEE);
    addch(ACS_HLINE); addch(ACS_TTEE);
    addch(ACS_HLINE); addch(ACS_TTEE);
    addch(ACS_HLINE); addch(ACS_URCORNER);

    move(StartY+7, StartX+46);
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);
 
    move(StartY+8, StartX+46);
    addch(ACS_LTEE);    addch(ACS_HLINE);
    addch(ACS_PLUS);    addch(ACS_HLINE);
    addch(ACS_PLUS);    addch(ACS_HLINE);
    addch(ACS_PLUS);    addch(ACS_HLINE);
    addch(ACS_RTEE);

    move(StartY+9, StartX+46);
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);

    move(StartY+10, StartX+46);
    addch(ACS_LTEE);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_RTEE);

    move(StartY+11, StartX+46);
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);

     move(StartY+12, StartX+46);
    addch(ACS_LTEE);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_RTEE);

    move(StartY+13, StartX+46);
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);  addch(' '); 
    addch(ACS_VLINE);

    move(StartY+14, StartX+46);
    addch(ACS_LTEE);
    addch(ACS_HLINE);
    addch(ACS_BTEE);
    addch(ACS_HLINE);
    addch(ACS_PLUS);
    addch(ACS_HLINE);
    addch(ACS_RTEE);
    addch(' '); 
    addch(ACS_VLINE); 


    move(StartY+15, StartX+46);
    addch(ACS_VLINE);  addch(' '); addch(' '); addch(' '); 
    addch(ACS_VLINE);  addch(' ');
    addch(ACS_VLINE);   addch(' ');
    addch(ACS_VLINE);  

    move(StartY+16, StartX+46);
    addch(ACS_LLCORNER);
    addch(ACS_HLINE);addch(ACS_HLINE);addch(ACS_HLINE);
    addch(ACS_BTEE);
    addch(ACS_HLINE);
    addch(ACS_BTEE);
    addch(ACS_HLINE);
    addch(ACS_LRCORNER);

// END NUMPAD

// END KEYBOARD

// TEST SHIT

// ///////

    refresh();
    endwin();    
    
}

void clsKeyboardToTest::Positions_Standard(void) {
   
    /* hardcodes poisition of each key
    * ultimatly this will be a config file.
    */
    
    keyposition[1].X_location = 19;     keyposition[1].Y_location = 7;
    keyposition[2].X_location = 21;     keyposition[2].Y_location = 7;
    keyposition[3].X_location = 23;     keyposition[3].Y_location = 7;
    keyposition[4].X_location = 25;     keyposition[4].Y_location = 7;
    keyposition[5].X_location = 27;     keyposition[5].Y_location = 7;
    keyposition[6].X_location = 29;     keyposition[6].Y_location = 7;
    keyposition[7].X_location = 31;     keyposition[7].Y_location = 7;
    keyposition[8].X_location = 33;     keyposition[8].Y_location = 7;
    keyposition[9].X_location = 35;     keyposition[9].Y_location = 7;
    keyposition[10].X_location = 37;    keyposition[10].Y_location = 7;
    keyposition[11].X_location = 39;    keyposition[11].Y_location = 7;
    keyposition[12].X_location = 41;    keyposition[12].Y_location = 7;
    keyposition[13].X_location = 43;    keyposition[13].Y_location = 7;
    keyposition[14].X_location = 45;    keyposition[14].Y_location = 7;     // not usually used 
    keyposition[15].X_location = 47;    keyposition[15].Y_location = 7;

    keyposition[16].X_location = 19;    keyposition[16].Y_location = 9;                                                        
    keyposition[17].X_location = 22;    keyposition[17].Y_location = 9;
    keyposition[18].X_location = 24;    keyposition[18].Y_location = 9;
    keyposition[19].X_location = 26;    keyposition[19].Y_location = 9;
    keyposition[20].X_location = 28;    keyposition[20].Y_location = 9;
    keyposition[21].X_location = 30;    keyposition[21].Y_location = 9;
    keyposition[22].X_location = 32;    keyposition[22].Y_location = 9;
    keyposition[23].X_location = 34;    keyposition[23].Y_location = 9;
    keyposition[24].X_location = 36;    keyposition[24].Y_location = 9;
    keyposition[25].X_location = 38;    keyposition[25].Y_location = 9;
    keyposition[26].X_location = 40;    keyposition[26].Y_location = 9;
    keyposition[27].X_location = 42;    keyposition[27].Y_location = 9;
    keyposition[28].X_location = 44;    keyposition[28].Y_location = 9;    
    keyposition[29].X_location = 47;    keyposition[29].Y_location = 9;     // not usually used
    
    keyposition[30].X_location = 19;    keyposition[30].Y_location = 11;                                                        
    keyposition[31].X_location = 23;    keyposition[31].Y_location = 11;
    keyposition[32].X_location = 25;    keyposition[32].Y_location = 11;
    keyposition[33].X_location = 27;    keyposition[33].Y_location = 11;
    keyposition[34].X_location = 29;    keyposition[34].Y_location = 11;
    keyposition[35].X_location = 31;    keyposition[35].Y_location = 11;
    keyposition[36].X_location = 33;    keyposition[36].Y_location = 11;
    keyposition[37].X_location = 35;    keyposition[37].Y_location = 11;
    keyposition[38].X_location = 37;    keyposition[38].Y_location = 11;
    keyposition[39].X_location = 39;    keyposition[39].Y_location = 11;
    keyposition[40].X_location = 41;    keyposition[40].Y_location = 11;
    keyposition[41].X_location = 43;    keyposition[41].Y_location = 11;
    keyposition[42].X_location = 45;    keyposition[42].Y_location = 11;        
    
    keyposition[43].X_location = 47;    keyposition[43].Y_location = 11;      

    keyposition[44].X_location = 19;    keyposition[44].Y_location = 13;                                                        
    keyposition[45].X_location = 22;    keyposition[45].Y_location = 13;
    keyposition[46].X_location = 24;    keyposition[46].Y_location = 13;
    keyposition[47].X_location = 26;    keyposition[47].Y_location = 13;
    keyposition[48].X_location = 28;    keyposition[48].Y_location = 13;
    keyposition[49].X_location = 30;    keyposition[49].Y_location = 13;
    keyposition[50].X_location = 32;    keyposition[50].Y_location = 13;
    keyposition[51].X_location = 34;    keyposition[51].Y_location = 13;
    keyposition[52].X_location = 36;    keyposition[52].Y_location = 13;
    keyposition[53].X_location = 38;    keyposition[53].Y_location = 13;
    keyposition[54].X_location = 40;    keyposition[54].Y_location = 13;
    keyposition[55].X_location = 42;    keyposition[55].Y_location = 13;
    keyposition[56].X_location = 44;    keyposition[56].Y_location = 13;    // not normally used    
    keyposition[57].X_location = 47;    keyposition[57].Y_location = 13;            
    
    keyposition[58].X_location = 19;    keyposition[58].Y_location = 15;            
    keyposition[60].X_location = 25;    keyposition[60].Y_location = 15;            
    keyposition[61].X_location = 34;    keyposition[61].Y_location = 15;            
    keyposition[62].X_location = 42;    keyposition[62].Y_location = 15;            
    keyposition[64].X_location = 48;    keyposition[64].Y_location = 15;
    
    keyposition[65].X_location = 15;    keyposition[65].Y_location = 7;   
    keyposition[66].X_location = 15;    keyposition[66].Y_location = 9;  
    keyposition[67].X_location = 15;    keyposition[67].Y_location = 11;  
    keyposition[68].X_location = 15;    keyposition[68].Y_location = 13;  
    keyposition[69].X_location = 15;    keyposition[69].Y_location = 15;  

    keyposition[70].X_location = 13;    keyposition[70].Y_location = 7;   
    keyposition[71].X_location = 13;    keyposition[71].Y_location = 9;  
    keyposition[72].X_location = 13;    keyposition[72].Y_location = 11;  
    keyposition[73].X_location = 13;    keyposition[73].Y_location = 13;  
    keyposition[74].X_location = 13;    keyposition[74].Y_location = 15;

    keyposition[75].X_location = 51;    keyposition[75].Y_location = 7;
    keyposition[76].X_location = 51;    keyposition[76].Y_location = 9;

    keyposition[78].X_location = 51;    keyposition[78].Y_location = 13;

    keyposition[80].X_location = 53;    keyposition[80].Y_location = 7;
    keyposition[81].X_location = 53;    keyposition[81].Y_location = 9;
    keyposition[82].X_location = 53;    keyposition[82].Y_location = 11;
    keyposition[83].X_location = 53;    keyposition[83].Y_location = 13;
    keyposition[84].X_location = 53;    keyposition[84].Y_location = 15;
    
    keyposition[85].X_location = 55;    keyposition[85].Y_location = 7;
    keyposition[86].X_location = 55;    keyposition[86].Y_location = 9;
    keyposition[88].X_location = 55;    keyposition[88].Y_location = 13;

    keyposition[90].X_location = 59;    keyposition[90].Y_location = 7;    
    keyposition[91].X_location = 59;    keyposition[91].Y_location = 9; 
    keyposition[92].X_location = 59;    keyposition[92].Y_location = 11; 
    keyposition[93].X_location = 59;    keyposition[93].Y_location = 13;     
    keyposition[94].X_location = 59;    keyposition[94].Y_location = 15;     // not used normally
    
    keyposition[95].X_location = 61;    keyposition[95].Y_location = 7;     
    keyposition[96].X_location = 61;    keyposition[96].Y_location = 9;     
    keyposition[97].X_location = 61;    keyposition[97].Y_location = 11;         
    keyposition[98].X_location = 61;    keyposition[98].Y_location = 13;     
    
    keyposition[99].X_location = 61;    keyposition[99].Y_location = 15;
    
    keyposition[100].X_location = 63;    keyposition[100].Y_location = 7;         
    keyposition[101].X_location = 63;    keyposition[101].Y_location = 9;         
    keyposition[102].X_location = 63;    keyposition[102].Y_location = 11;             
    keyposition[103].X_location = 63;    keyposition[103].Y_location = 13;         
    keyposition[104].X_location = 63;    keyposition[104].Y_location = 15;
    
    keyposition[105].X_location = 65;    keyposition[105].Y_location = 7;             
    keyposition[106].X_location = 65;    keyposition[106].Y_location = 9;             
    keyposition[107].X_location = 65;    keyposition[107].Y_location = 11;             
    keyposition[108].X_location = 65;    keyposition[108].Y_location = 13;      
    keyposition[109].X_location = 65;    keyposition[109].Y_location = 15;     // not used 

    keyposition[110].X_location = 21;    keyposition[110].Y_location = 4;  
    keyposition[111].X_location = 23;    keyposition[111].Y_location = 4;  
    keyposition[112].X_location = 25;    keyposition[112].Y_location = 4;  
    keyposition[113].X_location = 27;    keyposition[113].Y_location = 4;  
    keyposition[114].X_location = 29;    keyposition[114].Y_location = 4;  
    keyposition[115].X_location = 31;    keyposition[115].Y_location = 4;  
    keyposition[116].X_location = 33;    keyposition[116].Y_location = 4;  
    keyposition[117].X_location = 35;    keyposition[117].Y_location = 4;  
    keyposition[118].X_location = 37;    keyposition[118].Y_location = 4;  
    keyposition[119].X_location = 39;    keyposition[119].Y_location = 4;  
    keyposition[120].X_location = 41;    keyposition[120].Y_location = 4;  
    keyposition[121].X_location = 43;    keyposition[121].Y_location = 4;      

    keyposition[122].X_location = 21;    keyposition[122].Y_location = 2;  
    keyposition[123].X_location = 23;    keyposition[123].Y_location = 2;  
    keyposition[124].X_location = 25;    keyposition[124].Y_location = 2;  
    keyposition[125].X_location = 27;    keyposition[125].Y_location = 2;  
    keyposition[126].X_location = 29;    keyposition[126].Y_location = 2;  
    keyposition[127].X_location = 31;    keyposition[127].Y_location = 2;  
    keyposition[128].X_location = 33;    keyposition[128].Y_location = 2;  
    keyposition[129].X_location = 35;    keyposition[129].Y_location = 2;  
    keyposition[130].X_location = 37;    keyposition[130].Y_location = 2;  
    keyposition[131].X_location = 39;    keyposition[131].Y_location = 2;  
    keyposition[132].X_location = 41;    keyposition[132].Y_location = 2;  
    keyposition[133].X_location = 43;    keyposition[133].Y_location = 2;         
}

void clsKeyboardToTest::DisplayMain(void) {
    
    initscr();
    noecho();
    start_color();
    init_pair(10, COLOR_BLACK, COLOR_WHITE); //Black text, white background
    init_pair(9, COLOR_WHITE, COLOR_BLACK );    // white text, black background
    attron(COLOR_PAIR(9));
    ////////////////////
    
    move(0,0);
    addch(ACS_ULCORNER);
    for (int x=1; x<79; ++x) {
        move(0,x);
        addch(ACS_HLINE);
        move(18,x);
        addch(ACS_HLINE);
        move (28,x);
        addch(ACS_HLINE);
    }
    move(0,79);
    addch(ACS_URCORNER);
    
    // do sides of framework
    for (int y=1; y<=27; ++y) {
        move (y,0);
        addch(ACS_VLINE);
        move(y,79);
        addch(ACS_VLINE);
    }
    
    move(18,0);
    addch(ACS_LTEE);
    move(18, 79);
    addch(ACS_RTEE);
    
    move(28,0);
    addch(ACS_LLCORNER);
   
    move(28,79);
    addch(ACS_LRCORNER);
    
    // Header
    move(0,0);
    attron(COLOR_PAIR(10));
    for (int x=1; x<=80; ++x) {
       addch(' ');      // clear top row
    }
    std::string uniheader = "Unicomp Manual Test";
    int centerx;
    centerx = (80-uniheader.length())/2;
    move( 0, centerx);
    //printw ("%s",uniheader.c_str() );
    addstr(uniheader.c_str());
    ////////////////////
    refresh();   
    endwin();    
}

void clsKeyboardToTest::GetWSE(std::string WSEFileToCheck) {

    ifstream inputFile(WSEFileToCheck);
        if (inputFile.good()) {
            clsKeyboardToTest::WSEPath = WSEFileToCheck;
            cout << "Good WSE" << endl;
        }
        else {
            clsKeyboardToTest::WSEPath = "";
            cout << "BAD WSE" << endl;
            return;
        }         
    
        
 }

vector<string> clsKeyboardToTest::parseline (string testline) {
    
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