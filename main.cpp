#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "ExpressionTree.hpp"

using namespace std;

int main() {
    /*
     Menu:
     
     1) Load expression (makes an exptree and deletes the previous one)
     2) Print preorder (Checks if there is a tree)
     3) Print inorder (Checks if there is a tree)
     4) Print postorder (Checks if there is a tree)
     
     
     */
    
    
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
    
    ExpressionTree ET;
    
    ET.MakeTree(vecExpress.at(4));
    
    
//    int x = 0;
//
//    char theRoot = 'r';
//
//    while (vecExpress.size() > x) {
//        int y = 0;
//
//        while (vecExpress.at(x).size() > y) {
//            cout << vecExpress.at(x).at(y);
//
//            if (vecExpress.at(x).at(y) == '+' || vecExpress.at(x).at(y) == '-') {
//                theRoot = vecExpress.at(x).at(y);
//            }
//
//            y++;
//        }
//
//        if (!(theRoot == '+' || theRoot == '-')) {
//            theRoot = vecExpress.at(x).at(y-2);
//        }
//
//        cout << " The root is:  "<< theRoot << endl;
//
//
//
//        x++;
//    }
    
    
    
    
    
    
    
}
