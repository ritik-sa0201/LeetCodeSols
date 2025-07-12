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
class Solution {

 bool solve(TreeNode*root,int targetSum,int currSum){
    if(!root)return false;
     currSum +=root->val;
    if(!root->left && !root->right){
        return targetSum==currSum;
    }
    bool left = solve(root->left,targetSum,currSum);
    bool right  =solve(root->right,targetSum,currSum);

    return left || right;
 }


public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};