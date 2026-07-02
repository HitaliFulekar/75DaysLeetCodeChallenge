class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (char ch : s) {

            if (ch != ']') {
                st.push(ch);
            }
            else {

                
                string sub = "";
                while (!st.empty() && st.top() != '[') {
                    sub = st.top() + sub;
                    st.pop();
                }

                st.pop(); 

                
                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int num = stoi(numStr);

               
                string expanded = "";
                for (int i = 0; i < num; i++) {
                    expanded += sub;
                }

                
                for (char c : expanded) {
                    st.push(c);
                }
            }
        }

        
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};