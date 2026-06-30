class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        if (special.empty())
            return top - bottom + 1;

        sort(special.begin(), special.end());

        int ans = 0;

       
        ans = max(ans, special[0] - bottom);

        
        ans = max(ans, top - special.back());

        
        for (int i = 0; i < special.size() - 1; i++) {
            ans = max(ans, special[i + 1] - special[i] - 1);
        }

        return ans;
    }
};