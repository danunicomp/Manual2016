#include <cstdlib>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>
#include <unistd.h> // for usleep
#include <fstream>

#include "unicomp.h"
#include "clsKBDisplay.h"
#include "clsGetCodes.h"

using namespace std;

const string VERSION = "2.0.20160322.A";

struct scancode { int position; bool makebreak; vector<int> codesstream;  };
    
int main(int argc, char** argv) {
    clsKBDisplay ShowKeyboard;
    ShowKeyboard.DisplayKeyboard(KB_MOD_5250);
    usleep(100000);

    int x = 1;

    vector<scancode> codelist;
    vector<scancode> ParseWSE (void);
    
    codelist = ParseWSE();

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
        }
        if (codelist[i].codesstream == trimmedbuffer) {
            move(ShowKeyboard.keyposition[codelist[i].position].Y_location, ShowKeyboard.keyposition[codelist[i].position].X_location );    
            attron(COLOR_PAIR(3));
            addch(ACS_CKBOARD);    refresh();
            move(18,1);

            printw("Position %i good", codelist[i].position);
            refresh();
        } else {
            move(ShowKeyboard.keyposition[codelist[i].position].Y_location, ShowKeyboard.keyposition[codelist[i].position].X_location );    
            attron(COLOR_PAIR(2));
            addch(ACS_CKBOARD);    refresh();
            if (codelist[i].makebreak == 1) {   
                move(18,1);
                printw("Position %i MAKE FAIL", codelist[i].position);
                move(19,1);

                printw("Read: ");
                int tmp;
                for (tmp=0; tmp<6; ++tmp) {
                    printw("%i ", trimmedbuffer[tmp]);
                }
                move(20,1);
                printw("Expected: ");
                for (tmp=0; tmp<6; ++tmp) {
                    printw("%i ", codelist[i].codesstream[tmp]);
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
    }

    endwin(); 
    return 0;
}

#include "clsParseWSE.h"

vector<scancode> ParseWSE (void) {
    
   vector<scancode> codelist;
    scancode temp;
    
    clsParseWSE GetWSELayout ;

    string line;
    string filename = "/home/pi/manuall2/WSE_5250.txt";

    vector<string> a;

    try {
        ifstream inputFile(filename);
  
        while (getline(inputFile, line)) {
            if (line[0] != '#' && line[0] != '=') {
                a = GetWSELayout.parseline(line);

                temp.position = std::atoi(a.at(0).c_str());
                temp.makebreak = std::atoi(a.at(1).c_str());
                temp.codesstream.push_back(std::atoi(a.at(2).c_str()));
                temp.codesstream.push_back(std::atoi(a.at(3).c_str()));
                temp.codesstream.push_back(std::atoi(a.at(4).c_str()));
                temp.codesstream.push_back(std::atoi(a.at(5).c_str()));
                temp.codesstream.push_back(std::atoi(a.at(6).c_str()));
                temp.codesstream.push_back(std::atoi(a.at(7).c_str()));
                codelist.push_back(temp);
                temp.codesstream.clear();
            }
            a.clear();
        }
    } catch(...) {
        cout << "Problem opening file" << endl;
        return codelist;
    }
    return codelist;
}



