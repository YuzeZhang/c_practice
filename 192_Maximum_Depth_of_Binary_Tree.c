/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//每一层的高度就是它的两个子树的高度的最大值+1
int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    else{
        int left = maxDepth(root->left)+1;
        int right = maxDepth(root->right)+1;
        if(left > right)
            return left;
        else
            return right;
    }
}
