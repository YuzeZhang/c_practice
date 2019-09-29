/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int TreeSize(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return TreeSize(root->left)+TreeSize(root->right)+1;
}
void _preOrder(struct TreeNode* root,int* arr,int* pi){
    if(root){
        arr[*pi] = root->val;
        ++(*pi);
        _preOrder(root->left,arr,pi);
        _preOrder(root->right,arr,pi);
    }
}