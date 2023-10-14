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

using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int> vec, TreeNode* root, int sum){
        if(!root) return;
        
        if(!root->left && !root->right && root->val == sum){
            vec.push_back(root->val);
            res.push_back(vec);
            return;
        }
 
        vec.push_back(root->val);
        helper(res,vec,root->left, sum-root->val);
        helper(res,vec,root->right, sum-root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res; 
        vector<int> vec;
        helper(res,vec,root,targetSum);
        return res;
    }
};
