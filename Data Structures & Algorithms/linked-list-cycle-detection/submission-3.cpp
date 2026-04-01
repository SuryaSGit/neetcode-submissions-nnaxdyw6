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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        if(slow == nullptr){
            return false;
        }
        ListNode* fast = head->next;
        if(fast == nullptr){
            return false;
        }
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
            if(fast == nullptr){
                return false;
            }
            fast = fast -> next;
            if(fast == nullptr){
                return false;
            }
        }
        return true;
    }
};
