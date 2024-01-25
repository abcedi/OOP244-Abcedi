/***********************************************************************
// Workshop 1 # p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	 winter 2024
// Author Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "StMark.h"
using namespace std;
using namespace seneca;
int main() {
   bool done = false;
   char filename[256];
   while (!done) {
      cout << "Enter filename to generate report for or 'X' to exit:\n> ";
      cin >> filename;
      if ((filename[0] == 'X' || filename[0] == 'x') && filename[1] == 0) {
         done = true;
      }
      else if (!printReport(filename)) {
         cout << "Can not open \"" << filename << "\"!" << endl;
      }
   }
   cout << "Exiting program!" << endl;
   return 0;
}