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
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *nextNode = curr->next;

        vector<int> critical;
        int i = 1;
        while(nextNode != NULL){
            if((prev->val < curr->val && nextNode->val < curr->val ||
             prev->val >curr->val && nextNode->val > curr->val)){
                   critical.push_back(i);
             }
            prev = curr;
            curr = nextNode;
            nextNode = curr->next;
            i++;
        }
        int n =critical.size();
        if(n >= 2){
            int maxDistance = critical[n-1] - critical[0];
            int minDistance = INT_MAX;

            for( int i=0; i<n-1; i++){
                minDistance = min(minDistance, critical[i+1] - critical[i]);
            } 
            return {minDistance, maxDistance};
        }
        return {-1, -1};
    }
};