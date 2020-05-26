#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "ExpressionTree.hpp"

using namespace std;

void LoadMenu();

int main() {
    LoadMenu();
}

void LoadMenu() {
    int userSelection;
    int vecSize = 1;
    int pos = 0;
    ifstream inFile;
    string input;
    vector<string> vecExpress;
    ExpressionTree ET;
    TreeNode* tNode = nullptr;
    
    inFile.open("/Users/stahl/Desktop/Pierce College/COSCI 136/LAB_7_STAHL_DANIEL/data.txt");
    
    if (inFile) {
        cout << "File loaded\n";
    } else {
        cout << "No file exists\n";
        exit (1);
    }
    
    inFile >> input;
    vecExpress.push_back(input);
    
    while (getline(inFile, input)) {
        inFile >> input;
        vecExpress.push_back(input);
        vecSize++;
    }
    
    do {
        cout << "Main Menu\n 1) Load expression\n 2) Print preorder\n 3) Print postorder\n 4) Print inorder\n 5) Exit program\n Choice: ";
        cin >> userSelection;
        
        switch (userSelection) {
            case 1:
                // Loads expression 1 at a time and makes the tree.
                pos = ET.LoadExpression(vecSize-1);
                cout << "\nLoading Expression: " << vecExpress.at(pos) << "\n";
                tNode = ET.MakeTree(vecExpress.at(pos));
                cout << "\n";
                break;
                
            case 2:
                //Print preorder
                cout << "\nPreorder: ";
                ET.DisplayPreorder(tNode);
                cout << "\n" << endl;
                break;
                
            case 3:
                //Print postorder
                cout << "\nPostorder: ";
                ET.DisplayPostorder(tNode);
                cout << "\n" << endl;
                break;
                
            case 4:
                //Print inorder
                cout << "\nInorder: ";
                ET.DisplayInorder(tNode);
                cout << "\n" << endl;
                break;
        }
    } while (userSelection != 5);
    
}
