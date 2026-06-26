class Solution {
public:
void cb(vector<int>& candidates, int target,vector<vector<int>>&ans, int sum, vector<int>&arr,int idx){
    if(sum>target){
        return;
    }
    else if(sum==target){
        ans.push_back(arr);
        return;
    }
    for(int i =idx ; i<candidates.size(); i++){
        arr.push_back(candidates[i]);
        cb(candidates,target,ans,sum+candidates[i],arr,i);
        arr.pop_back();
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
vector<int>arr;
        cb(candidates,target,ans,0,arr,0);
        return ans;
    }
};