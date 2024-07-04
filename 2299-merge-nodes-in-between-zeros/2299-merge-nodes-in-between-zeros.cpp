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
    ListNode* mergeNodes(ListNode* head) {
        
        if(head->next == nullptr) {
            return 0;
        }

        // Skip the initial zero node
        head = head->next;

        struct ListNode* temp = head;     // 'temp' will point to the current node for summing
        struct ListNode* traverse = temp->next; // 'traverse' will iterate through the list

        while (temp->next != nullptr) {
            if (traverse->val != 0) {
                temp->val += traverse->val;
                traverse = traverse->next;
            } else {
                // If 'traverse' is zero
                temp->next = traverse->next; // Skip the zero node

                // If the end of the list is reached after skipping the zero
                if(temp->next == nullptr) {
                    return head;
                }

                // Move 'temp' to the start of the next segment
                temp = traverse->next;
                traverse = temp->next; // Move 'traverse' to the next node
            }
        }

        return 0; 
    }
};