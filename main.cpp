#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inFile;
    string input;
    vector<string> vecExpress;
    
    inFile.open("/Users/stahl/Desktop/Pierce College/COSCI 136/LAB_7_STAHL_DANIEL/data.txt");
    
    if (inFile) {
        cout << "File loaded\n";
    } else {
        cout << "No file exists\n";
        exit (1);
    }
    
    while (getline(inFile, input)) {
        inFile >> input;
        vecExpress.push_back(input);
    }
    
    int x = 0;
    while (vecExpress.size() > x) {
        cout << vecExpress.at(x) << endl;
        x++;
    }
    
    
    
    
    
    
    
}
