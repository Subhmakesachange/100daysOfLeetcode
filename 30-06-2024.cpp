#include <vector>
#include <algorithm>

using namespace std;

class UF {
public:
    vector<int> p;
    vector<int> r;
    int comps;

    UF(int size) {
        p.resize(size);
        r.resize(size, 0);
        comps = size;
        for (int i = 0; i < size; ++i) {
            p[i] = i;
        }
    }

    int find(int u) {
        if (p[u] != u) {
            p[u] = find(p[u]); // Path compression
        }
        return p[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (r[rootU] > r[rootV]) {
                p[rootV] = rootU;
            } else if (r[rootU] < r[rootV]) {
                p[rootU] = rootV;
            } else {
                p[rootV] = rootU;
                r[rootU]++;
            }
            comps--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Sort edges by type, prioritizing type 3, then type 1, then type 2
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        UF ufA(n + 1);
        UF ufB(n + 1);
        int totalEdgesUsed = 0;

        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (ufA.unionSets(edge[1], edge[2])) {
                    ufB.unionSets(edge[1], edge[2]);
                    totalEdgesUsed++;
                }
            }
        }

        // Process type 1 edges (Alice only)
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (ufA.unionSets(edge[1], edge[2])) {
                    totalEdgesUsed++;
                }
            }
        }

        // Process type 2 edges (Bob only)
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (ufB.unionSets(edge[1], edge[2])) {
                    totalEdgesUsed++;
                }
            }
        }

        // Check if both Alice and Bob can traverse the entire graph
        if (ufA.comps > 2 || ufB.comps > 2) {
            return -1;
        }

        // Maximum number of removable edges
        return edges.size() - totalEdgesUsed;
    }
};
