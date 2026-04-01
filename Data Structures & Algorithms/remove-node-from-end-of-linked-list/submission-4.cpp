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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        if(head == nullptr){
            return nullptr;
        }
        if(head -> next == nullptr){
            return nullptr;
        }
        ListNode* temp = head;
        while(temp!=nullptr){
            temp = temp -> next;
            count++;
        }
        count = count - n;
        if(count == 0){
            temp = head-> next;
            head -> next = nullptr;
            return temp;
        }
        ListNode* prev = temp;
        temp = head;
        for(int i = 0; i < count; i++){
            prev = temp;
            temp = temp -> next;
        }
        prev->next = temp -> next;
        return head;
    }
};
