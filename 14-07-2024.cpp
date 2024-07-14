class Solution {
public:
    string countOfAtoms(string formula) {
            map<string, int> cnt_map;
    stack<map<string, int>> stk;
    int i = 0, n = formula.size();
    
    while (i < n) {
        if (formula[i] == '(') {
            stk.push(cnt_map);
            cnt_map.clear();
            i++;
        } else if (formula[i] == ')') {
            i++;
            int start = i;
            while (i < n && isdigit(formula[i])) i++;
            int mult = (start == i) ? 1 : stoi(formula.substr(start, i - start));
            
            if (!stk.empty()) {
                auto prev_map = stk.top();
                stk.pop();
                for (auto &[elem, cnt] : cnt_map) {
                    prev_map[elem] += cnt * mult;
                }
                cnt_map = prev_map;
            }
        } else {
            int start = i;
            i++;
            while (i < n && islower(formula[i])) i++;
            string elem = formula.substr(start, i - start);
            
            start = i;
            while (i < n && isdigit(formula[i])) i++;
            int cnt = (start == i) ? 1 : stoi(formula.substr(start, i - start));
            
            cnt_map[elem] += cnt;
        }
    }
    
    string res;
    for (const auto &pair : cnt_map) {
        res += pair.first;
        if (pair.second > 1) res += to_string(pair.second);
    }
    
    return res;

    }
};
