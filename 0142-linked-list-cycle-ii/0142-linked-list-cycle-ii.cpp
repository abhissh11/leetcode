/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }

        if(fast == NULL || fast->next == NULL) return NULL;
// restart the slow from the head node and the fast from the current colliding position and now move just one pos to next
        ListNode * ptr = head;
        while(ptr != fast){
            ptr = ptr->next;
            fast = fast->next;
        }
        return ptr;
    }
};