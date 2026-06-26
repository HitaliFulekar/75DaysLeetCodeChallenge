class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& arr, vector<int>& vis) {

        if (arr.size() == nums.size()) {
            ans.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;

            vis[i] = 1;
            arr.push_back(nums[i]);

            solve(nums, ans, arr, vis);

            arr.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        vector<int> vis(nums.size(), 0);

        solve(nums, ans, arr, vis);
        return ans;
    }
};