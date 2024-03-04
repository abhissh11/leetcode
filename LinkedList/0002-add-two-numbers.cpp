/*
    Given 2 linked lists, digits stored in reverse order, add them
    Ex. l1 = [2,4,3] l2 = [5,6,4] -> [7,0,8] (342 + 465 = 807)

    Sum digit-by-digit + carry, handle if one list becomes null

    Time: O(max(m, n))
    Space: O(max(m, n))
*/
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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while ((l1 != NULL || l2 != NULL) || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};