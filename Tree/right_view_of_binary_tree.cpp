/*
According to this question, we need to BFS/Level Order Traversal
and for right view push last element in vector.
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
    vector<int> v;
    queue<TreeNode*> q;
    void helper(TreeNode* root){
        if(root == NULL) return;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* n = q.front();
                if(i == sz-1){
                    v.push_back(n->val);
                }
                if(n->left != NULL) q.push(n->left);
                if(n->right != NULL) q.push(n->right);
                q.pop();
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root);
        return v;
    }
};