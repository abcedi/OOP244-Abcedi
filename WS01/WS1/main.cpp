/***********************************************************************
Workshop 1: Compiling modular source code
File	w1p1.cpp
Version 1.0
Author	Fardad Soleimanloo  2241
Description:
   This provides some source code in a single file to break
   into modules and compile together

Revision History
-----------------------------------------------------------
Name            Date            Reason
Abcedi Ilacas   2024/01/20      Seperated into modules
***********************************************************************/
/*
Workshop 1: Compiling modular source code
Name: Abcedi Ilacas
Student number: 138180211
Email: ailacas1@myseneca.ca
Section: NAA
Date: 2024/01/20
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

#include "io.h"
#include "graph.h"

using namespace std;
using namespace seneca;

// Maximum number of samples in a graph
const int MAX_NO_OF_SAMPLES = 20;

// prints samples error message
void samplesFirst();

// SeneGraph program
int main() {
    int noOfSamples = 0;
    int samples[MAX_NO_OF_SAMPLES] = { 0 };
    bool done = false;
    labelLine(33, "Welcome to SeneGraph");
    while (!done) {
        switch (menu(noOfSamples)) {
        case 1:
            cout << "Enter number of available samples: ";
            noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
            break;
        case 2:
            if (noOfSamples == 0) {
                samplesFirst();
            }
            else {
                cout << "Please enter the sample values: " << endl;
                getSamples(samples, noOfSamples);
            }
            break;
        case 3:
            if (noOfSamples == 0) {
                samplesFirst();
            }
            else if (samples[0] == 0) {
                cout << "Samples missing. Please enter the sample values!" << endl;
            }
            else {
                printGraph(samples, noOfSamples, " SeneGraph ");
            }
            break;
        case 0:
            cout << "Thanks for using SeneGraph" << endl;
            done = true;
        }
    }
    return 0;
}

// prints samples error message
void samplesFirst() {
	cout << "Number of Samples must be set first!" << endl;
}