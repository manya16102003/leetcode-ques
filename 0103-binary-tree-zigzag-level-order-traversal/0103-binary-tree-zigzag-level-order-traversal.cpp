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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        bool LtoR=true;
        queue<TreeNode*>q;
        q.push(root);
        if(!root) return ans;
        while(!q.empty())
        {
            int width=q.size();
            vector<int>onelevel(width);
            for(int i=0;i<width;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                int index=LtoR ? i :width-i-1;
                onelevel[index]=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);

            }
            LtoR=!LtoR;
            ans.push_back(onelevel);
            
        }
        return ans;
    }
};