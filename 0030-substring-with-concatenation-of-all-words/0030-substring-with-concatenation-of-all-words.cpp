class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();
        int k = words.size();

        if (n == 0 || k == 0)
            return ans;

        int len = words[0].size();

        unordered_map<string, int> need;

        for (string &word : words)
            need[word]++;

      
        for (int start = 0; start < len; start++) {

            unordered_map<string, int> have;

            int left = start;
            int count = 0;

            for (int right = start; right + len <= n; right += len) {

                string word = s.substr(right, len);

                
                if (need.find(word) == need.end()) {
                    have.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                have[word]++;
                count++;

               
                while (have[word] > need[word]) {
                    string leftWord = s.substr(left, len);
                    have[leftWord]--;
                    count--;
                    left += len;
                }

                
                if (count == k) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, len);
                    have[leftWord]--;
                    count--;
                    left += len;
                }
            }
        }

        return ans;
    }
};