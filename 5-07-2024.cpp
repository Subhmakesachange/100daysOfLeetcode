/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mindistance = INT_MAX;
        int maxdistance = -1;
        int first = -1;
        int previous = -1;
        int index = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {

            //checking max and minima
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (first == -1) {//changing first index value
                    first = index;
                } else {
                    //updating mindistance
                    mindistance = min(mindistance, index - previous);
                }
                if (previous != -1) {
                    maxdistance = max(maxdistance, index - first);
                }
                previous = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (mindistance == INT_MAX) {
            mindistance = -1;
        }
        if (maxdistance == -1) {
            maxdistance = -1;
        }

        return {mindistance, maxdistance};
    }
};
