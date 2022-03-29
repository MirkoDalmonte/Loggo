/*
 * Loggo v1.2 -> loggo.cpp
 *
 * Copyright (C) Mirko Dalmonte <dal.mirko@gmail.com>
 *
 * SPDX-License-Identifier:   GPL-3.0-or-later
 */


#include "loggo.h"

std::string Loggo::get_time()
{
  time_t _tm = time(NULL);
  struct tm * timeptr = localtime ( &_tm );
  static char result[20];
  if (!Loggo::lEndian) {
    sprintf(result, "%d/%.2d/%.2d %.2d:%.2d:%.2d",
    1900 + timeptr->tm_year,
    timeptr->tm_mon+1,
    timeptr->tm_mday,
    timeptr->tm_hour,
    timeptr->tm_min,
    timeptr->tm_sec);
  } else {
    sprintf(result, "%.2d/%.2d/%d %.2d:%.2d:%.2d",
    timeptr->tm_mday,    
    timeptr->tm_mon+1,
    1900 + timeptr->tm_year, 
    timeptr->tm_hour,
    timeptr->tm_min,
    timeptr->tm_sec);
  }
  return result;
}

void Loggo::write( const std::string &text )
{   
  if(Loggo::isLogging() && Loggo::isOpen()) {
    Loggo::log_file << " " << get_time() << " >> " << text << std::endl;
  }
}

void Loggo::stop()
{
  if(Loggo::isLogging()) {
    Loggo::logging = false;
    Loggo::log_file << Loggo::decor() << " STOPPED @ " 
    << Loggo::get_time() << " " << Loggo::decor() << std::endl;
    Loggo::close();
  }
}

void Loggo::start()
{
  if(!Loggo::isLogging()) {
  	Loggo::open();
    Loggo::logging = true;
    Loggo::log_file << Loggo::decor() << " STARTED @ " 
    << Loggo::get_time() << " " << Loggo::decor() << std::endl;
  }
}

void Loggo::close()
{ 
  Loggo::logging = false;
  if (Loggo::isOpen()) {
     Loggo::log_file.close();
     }
}

void Loggo::open()
{ 
  if (!Loggo::isOpen()) {
     const char *filenamep = Loggo::filename.c_str();
     Loggo::log_file.open(filenamep, std::ios_base::out 
                  | std::ios_base::app );
     }
}

std::string Loggo::decor()
{
  std::string str ="";
  for (int i=0; i<Loggo::numDec; i++){
    str = str+Loggo::dec;
  }
  return str;     
}
