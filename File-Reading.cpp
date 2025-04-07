#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

void createDummyData(const char* filename) {
    ofstream file(filename);
    if (strcmp(filename, "home.txt") == 0) {
        file << "WashingMachine 1001 150\n";
        file << "Refrigerator 1002 220\n";
        file << "Microwave 1003 180\n";
    } else if (strcmp(filename, "offices.txt") == 0) {
        file << "Printer 2001 90\n";
        file << "Scanner 2002 130\n";
        file << "Laptop 2003 250\n";
    }
    file.close();
}

int main() {
    char cbr[50];
    int product;
    int sold;
    int maxSold = -1;
    char maxItem[50];
    int x = 0;

    cout << "Press 1 to find the maximum sales of home appliances" << endl;
    cout << "Press 2 to find the maximum sales of office appliances" << endl;
    cin >> x;

    const char* filename = nullptr;

    if (x == 1) {
        filename = "home.txt";
    } else if (x == 2) {
        filename = "offices.txt";
    } else {
        cout << "Invalid choice! Exiting..." << endl;
        return 1;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cout << filename << " does not exist. Creating and adding dummy data..." << endl;
        createDummyData(filename);
        file.open(filename);
    }

    while (file >> cbr >> product >> sold) {
        if (sold > maxSold) {
            maxSold = sold;
            strcpy(maxItem, cbr);
        }
    }

    file.close();

    if (maxSold != -1) {
        cout << "The item with the highest sales in ";
        cout << ((x == 1) ? "home" : "office") << " category is '" << maxItem << "' with " << maxSold << " sold items." << endl;
    } else {
        cout << "No data found in the file." << endl;
    }

    return 0;
}
