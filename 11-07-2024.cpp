class Solution {
public:
    string reverseParentheses(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == ')') {
            string temp;
            while (st.top() != '(') {
                temp += st.top();
                st.pop();
            }
            st.pop(); 
            for (char x : temp) {
                st.push(x);
            }
        } else {
            st.push(c);
        }
    }

    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
};
