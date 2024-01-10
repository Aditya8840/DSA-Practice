/**
 * Key idea to find absolute difference between left length and right length <= 1
 * but left subtree and right subtree also should be balanced
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
    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int l = 1+depth(root->left);
        int r = 1+depth(root->right);

        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int l = depth(root->left);
        int r = depth(root->right);

        cout<<l<<" "<<r<<endl;
        
        int res = l-r;
        return abs(res) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};