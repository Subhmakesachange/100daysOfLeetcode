class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
    vector<tuple<int, int, char, int>> robots;

    for (int i = 0; i < n; ++i) {
        robots.emplace_back(positions[i], healths[i], directions[i], i);
    }
    sort(robots.begin(), robots.end());

    stack<tuple<int, int, char, int>> stk; 
    vector<int> res(n, -1);

    for (const auto& r : robots) {
        int p, h, idx;
        char d;
        tie(p, h, d, idx) = r;

        if (d == 'R') {
            stk.push(r);
        } else {
            while (!stk.empty() && get<2>(stk.top()) == 'R') {
                auto [rp, rh, rd, ridx] = stk.top();
                if (h > rh) {
                    h--;
                    stk.pop();
                } else if (h < rh) {
                    get<1>(stk.top())--; 
                    h = 0; 
                    break;
                } else {
                    stk.pop();
                    h = 0;
                    break;
                }
            }
            if (h > 0) {
                res[idx] = h;
            }
        }
    }

    while (!stk.empty()) {
        auto [rp, rh, rd, ridx] = stk.top();
        stk.pop();
        res[ridx] = rh;
    }

    vector<int> final_res;
    for (int h : res) {
        if (h != -1) {
            final_res.push_back(h);
        }
    }

    return final_res;
    }
};
