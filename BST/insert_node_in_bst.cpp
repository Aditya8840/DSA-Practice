/*
Only take about one edge case which is if root is already NULL
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
    void insert(TreeNode* root, int val){
        int k = root->val;
        if(k < val){
            if(root->right == NULL){
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return;
            }
            insert(root->right, val);
        }else{
            if(root->left == NULL){
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return;
            }
            insert(root->left, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        insert(root, val);
        return root;
    }
};