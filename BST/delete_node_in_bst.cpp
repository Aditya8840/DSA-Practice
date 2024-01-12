/*
Basically we will follow deletion of node in BST with recurrsive solution
*/
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
    TreeNode* help(TreeNode* root){
        while(root->left != NULL){
            root = (root->left);
        }
        return root;
    }
    // void helper(TreeNode* root, int val){
    //     if(root == NULL) return;
    //     if(root->val < val){
    //         if(root->right) helper(root->right, val);
    //     }else if(root->val > val){
    //         if(root->left) helper(root->left, val);
    //     }else{
    //         if(root->left == NULL && root->right == NULL){
    //             root = NULL;
    //             return;
    //         }else if(root->left == NULL && root->right != NULL){
    //             root = root->right;
    //         }else if(root->left != NULL && root->right == NULL){
    //             root = root->left;
    //         }else{
    //             if((root->right)->left == NULL){
    //                 root = root->right;
    //             }else{
    //                 int k = help(root->right);
    //                 root->val = k;
    //             }
    //         }
    //     }
    // }

    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        cout<<(root->val)<<" "<<val<<endl;
        if(root->val < val){
            root->right = deleteNode(root->right, val);
            return root;
        }
        if(root->val > val){
            root->left = deleteNode(root->left, val);
            return root;
        }else{
            if(root->left == NULL){
                return root->right;
            }
            if(root->right == NULL){
                return root->left;
            }

            TreeNode* minNode = help(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};