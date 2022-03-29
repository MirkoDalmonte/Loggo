/*
 * Loggo v1.2 -> loggo.h
 *
 * Copyright (C) Mirko Dalmonte <dal.mirko@gmail.com>
 *
 * SPDX-License-Identifier:   GPL-3.0-or-later
 */


#ifndef LOGGO_H
#define LOGGO_H

#include <string.h>
#include <time.h>
#include <fstream>
#include <iostream>

    class Loggo
    { 

    public:  
      
       Loggo( std::string name) {
         this->filename = name;
       }
       Loggo( std::string name, bool endian) {
         this->filename = name;
         this->lEndian = endian;
       }
       Loggo( std::string name, bool endian, const std::string &text, int numb) {
         this->filename = name;
         this->lEndian = endian;
         this->dec = text;
         this->numDec = numb;
       }
       Loggo( std::string name, const std::string &text, int numb) {
         this->filename = name;
         this->dec = text;
         this->numDec = numb;
       }
       void start();
       void write( const std::string &text );
       void stop();
       bool isLogging() { return this->logging; }
       bool isOpen() { return this->log_file.is_open(); }

    private:
       std::string filename;
       std::ofstream log_file;
       std::string dec = "*";
       int numDec = 20;
       bool lEndian = false;
       bool logging = false;
       void close();
       void open();
       std::string decor();
       std::string get_time();
    };

#endif
