class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;

        for (char ch : t)
            freq[ch]++;

        int left = 0;
        int matched = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            if (freq[s[right]] > 0)
                matched++;

            freq[s[right]]--;

            while (matched == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    matched--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};