#include "ExpressionTree.hpp"

bool ExpressionTree::IsOperand(char input) {
    if (input == '*' || input == '/' || input == '+' || input == '-') {
        return true;
    } else {
        return false;
    }
}

int ExpressionTree::LoadExpression(int vecSize) {
    static int num;
    
    if (num == vecSize) {
        num = 1;
        return num - 1;
    }
    
    num++;
    return num - 1;
}


TreeNode* ExpressionTree::MakeTree(string expression) {
    TreeNode* pivot = new (std::nothrow) TreeNode;
    pivot->left = nullptr;
    pivot->right = nullptr;
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

void ExpressionTree::DisplayPreorder(TreeNode* tNode) {
    if (tNode == nullptr) {
        return;
    }
    
    cout << tNode->element << " ";
    
    DisplayPreorder(tNode->left);
    DisplayPreorder(tNode->right);
}

void ExpressionTree::DisplayPostorder(TreeNode* tNode) {
    if (tNode == nullptr) {
        return;
    }
    
    DisplayPreorder(tNode->left);
    DisplayPreorder(tNode->right);
    
    cout << tNode->element << " ";
    
}

void ExpressionTree::DisplayInorder(TreeNode* tNode) {
    if (tNode == nullptr) {
        return;
    }
    
    DisplayInorder(tNode->left);
    
    cout << tNode->element << " ";
    
    DisplayInorder(tNode->right);
    
}

void ExpressionTree::EmptyTree(TreeNode*& tNode) {
    if (tNode == nullptr) {
        return;
    }
    
    DisplayPreorder(tNode->left);
    DisplayPreorder(tNode->right);
    
    delete tNode;
    
    
}
