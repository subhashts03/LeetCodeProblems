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
    void vot(TreeNode *root,map<int,map<int,vector<int>>> &m,int hd,int level){
        if(root == NULL) return ;
        m[hd][level].push_back(root -> val);
        vot(root -> left,m,hd - 1,level + 1);
        vot(root -> right,m,hd +1,level + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v1;
        map<int,map<int,vector<int>>> m;
        vot(root,m,0,0);
        for(auto i : m){
            vector<int> v2;
            for(auto k : i.second){
                sort(k.second.begin(),k.second.end());
                for(auto j : k.second){
                v2.push_back(j);}
            }
            v1.push_back(v2);
        }
        return v1;
    }
};