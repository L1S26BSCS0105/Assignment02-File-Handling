/*
 * Name       : Tahreem Fatima
 * Reg No     : L1S26BSCS0105
 * Assignment : 02 - File Handling
 * Question   : Q5 - Expense Tracker
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
  
   int choice = 0;
   char category[20];       
   int amount;              
   char wanted[20];    

   char fileCat[20];        
   int fileAmount;          
   char cats[100][20];      
   
    int amts[100];           
    int n, i;                
    int total, largest;      
    int count;               

    do {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

     if (!(cin >> choice)) { 

          break;
      }

      if (choice == 1) {


        cout << "Enter category: ";
         cin >> category;
        cout << "Enter amount: ";
        cin >> amount;
          if (amount <= 0) {

                cout << "Invalid amount!" << endl;

         }

        else {

                ofstream outFile("expenses.txt", ios::app);   // app, adds at the end, to keep old lines

                outFile << category << " " << amount << endl;

                outFile.close();
                cout << "Expense saved." << endl;

            }

        }
        else if (choice == 2) {

            n = 0;                               // starting from zero every time option 2 is chosen

            ifstream inFile("expenses.txt");     
            if (inFile) {

                while (n < 100 && inFile >> cats[n] >> amts[n]) {
                    n++;
                }

                inFile.close();
            }
            if (n == 0) {

                cout << "No expenses yet." << endl;
            }

            else {
                total = 0;
                largest = 0;

                for (i = 0; i < n; i++) {
                    cout << i + 1 << ". " << cats[i] << " " << amts[i] << endl;
                    total = total + amts[i];

                    if (amts[i] > amts[largest]) {  

                        largest = i;
                    }
                }

                cout << "Total spent: " << total << endl;
                cout << "Largest expense: " << cats[largest] << " (" << amts[largest] << ")" << endl;

            }
        }
        else if (choice == 3) {

            cout << "Enter category: ";

            cin >> wanted;


            count = 0;                           // start from zero every time option 3 is chosen
            total = 0;
            ifstream inFile("expenses.txt");
            if (inFile) {
                while (inFile >> fileCat >> fileAmount) {
                    if (strcmp(fileCat, wanted) == 0) {
                        count++;
                        total = total + fileAmount;
                    }
                }
                inFile.close();
            }
            if (count == 0) {
                cout << "No expenses found for " << wanted << endl;
            }
            else {
                cout << "Expenses in " << wanted << ": " << count << endl;
                cout << "Total for " << wanted << ": " << total << endl;
            }
        }
        else if (choice == 4) {
            ofstream outFile("expenses.txt");   
            outFile.close();
            cout << "All expenses cleared." << endl;
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}