class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end());
        int ans = 0;
        while(k > 0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};