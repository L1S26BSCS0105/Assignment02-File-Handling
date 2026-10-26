/*
 * Name       : Tahreem Fatima
 * Reg No     : L1S26BSCS0105
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

    char path[100];
    int n = 0;
    char name[30];

    double cgpa;
    int count = 0, eligible = 0;
    double sum = 0, topCgpa = 0;

    char topName[30];

    cout << "Enter the file name: ";
    cin.getline(path, 100);          // getline, as the name may contain spaces

    // Step 1: Open
    ifstream inFile(path);

    // Step 2: Check
    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }


    inFile >> n;
    inFile.ignore(100, '\n');

    if (n > 30) {

        cout << "Too many students!" << endl;

        inFile.close();
        return 1;
    }


    ofstream outFile("scholarship.txt");    // Step 3: Read / Write

    while (count < n) {
        inFile.getline(name, 30, ',');
        inFile >> cgpa;

        if (!inFile) {

            break;
        }
        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: " << cgpa << endl;

        if (cgpa >= 3.5) {
            outFile << name << "," << cgpa << endl;

            eligible++;
        }
        sum = sum + cgpa;

        if (count == 0 || cgpa > topCgpa) {
            topCgpa = cgpa;

            strcpy(topName, name);
        }
        count++;
    }

    // Step 4: Close
    inFile.close();
    outFile.close();

    if (count < n) {
        cout << "Warning: only " << count << " of " << n << " records found." << endl;

    }
    if (count == 0) {

        cout << "No students found!" << endl;

        return 0;

    }

    cout << "Students: " << count << endl;
    cout << "Average CGPA: " << sum / count << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName << " (" << topCgpa << ")" << endl;


    return 0;

}

