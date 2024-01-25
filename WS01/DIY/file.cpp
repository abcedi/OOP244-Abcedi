#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
#include "StMark.h"
using namespace std;
namespace seneca {
   std::FILE* datafile = nullptr;
   bool openFile(const char* fname)
   {
      if (datafile != nullptr) closeFile();
      datafile = fopen(fname, "r");
      return datafile != nullptr;
   }

   void closeFile(){
      if (datafile) {
         fclose(datafile);
         datafile = nullptr;
      }
   }

   bool readMark(StMark* markRec)
   {
      return fscanf(datafile, "%[^,],%[^,],%d\n", markRec->name, markRec->surname, &markRec->mark) == 3;
   }

   int readMarks(StMark* marks)
   {
      int cnt = 0;
      for (; cnt < MAX_NO_RECS && readMark(&marks[cnt]); cnt++);
      return cnt;
   }
}