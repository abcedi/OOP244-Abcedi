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
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
   struct Utils {
      int getInt( );
      void getCstr( char* str, size_t len );
   };
   extern Utils ut; // protoype for the ut inside Utils.cpp

   /// <summary>
   /// Tries to open the student records file using the file name.
   /// </summary>
   /// <param name="fname">, name of the file</param>
   /// <returns>ture if file is opened successfuly or false if not</returns>
   bool openFile(const char* fname);

   /// <summary>
   /// closes the student records file.
   /// </summary>
   void closeFile();

   
}
#endif // !SENECA_UTILS_H


