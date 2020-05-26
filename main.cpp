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

/*
Menu:

1) Load expression (makes an exptree and deletes the previous one)
2) Print preorder (Checks if there is a tree)
3) Print inorder (Checks if there is a tree)
4) Print postorder (Checks if there is a tree)


*/

void LoadMenu() {
    int userSelection;
    int vecSize = 1;
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
        cout << "Main Menu\n 1) Load expression\n 2) Print preorder\n 3) Print inorder\n 4) Print postorder\n 5) Exit program\n Choice: ";
        cin >> userSelection;
        
        switch (userSelection) {
            case 1:
                // Loads expression 1 at a time and makes the tree.
                tNode = ET.MakeTree(vecExpress.at(ET.LoadExpression(vecSize)));
                
                break;
                
            case 2:
                //Print preorder
                
                ET.DisplayPreorder(tNode);
                
                break;
                
            case 3:
                //Print inorder
                ET.DisplayInorder(tNode);
                
                break;
                
            case 4:
                //Print postorder
                ET.DisplayPostorder(tNode);
                break;
        }
        
        
        
        
    } while (userSelection != 5);
    
    
    
    
}
