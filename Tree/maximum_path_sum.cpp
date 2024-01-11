/*
basically find maximum path of left subtree and right subtree but if negative in left or right then ignore that
also keep track of maximum sum
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
    int depth(TreeNode* root, int &mx){
        if(root == NULL) return 0;

        int lMax = max(0, depth(root->left, mx));
        int rMax = max(depth(root->right, mx),0);

        mx = max(mx, lMax+rMax+root->val);

        return root->val+max(lMax,rMax);
    }
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        int res = depth(root, mx);

        return mx;
    }
};