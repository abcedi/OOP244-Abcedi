/***********************************************************************
Workshop 1: Compiling modular source code
File	w1p2.cpp
Version 1.0
Author	Fardad Soleimanloo  2241
Description:
   This provides some source code in a single file to break 
   into modules and compile together

Revision History
-----------------------------------------------------------
Name            Date            Reason       

***********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;

// Maximum number of samples in an graph
const int MAX_NO_OF_SAMPLES = 20; 
const int GRAPH_WIDTH = 65;
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples, const char* label);
// prints the int value in width of fieldWidth
void printInt(int value, int fieldWidth);
// erturns number of digits in an integer
int intDigits(int value);
// Performs a fool-proof integer entry assuming the user will only enter numeric values.
// if the user enters non digit values, the function will hang in an endless loop.
int getInt(int min, int max);
// moves the cursor backwards
void goBack(int n);
// displays the user interface menu
int menu(int noOfSamples);
// prints samples error message
void samplesFirst();
// Draws a line and adds a label
void labelLine(int n, const char* label);
// Draws a line
void line(int n);

// SeneGraph program
int main() {
   int noOfSamples = 0;
   int samples[MAX_NO_OF_SAMPLES] = { 0 };
   bool done = false;
   labelLine(33, "Welcome to SeneGraph");
   while (!done) {
      switch (menu(noOfSamples)) {
      case 1:
         cout << "Enter number of available samples: ";
         noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
         break;
      case 2:
         if (noOfSamples == 0) {
            samplesFirst();
         }
         else {
            cout << "Please enter the sample values: " << endl;
            getSamples(samples, noOfSamples);
         }
         break;
      case 3:
         if (noOfSamples == 0) {
            samplesFirst();
         }
         else if (samples[0] == 0) {
            cout << "Samples missing. Please enter the sample values!" << endl;
         }
         else {
            printGraph(samples, noOfSamples, " SeneGraph ");
         }
         break;
      case 0:
         cout << "Thanks for using SeneGraph" << endl;
         done = true;
      }
   }
   return 0;
}


// prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples, const char* label) {
   int max = findMax(samples, noOfSamples);
   labelLine(GRAPH_WIDTH + 10, label);
   for (int i = 0; i < noOfSamples; i++) {
      printBar(samples[i], max);
   }
   line(GRAPH_WIDTH + 10);
}

// prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max) {
   int i;
   int barlength = GRAPH_WIDTH * val / max;
   cout << "| ";
   for (i = 0; i < barlength; i++) {
      cout << "*";
   }
   cout << " ";
   printInt(val, (GRAPH_WIDTH + 6 - barlength));
   cout << "|" << endl;
}

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples) {
   int i;
   for (i = 0; i < noOfSamples; i++) {
      line(28);
      cout << "\\ " << (i + 1) << "/";
      printInt(noOfSamples, 2);
      cout << ":                    /";
      goBack(20);
      samples[i] = getInt(1, 1000000);
   }
}

// finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
// otherwise it will return GRAPH_WIDTH. 
int findMax(int samples[], int noOfSamples){
  int max = samples[0];
  int i;
  for (i = 1; i < noOfSamples; i++){
    if (max < samples[i]) max = samples[i];
  }
  return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
}

void printInt(int value, int fieldWidth) {
   cout << value;
   for (int i = 0; i < fieldWidth - intDigits(value); i++) {
      cout << " ";
   }
}
int intDigits(int value) {
   int count = (value == 0);
   while (value != 0) {
      value /= 10;
      ++count;
   }
   return count;
}

// Performs a fool-proof integer entry
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

// moves the cursor backwards
void goBack(int n) {
   for (int i = 0; i < n; cout << "\b", i++);
}

// draw line
void labelLine(int n, const char* label) {
   cout << "+";
   for (int i = 0; i < n - 2; cout << "-", i++);
   cout << "+";
   if (label) {
      goBack(n - 4);
      cout << label;
   }
   cout << endl;
}
void line(int n) {
   cout << "+";
   for (int i = 0; i < n - 2; cout << "-", i++);
   cout << "+";
   cout << endl;
}

// displays the user interface menu
int menu(int noOfSamples) {
   line(28);
   cout << "| No Of Samples: ";
   printInt(noOfSamples, 5);
   cout << "     |" << endl;
   line(28);
   cout << "| 1- Set Number of Samples |" << endl;
   cout << "| 2- Enter Samples         |" << endl;
   cout << "| 3- Graphs                |" << endl;
   cout << "| 0- Exit                  |" << endl;
   cout << "\\ >                        /";
   goBack(24);

   return getInt(0, 3);
}
// prints samples error message
void samplesFirst() {
   cout << "Number of Samples must be set first!" << endl;
}
