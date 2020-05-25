#include "TreeNode.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <new>

using namespace std;

class ExpressionTree {
public:
    TreeNode* MakeTree(string expression);
    bool IsOperand(char input);
    TreeNode* FindPiv(string expression);
    
private:
    TreeNode* root = nullptr;
    vector<string>leftTree;
    vector<string>rightTree;
    string leftSide;
    string rightSide;
    
};
