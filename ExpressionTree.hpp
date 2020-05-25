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
    TreeNode* FindPiv(string expression, TreeNode* tNode);
    
private:
    TreeNode* root = nullptr;
    
};
