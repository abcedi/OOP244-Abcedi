/***********************************************************************
OOP244 Workshop # p2: 
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
Abcedi Ilacas   2024/01/24      Workshop 1 part 2 (DIY)
***********************************************************************/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
namespace seneca {

   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark {
      char name[21];
      char surname[31];
      int mark;
   };

   bool printReport(const char* filename);

   void bubbleSort(StMark* studentArray, int size);

}
#endif // !SENECA_STMARK_H


