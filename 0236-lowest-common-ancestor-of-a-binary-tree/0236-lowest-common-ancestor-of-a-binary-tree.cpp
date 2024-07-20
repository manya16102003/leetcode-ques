/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;
        TreeNode* leftans=lowestCommonAncestor(root->left, p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right, p,  q);
        if(leftans==NULL && rightans==NULL) return NULL;
        else if(leftans!=NULL && rightans==NULL) return leftans;
        else if(leftans==NULL && rightans!=NULL) return rightans;
        
        else return root;
    }
};