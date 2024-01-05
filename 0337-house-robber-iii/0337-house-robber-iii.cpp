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
public:
int solve (TreeNode* root, unordered_map<TreeNode* , int>&dp)
{
    if(!root) return 0;
    if(dp.find(root)!=dp.end()) return dp[root];
     //including the node 
     int include_node_profit=0 , exclude_node_profit=0;
     include_node_profit +=root->val;
     if(root->left)
     {
        include_node_profit+= solve(root->left->left,dp)+solve(root->left->right,dp);
     }
     if(root->right)
     {
         include_node_profit+=solve(root->right->left,dp)+solve(root->right->right,dp);
     }
     //exclude the node
     exclude_node_profit+=solve(root->left,dp)+solve(root->right,dp);
     dp[root]=max(exclude_node_profit,include_node_profit);
     return max(exclude_node_profit,include_node_profit);
}
    int rob(TreeNode* root) {
        unordered_map<TreeNode* , int>dp;
        return solve(root,dp);
    }
};