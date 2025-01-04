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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root == NULL) return ans;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int count = q.size();
            vector<int> innerArray;
            while(count){
                TreeNode * curr = q.front();
                q.pop();
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
                innerArray.push_back(curr -> val);
                count--;
            }
            if(level % 2 ==0)std::reverse(std::begin(innerArray), std::end(innerArray));
            ans.push_back(innerArray);
            level +=1;
        }
        return ans;
    }
};