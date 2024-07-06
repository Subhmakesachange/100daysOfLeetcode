class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        // If the size of the array is less than 3, it's not possible to have three consecutive odd numbers
        if (arr.size() < 3) {
            return false;
        }

        // Loop through the array up to the third-to-last element
        for (int i = 0; i < arr.size() - 2; i++) {
            // Check if the current element is odd
            if (arr[i] % 2 != 0) {
                // Check if the next two elements are also odd
                if (arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
                    return true; // Return true if three consecutive odd numbers are found
                }
            }
        }
        
        return false; // Return false if no such sequence is found
    }
};
