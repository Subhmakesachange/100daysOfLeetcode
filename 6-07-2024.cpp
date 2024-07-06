class Solution {
public:
    int passThePillow(int n, int time) {
        time %= 2 * (n - 1); // Calculate the remaining time after full cycles
        
        if (time <= n - 1) {
            return time + 1; // Forward direction
        } else {
            return n - (time - (n - 1)); // Backward direction
        }
    }
};
