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
    ListNode* oddEvenList(ListNode* head) {
            if(!head || head->next == 0) return head;

        ListNode *even = head->next;
        ListNode *evenHead = even;
        ListNode *odd = head;

        while( even && even->next){
            
            odd->next = even->next;    //all odds
            even->next = even->next->next;  //all evens

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead; // connect the evenHead with the last odd node
        return head;
    }
};