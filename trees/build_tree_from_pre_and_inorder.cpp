/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    TreeNode* build(int inStart, int inEnd, int preStart, int preEnd, vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& mp){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val]; //find inOrder index in map
        int leftOver = inRoot - inStart;

        root->left = build(inStart, inRoot - 1, preStart+1, preStart+leftOver,preorder,inorder,mp);
        root->right = build(inRoot+1, inEnd, preStart+leftOver+1, preEnd,preorder,inorder,mp);
        return root;
    } 

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //map index of inorder traversal
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        int n = preorder.size();
        int m = inorder.size();
        TreeNode* root = build(0,m-1,0,n-1,preorder,inorder,mp);
        return root; 
    }
};
