#include "lib.h"
//using namespace std;


int main() {
    int menu_entry;

    cout << "SportComp v2.1, custom buggy database interface\n\n";
    cout << "-----MENU-----\n";
    cout << "[1] Read data from file\n" <<
            "[2] Write data to file\n" <<
            "[3] Print data out\n" <<
            "[4] Exit (recommended)\n\n";
    cout << "[>] Choose menu entry: ";
    cin >> menu_entry;
    switch (menu_entry) {
        case 1:
        case 2:
        case 3:
            cout << menu_entry << endl;
        case 4:
            exit(0);
            //break;
    }

    return 0;
}
