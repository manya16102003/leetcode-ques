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
    //BFS
    // int minDepth(TreeNode* root) {
    //     if(!root) return 0;
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     int level=1;
    //     while(!q.empty())
    //     {
            
    //         int n =q.size();
            
    //         for(int i=0;i<n ;i++)
    //         {
    //             TreeNode* front =q.front();
    //             q.pop();
    //             if(front->left==NULL && front->right==NULL) return level;
    //             if(front->left) q.push(front->left);
    //             if(front->right) q.push(front->right);

    //         }
    //         level++;
    //     }
    //     return -1;
    // }
    int minDepth(TreeNode* root)
    {
        //DFS
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        // int l=minDepth(root->left);
        // int r=minDepth(root->right);
        //as above recursion call will return 0 
        int l=root->left!=NULL ? minDepth(root->left) : INT_MAX;
        int r= root->right!=NULL ? minDepth(root->right) : INT_MAX;
        return 1+min(l,r);
    }
};