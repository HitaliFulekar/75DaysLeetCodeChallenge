class Solution {
public:
void cb( vector<vector<int>>&ans, int n , int k , int idx, vector<int>&arr){
    if(arr.size()==k){
        ans.push_back(arr);
        return;
    }

    for(int i = idx; i<=n; i++){
        arr.push_back(i);
        cb(ans,n,k, i+1,arr);
        arr.pop_back();
    }
    return;
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>arr;
        cb(ans,n,k,1, arr);
        return ans;
    }
};