#include <iostream>
#include <fstream>
#include <thread>
#include <string>
using namespace std;

// -------------------- COMPRESSION (RLE) --------------------
void compressFile(string inFile, string outFile)
{
    ifstream in(inFile);
    ofstream out(outFile);

    if (!in.is_open()) {
        cout << "Input file open nahi ho raha!\n";
        return;
    }
    if (!out.is_open()) {
        cout << "Output file open nahi ho raha!\n";
        return;
    }

    char prev, ch;
    int count = 1;

    if (!in.get(prev)) {
        cout << "File empty hai!\n";
        return;
    }

    while (in.get(ch)) {
        if (ch == prev) {
            count++;
        } 
        else {
            out << prev << count << " ";
            prev = ch;
            count = 1;
        }
    }

    out << prev << count << " ";

    cout << "Compression Complete!\n";
}

// -------------------- DECOMPRESSION --------------------
void decompressFile(string inFile, string outFile)
{
    ifstream in(inFile);
    ofstream out(outFile);

    if (!in.is_open()) {
        cout << "Input file open nahi ho raha!\n";
        return;
    }
    if (!out.is_open()) {
        cout << "Output file open nahi ho raha!\n";
        return;
    }

    char ch;
    int count;

    while (in >> ch >> count) {
        for (int i = 0; i < count; i++) {
            out << ch;
        }
    }

    cout << "Decompression Complete!\n";
}

// -------------------------- MAIN --------------------------
int main()
{
    int choice;
    string input, output;

    cout << "------ MULTITHREAD FILE TOOL ------\n";
    cout << "1. Compress File\n";
    cout << "2. Decompress File\n";
    cout << "Enter Choice";
