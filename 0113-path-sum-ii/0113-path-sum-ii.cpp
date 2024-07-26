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
void solve(TreeNode* root, int targetSum , int sum , vector<int>temp ,vector<vector<int>>&ans )
{
    if(!root) return;
    if(root->left==NULL && root->right==NULL)
    {
        temp.push_back(root->val);
        sum+=root->val;
        if(sum==targetSum)
        {
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(root->val);
    sum+=root->val;
    solve(root->left , targetSum , sum  ,temp, ans);
    solve(root->right , targetSum , sum  ,temp, ans);
    
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;
        vector<vector<int>>ans;
        solve(root , targetSum , sum  ,temp, ans);
        return ans;
    }
};