class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void cb(string &digits, vector<string> &ans, int i, string ss) {
        if (i == digits.size()) {
            ans.push_back(ss);
            return;
        }

        for (char ch : mp[digits[i]]) {
            cb(digits, ans, i + 1, ss + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        cb(digits, ans, 0, "");
        return ans;
    }
};