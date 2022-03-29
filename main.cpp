/*
 * Loggo Example-> main.cpp
 *
 * Copyright (C) Mirko Dalmonte <dal.mirko@gmail.com>
 *
 * SPDX-License-Identifier:   GPL-3.0-or-later
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include "loggo.h"

	// File name + default format Date ex. 2022/03/28 + default "*" + default 20
Loggo *myLog1 = new Loggo("log1_file.txt");
// File name + Little-endian Date ex. 28/03/2022 + default "*" + default 20
Loggo *myLog2 = new Loggo("log2_file.txt", true);
// File name + default format Date + decoration "#" + decoration number 15
Loggo *myLog3 = new Loggo("log3_file.txt", "#", 15);
// File name + Little-endian Date ex. 28/03/2022 + decoration "~" + decoration number 1
Loggo *myLog4 = new Loggo("log4_file.txt", true, "~", 1);

int main(int argc,char* argv[]) {

	std::cout << std::endl << "************** Loggo  Example **************" << std::endl;
	std::cout << std::endl << "-> 4 Loggo instances created" << std::endl;
	myLog1->start();
	std::cout << "-> Log1 started ok"<< std::endl;
	myLog2->start();
	std::cout << "-> Log2 started ok"<< std::endl;
    myLog3->start();
    std::cout << "-> Log3 started ok"<< std::endl;
   
	for (int i=1; i<=16; i++) {
		sleep(1); 
		std::string numb = std::to_string(i);
		myLog1->write("Log1 Running..(" + numb + ")");
        myLog2->write("Log2 Running..(" + numb + ")");
        myLog3->write("Log3 Running..(" + numb + ")");
        myLog4->write("Log4 Running..(" + numb + ")");
        if (i==2) { myLog4->start(); std::cout << "-> Log4 started ok @" << numb << std::endl; }
        else if (i==4) { myLog1->stop(); std::cout << "-> Log1 stopped ok @" << numb << std::endl; }
        else if (i==6) { myLog2->stop(); std::cout << "-> Log2 stopped ok @" << numb << std::endl; }
        else if (i==8) { myLog3->stop(); std::cout << "-> Log3 stopped ok @" << numb << std::endl; }
        else if (i==10) { myLog4->stop(); myLog3->start(); std::cout << "-> Log4 stopped & Log3 started ok @" << numb<< std::endl; }
        else if (i==12) { myLog3->stop(); std::cout << "-> Log3 stopped ok @" << numb << std::endl; }
        else if (i==14) { myLog1->start(); std::cout << "-> Log1 started ok @" << numb << std::endl; }
        else if (i==16) { myLog1->stop(); std::cout << "-> Log1 stopped ok @" << numb << std::endl; }
    }
    std::cout << std::endl << "-> Done! See the log files in the project folder" << std::endl << std::endl;
return 0;
}
