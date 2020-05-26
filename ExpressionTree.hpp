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
    int LoadExpression(int vecSize);
    void DisplayPreorder(TreeNode* tNode);
    void DisplayPostorder(TreeNode* tNode);
    void DisplayInorder(TreeNode* tNode);
    void EmptyTree(TreeNode* tNode);
    ~ExpressionTree();
    
private:
    TreeNode* root = nullptr;
    
};
