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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * curr = root;
        stack<TreeNode *> s;
        vector<int> ans;
        while(true){
            while(curr  != NULL){
                s.push(curr);
                curr = curr -> left;
            }
            if(s.empty()) break;
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr -> right;
        }
        return ans;
    }
};