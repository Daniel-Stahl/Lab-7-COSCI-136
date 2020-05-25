#include "ExpressionTree.hpp"

bool ExpressionTree::IsOperand(char input) {
    if (input == '*' || input == '/' || input == '+' || input == '-') {
        return true;
    } else {
        return false;
    }
}

TreeNode* ExpressionTree::MakeTree(string expression) {
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
        
        leftSubTree = expression.substr(0, pivPoint);
        rightSubTree = expression.substr(pivPoint+1, strSize);
    }
    
    if (root == nullptr) {
        root = pivot;
    }
    
    if (leftSubTree != "") {
        pivot->left = MakeTree(leftSubTree);
    } else {
        return pivot;
    }
    
    if (rightSubTree != "") {
        pivot->right = MakeTree(rightSubTree);
    }

    return pivot;
}
