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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            temp = temp -> next;
            count++;
        }
        if(count < k){
            return head;
        }
        temp = head;
        ListNode* temp2 = head -> next;
        ListNode* temp3 = temp2 -> next;
        for(int i = 0; i < k-1; i++){
            temp2 -> next = temp;
            temp = temp2;
            temp2 = temp3;
            if(temp2 == nullptr){
                break;
            }
            temp3 = temp2 -> next;
        }
        head -> next = reverseKGroup(temp2,k);
        head = temp;
        return head;
    }
};
