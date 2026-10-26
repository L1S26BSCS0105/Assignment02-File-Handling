/*
 * Name       : Tahreem Fatima
 * Reg No     : L1S26BSCS0105
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
 // FIX 1: <fstream> was missing, so ifstream and ofstream were unknown types (this was the compile error)
#include <fstream>
using namespace std;

int main() {

    ifstream inFile("stock.txt");
              // FIX 2: the check was upside down, it printed "not found" when the file DID open. 
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

        // FIX 3: a plain ofstream erases reorder.txt on opening, ios::app keeps the old lines and adds at the end
    ofstream reorder("reorder.txt", ios::app);

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    // FIX 4: total was an int, so every qty * price lost its decimals, it must be a double
    double total = 0;

       // FIX 5: the first line is a header, it was never skipped, so the first read failed and nothing was counted
    inFile.ignore(100, '\n');

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            // FIX 6: endl was missing, so all low stock items were joined on one line instead of one item per line
            reorder << code << " " << qty << endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();

  cout << "Items: " << count << endl;
  cout << "Total stock value: " << total << endl;
  cout << "Low stock items: " << low << endl;

    return 0;
}

