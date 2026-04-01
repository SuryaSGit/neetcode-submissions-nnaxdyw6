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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        if(temp1== nullptr){
            return temp2;
        }
        if(temp2 == nullptr){
            return temp1;
        }
        ListNode* head;
        if(temp1->val < temp2->val){
            head = temp1;
            temp1 = temp1->next;
        }
        else{
            head = temp2;
            temp2 = temp2->next;
        }
        ListNode* cur = head;
        while(temp1!=nullptr && temp2 != nullptr){
            if(temp1->val < temp2->val){
                cur -> next = temp1;
                temp1 = temp1 -> next;
            }
            else{
                cur -> next = temp2;
                temp2 = temp2 -> next;
            }
            cur = cur -> next;
        }
        if(temp1!=nullptr){
            cur -> next = temp1;
        }
        if(temp2 != nullptr){
            cur -> next = temp2;
        }
        return head;
    }
};
