
/*
 * Name       : Tahreem Fatima
 * Reg No     : L1S26BSCS0105
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
  int d = 0, m = 0, y = 0;
  char slash;
  char plate[15];
  char type;
  char colon;
  int inH, inM, outH, outM;

   int count = 0, cars = 0, bikes = 0, totalFee = 0;
  int longestMin = -1;

  char longestPlate[15];

  ifstream inFile("parking.txt"); // Step 1: Open

   // Step 2: Check

     if (!inFile) {

         cout << "parking.txt not found!" << endl;
         return 1;

      }

    // Step 3: Read / Write
  inFile >> d >> slash >> m >> slash >> y;

      inFile.ignore(100, '\n');   
     inFile.ignore(100, '\n');

    cout << "Parking report for " << d << "/" << m << "/" << y << endl;

    ofstream receipts("receipts.txt");   

    receipts << "Receipts for " << d << "/" << m << "/" << y << endl;
  
    while (count < 30 && inFile >> plate >> type >> inH >> colon >> inM >> outH >> colon >> outM) {

      int minutes = (outH * 60 + outM) - (inH * 60 + inM);
       int hoursCharged = (minutes + 59) / 60;

        if (hoursCharged == 0) {

           hoursCharged = 1;
         }

      int fee;

     if (type == 'C') {
         fee = hoursCharged * 100;
         cars++;
         cout << plate << " Car ";
      }
        else {
            fee = hoursCharged * 40;

          
           bikes++;
            cout << plate << " Bike ";
        }
        cout << minutes / 60 << " h " << minutes % 60 << " min Fee: " << fee << endl;

        receipts << plate << " " << fee << endl;

        totalFee = totalFee + fee;

     if (minutes > longestMin) {  

         longestMin = minutes;
          strcpy(longestPlate, plate);

        }
           count++;
    }

          // Step 4: Close
    inFile.close(); 
    receipts.close();

    if (count == 0) {

        cout << "No vehicles found!" << endl;
        return 0;
    }

    cout << "Vehicles: " << count << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << totalFee << endl;
    cout << "Longest stay: " << longestPlate << " (" << longestMin / 60 << " h " << longestMin % 60 << " min)" << endl;


    return 0;
}





