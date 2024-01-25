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

   /// <summary>
   /// Read one student record frome the opened student records file
   /// </summary>
   /// <param name="mark">, points to one StMark structure</param>
   /// <returns>true if the record is read successfuly</returns>
   bool readMark(StMark* mark);

   /// <summary>
   /// fills an array of StMark array with the records read from the opened student records file up to MAX_NO_RECS constant integer value.
   /// </summary>
   /// <param name="marks">, array of student marks</param>
   /// <returns>the actual number of records read.</returns>
   int readMarks(StMark* marks);
}

#endif // !SENECA_FILE_H