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
    ListNode* reverseHelper(ListNode* start, int numnodes){
        ListNode* cur = start->next;
        ListNode* prev = start;
        ListNode* temp = nullptr;
        for(int i = 0; i < numnodes; i++){
            temp = cur->next;
            cur->next=prev;
            prev=cur;
            cur = temp;
        }
        start->next = cur;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        ListNode* cur = head;
        ListNode* prev = nullptr;
        int cur_pos = 1;
        ListNode* new_head = head;
        while(cur != nullptr){
            if(left == 1){
                ListNode* tmp = head;
                new_head = reverseHelper(head,right-left);
                cur = tmp->next;
                cur_pos = right;
                return new_head;
            }
            else if(cur_pos == left){
                ListNode* tmp = cur;
                prev -> next = reverseHelper(cur,right-left);
                cur = tmp->next;
                return head;
            }
            else{
                prev=cur;
                cur = cur -> next;
                cur_pos++;
            }
        }
        return new_head; 
    }
};