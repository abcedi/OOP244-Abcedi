#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "StMark.h"
#include "file.h"
#include "graph.h"
#include "io.h"

using namespace std;

namespace seneca {
	/// <summary>
	/// Tries to open the students' mark data file. 
	/// If successful it will print a report based on the 
	/// date in the file.
	/// </summary>
	/// <param name="filename">, holds the data file name</param>
	/// <returns>True if the date files is opened succesfully, 
	/// otherwise returns false</returns>

	bool printReport(const char* filename) {

		if (openFile(filename)) {

			StMark marks[MAX_NO_RECS];
			int noOfMarks = readMarks(marks);

			int range[10] = {0};

			for (int i = 0; i < noOfMarks; i++) {

				int mark = marks[i].mark;
				int rangeIndex = 0;

				if (mark >= 91 && mark <= 100) {
					rangeIndex = 0;
				}
				else if (mark >= 81 && mark <= 90) {
					rangeIndex = 1;
				}
				else if (mark >= 71 && mark <= 80) {
					rangeIndex = 2;
				}
				else if (mark >= 61 && mark <= 70) {
					rangeIndex = 3;
				}
				else if (mark >= 51 && mark <= 60) {
					rangeIndex = 4;
				}
				else if (mark >= 41 && mark <= 50) {
					rangeIndex = 5;
				}
				else if (mark >= 31 && mark <= 40) {
					rangeIndex = 6;
				}
				else if (mark >= 21 && mark <= 30) {
					rangeIndex = 7;
				}
				else if (mark >= 11 && mark <= 20) {
					rangeIndex = 8;
				}
				else if (mark >= 0 && mark <= 10) {
					rangeIndex = 9;
				}
				range[rangeIndex]++;
			}

			bubbleSort(marks, noOfMarks);

			printGraph(range, 10, "Students' mark distribution");

			for (int i = 0; i < noOfMarks; i++) {

				if (i < 9) {
					cout << i + 1 << "  : [";
				}
				else if (i < 99) {
					cout << i + 1 << " : [";
				}
				else {
					cout << i + 1 << ": [";
				}

				int spaces = (marks[i].mark < 10) ? 2 : (marks[i].mark < 100) ? 1 : 0;
				cout << marks[i].mark;

				cout << string(spaces, ' ') << "] ";

				cout << marks[i].name << " " << marks[i].surname << endl;

				
			}

			closeFile();
			cout << "----------------------------------------" << endl;
			return true;
		}

		

		return false;
	}

	void bubbleSort(StMark* studentArray, int size) {
		int i, j;
		for (i = 0; i < size - 1; i++) {
			for (j = 0; j < size - i- 1; j++) {
				if (studentArray[j].mark < studentArray[j + 1].mark) {
					StMark temp = studentArray[j];
					studentArray[j] = studentArray[j + 1];
					studentArray[j + 1] = temp;
				}
			}
		}
	}
}
