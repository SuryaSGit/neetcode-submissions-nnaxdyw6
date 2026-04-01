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
    void reorderList(ListNode* head) {
        if(head == nullptr){
            return;
        }
        if(head ->next == nullptr){
            return;
        }
        int count = 1;
        ListNode* temp = head;
        cout << "HI" << endl;
        while(temp != nullptr){
            temp = temp->next;
            count++;
        }
        count = count/2;
        temp = head;
        ListNode* temp3;
        for(int i = 0; i < count; i++){
            temp3 = temp;
            temp = temp -> next;
        }
        temp3 -> next = nullptr;
        ListNode* temp2 = temp -> next;
        temp -> next = nullptr;
        cout << "HI" << endl;
        while(temp2 != nullptr){
            temp3 = temp2 -> next;
            temp2 -> next = temp;
            temp  = temp2;
            temp2 = temp3;
        }
        cout << "HI" << endl;
        temp2 = head;
        while(temp!=nullptr){
            temp3 = temp2 -> next;
            temp2 -> next = temp;
            temp2 = temp3;
            temp3 = temp -> next;
            temp -> next = temp2;
            temp = temp3;
        }
    }
};
