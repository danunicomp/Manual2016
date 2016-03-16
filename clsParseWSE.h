/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clsParseWSE.h
 * Author: dshaffer
 *
 * Created on March 15, 2016, 9:42 AM
 */

#ifndef CLSPARSEWSE_H
#define CLSPARSEWSE_H

#include <vector>
#include <string>

class clsParseWSE {
public:
    clsParseWSE();
    clsParseWSE(std::string);  //send path to WSE
    clsParseWSE(const clsParseWSE& orig);
    virtual ~clsParseWSE();
    void GetWSE(std::string);
    std::vector<std::string> parseline (std::string) ;
private:
    std::string WSEPath;
};

#endif /* CLSPARSEWSE_H */

