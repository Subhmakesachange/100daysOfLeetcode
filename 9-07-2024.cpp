class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long wait = 0;
    long long time = 0;
    int size=customers.size();
    for (const auto& customer : customers) {
        int arrival = customer[0];
        int order = customer[1];
        
        if (time < arrival) {
            time = arrival;
        }
        
        time += order;
        wait += (time - arrival);
    }
    
    return (double)wait / customers.size();

    }
};
