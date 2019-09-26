/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
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
*/
bool isBalanced(struct TreeNode* root){
    int depth = 0;
    return isBalanced2(root,depth);
}

bool isBalanced2(struct TreeNode* root,int* curDepth){
    if(root == NULL){
        *curDepth = 0;
        return 0;
    }
    int leftDepth = 0,rightDepth = 0;
    if(isBalanced2(root->left,&leftDepth)&& isBalanced2(root->right,&rightDepth)
       &&abs(leftDepth - rightDepth) < 2){
        //当前树的高度 max(leftDepth,rightDepth)
        *curDepth = leftDepth > rightDepth ? leftDepth +1 :rightDepth+1;
        return true;
    }else
        return false;
}