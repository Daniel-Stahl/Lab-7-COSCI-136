#include "ExpressionTree.hpp"

TreeNode* ExpressionTree::MakeTree(string expression) {
//    int strSize = expression.size();
//    int x = 0;
//    int pivPoint = 0;
//    char tempChar;
//    string leftSubTree;
//    string rightSubTree;
//
//
//    x = 0;
//    while (x < strSize) {
//        tempChar = expression.at(x);
//        if (x < pivPoint) {
//            leftSubTree += tempChar;
//        } else if(x > pivPoint) {
//            rightSubTree += tempChar;
//        }
//
//        x++;
//    }
    
    
    
    return FindPiv(expression);


};

bool ExpressionTree::IsOperand(char input) {
    if (input == '*' || input == '/' || input == '+' || input == '-') {
        return true;
    } else {
        return false;
    }
}

TreeNode* ExpressionTree::FindPiv(string expression) {
    TreeNode* pivot = new (std::nothrow) TreeNode;
    int strSize = expression.size();
    int x = 0;
    int pivPoint = 0;
    char tempChar;
    string leftSubTree = "";
    string rightSubTree = "";
    
    if (pivot) {
        while (x < strSize) {
            tempChar = expression.at(x);
            
            
            // a+b*c-d/e
            
            if (IsOperand(tempChar) && (tempChar == '+' || tempChar == '-')) {
                pivot->element = tempChar;
                pivPoint = x;
            } else if(IsOperand(tempChar) && (pivot->element != '+' && pivot->element != '-')) {
                pivot->element = tempChar;
                pivPoint = x;
            } else if (strSize == 1) {
                pivot->element = tempChar;
            }
            
            x++;
        }
        
        //expression.substr();
        
        x = 0;
        while (x < strSize) {
            tempChar = expression.at(x);
            
            if (x < pivPoint) {
                leftSubTree += tempChar;
            } else if(x > pivPoint) {
                rightSubTree += tempChar;

            }

            x++;
        }
    }
    
    if (root == nullptr) {
        root = pivot;
    }
    
    if (leftSubTree != "") {
        pivot->left = FindPiv(leftSubTree);
    } else {
        return pivot;
    }
    
    if (rightSubTree != "") {
        pivot->right = FindPiv(rightSubTree);
    }
    
    if (leftSubTree == "" && rightSubTree == "") {
        return pivot;
    }
    
    
    
    return pivot;
}
