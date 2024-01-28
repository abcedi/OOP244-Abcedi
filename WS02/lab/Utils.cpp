/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	main.cpp
// Version 1.0
//
// Author	Fardad Soleimanloo
// Description
// Helpful function utilities
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut; // 
   int Utils::getInt( ) {
      int val{};
      cin >> val;
      while ( cin.fail( ) ) {
         cout << "Invalid Int, retry\n> ";
         cin.clear( );
         cin.ignore( 12000, '\n' );
         cin >> val;
      }
      //cin.ignore( ); // only one character
      cin.ignore( 12000, '\n' );
      return val;
   }

   void Utils::getCstr( char* str, size_t len ) {
      cin.getline( str, len + 1 );
      while ( cin.fail( ) ) {
         cout << "Maximum " << len << " chars!, retry\n> ";
         cin.clear( );
         cin.ignore( 12000, '\n' );
         cin.getline( str, len + 1 );
      }
   }
   std::FILE* datafile = nullptr;
   bool openFile(const char* fname)
   {
       if (datafile != nullptr) closeFile();
       datafile = fopen(fname, "r");
       return datafile != nullptr;
   }

   void closeFile() {
       if (datafile) {
           fclose(datafile);
           datafile = nullptr;
       }
   }
   
}
