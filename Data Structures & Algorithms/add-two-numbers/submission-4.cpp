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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head;
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        int temp2 = l1 -> val + l2 -> val;
        int carry = 0;
        while(temp2 > 9){
            temp2=temp2 - 10;
            carry++;
        }
        ListNode* temp = new ListNode(temp2);
        head = temp; 
        l1 = l1 -> next;
        l2 = l2 -> next;
        while(l1!=nullptr || l2!=nullptr){
            temp2 = carry;
            if(l1 != nullptr){
                temp2 = temp2 + l1 -> val;
            }
            if(l2 != nullptr){
                temp2 = temp2 + l2 -> val;
            }
            carry = 0;
            while(temp2 > 9){
                temp2 = temp2 - 10;
                carry++;
            }
            temp -> next = new ListNode(temp2);
            temp = temp -> next;
            if(l1 != nullptr){
                l1 = l1 -> next;
            }
            if(l2 != nullptr){
                l2 = l2 -> next;
            }
        }
        if(carry > 0){
            temp -> next = new ListNode(carry);
        }
        return head;
    }
};
