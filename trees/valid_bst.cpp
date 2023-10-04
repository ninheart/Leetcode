
#include "tree.h"
#include <vector>

using namespace std;

void inOrder(TreeNode *node, vector<int>& nodes){
    if(!node) return 
    inOrder(node->left, nodes);
    nodes.push_back(node->val);
    inOrder(node->right,nodes);
}

bool validBST(TreeNode *root){
    vector<int> nodes;
    inOrder(root, nodes);
    for(int i = 1; i < nodes.size(); i++){
        if(nodes[i] <= nodes[i-1]) return false;
    }
    return true;
};