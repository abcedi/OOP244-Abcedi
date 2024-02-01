#include <iostream>
#include <cstring>

#include "Utils.h"
using namespace std;
using namespace seneca;

namespace seneca {
   /* Author - Fardad Soleimanloo*/
   int getInt(int min, int max) {
      int val = min - 1;
      bool done = false;
      while (!done) {
         cin >> val;
         if (val < min || val > max) {
            cout << "Invalid value!" << endl << "The value must be between " << min << " and " << max << ": ";
         }
         else {
            done = true;
         }
      }
      return val;
   }
   /* Author - Fardad Soleimanloo*/
   void printInt(int value, int fieldWidth) {
      cout << value;
      for (int i = 0; i < fieldWidth - intDigits(value); i++) {
         cout << " ";
      }
   }
   /* Author - Fardad Soleimanloo*/
   int intDigits(int value) {
      int count = (value == 0);
      while (value != 0) {
         value /= 10;
         ++count;
      }
      return count;
   }

   /* Author - Fardad Soleimanloo*/
   std::FILE* datafile = nullptr;
   bool openFile(const char* fname)
   {
       if (datafile != nullptr) closeFile();
       datafile = fopen(fname, "r");
       return datafile != nullptr;
   }
   /* Author - Fardad Soleimanloo*/
   void closeFile() {
       if (datafile) {
           fclose(datafile);
           datafile = nullptr;
       }
   }

   void bubbleSort(int* data, int n) {
      bool done = false;
      int i;
      while (!done) {
         done = true;
         for (i = 0; i < n - 1; i++) {
            if (data[i] > data[i + 1]) {
               int temp = data[i];
               data[i] = data[i + 1];
               data[i + 1] = temp;
               done = false;
            }
         }
      }
   }

//The dynamic array will be deleted by first going through each element of the Assessment array in a loop, deleting the dynamic double and the dynamic cString of all 
//Assessment elements and then it will delete the array itself.
void freeMem(int data, int size) {
   for (int i = 0; i < size; i++) {
      delete[] data[i];
   }
   delete[] data;
}

   
}
