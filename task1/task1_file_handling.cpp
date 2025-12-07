#include <iostream>
#include <fstream>
using namespace std;

void writeFile(string filename) {
    ofstream file(filename); // write mode
    if (!file) {
        cout << "Error creating file!\n";
        return;
    }

    cin.ignore(); // buffer clear
    cout << "Enter text to write in file:\n";
    string text;
    getline(cin, text);

    file << text << endl;
    file.close();
    cout << "Data written successfully!\n";
}

void appendFile(string filename) {
    ofstream file(filename, ios::app); // append mode
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    cin.ignore(); 
    cout << "Enter text to append:\n";
    string text;
    getline(cin, text);

    file << text << endl;
    file.close();
    cout << "Data appended successfully!\n";
}

void readFile(string filename) {
    ifstream file(filename); // read mode
    if (!file) {
        cout << "File not found!\n";
        return;
    }

    cout << "\n----- File Content -----\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    cout << "------------------------\n";
}

int main() {
    int choice;
    string filename = "myfile.txt";

    cout << "==== FILE MANAGEMENT TOOL ====\n";
    cout << "1. Write to File\n";
    cout << "2. Append to File\n";
    cout << "3. Read File\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            writeFile(filename);
            break;
        case 2:
            appendFile(filename);
            break;
        case 3:
            readFile(filename);
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;  // Program yahin stop ho jayega
}
