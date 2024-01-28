#ifndef SENECA_FILE_H
#define SENECA_FILE_H


#include <cstdio>
#include "StMark.h"

namespace seneca {
   const int MAX_NO_RECS = 1000;

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

#endif // !SENECA_FILE_H