/***********************************************************************
OOP244 Workshop # p2: file tester program
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "file.h"
#include "StMark.h"
using namespace std;
using namespace seneca;
int main() {
   StMark m[MAX_NO_RECS];
   int recoredsRead = 0;
   if (openFile("group.csv")) {
      cout << "This should not happen!" << endl;
   }
   if (openFile("group1.csv")) {
      recoredsRead = readMarks(m);
      cout << "GROUP1: ....................." << endl;
      for (int i = 0; i < recoredsRead; i++) {
         cout << (i + 1) << ": " << m[i].name << " " << m[i].surname << " [" << m[i].mark << "]" << endl;
      }
      closeFile();
   }
   else{
      cout << "This should not happen!" << endl;
   }
   if (openFile("group2.csv")) {
      cout << "GROUP2: ....................." << endl;
      recoredsRead = readMarks(m);
      for (int i = 0; i < recoredsRead; i++) {
         cout << (i + 1) << ": " << m[i].name << " " << m[i].surname << " [" << m[i].mark << "]" << endl;
      }
      closeFile();
   }
   else {
      cout << "This should not happen!" << endl;
   }
return 0;
}


