class Solution {
public:
    int numWaterBottles(int n, int k) {
        int total = n;
        while (n >= k) {
            int newbottle = n / k;
            int bottlesleft = n % k;
            total += newbottle;
            n = newbottle + bottlesleft;
        }
        return total;
    }
};
