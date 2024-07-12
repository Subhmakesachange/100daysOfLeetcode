class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int sc = 0;
        stack<char> stk;

        auto rmSubstr = [&](char a, char b, int pts) {
            int temp_sc = 0;
            stack<char> temp_stk;

            while (!stk.empty()) {
                char ch = stk.top();
                stk.pop();
                if (!temp_stk.empty() && temp_stk.top() == b && ch == a) {
                    temp_sc += pts;
                    temp_stk.pop();
                } else {
                    temp_stk.push(ch);
                }
            }

            while (!temp_stk.empty()) {
                stk.push(temp_stk.top());
                temp_stk.pop();
            }

            return temp_sc;
        };

        if (x >= y) {
            for (char c : s)
                stk.push(c);
            sc += rmSubstr('a', 'b', x);
            sc += rmSubstr('b', 'a', y);
        } else {
            for (char c : s)
                stk.push(c);
            sc += rmSubstr('b', 'a', y);
            sc += rmSubstr('a', 'b', x);
        }

        return sc;
    }
};
