#include "TreeNode.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <new>

using namespace std;

class ExpressionTree {
public:
    bool IsOperand(char input);
    TreeNode* MakeTree(string expression);
    
private:
    TreeNode* root = nullptr;
    
};
