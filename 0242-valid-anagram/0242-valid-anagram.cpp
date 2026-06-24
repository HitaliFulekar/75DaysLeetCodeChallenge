class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char,int> sm;

        for(char ch : t){
            sm[ch]++;
        }

        for(char ch : s){
            if(sm[ch] == 0){
                return false;
            }
            sm[ch]--;
        }

        return true;
    }
};