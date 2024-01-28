#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
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
}