class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {

                // Store index of '('
                st.push(i);

            } else {

                // Try to match ')'
                st.pop();

                if (st.empty()) {

                    // This ')' cannot be matched
                    st.push(i);

                } else {

                    // Valid substring length
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};