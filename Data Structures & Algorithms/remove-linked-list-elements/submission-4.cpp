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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* newhead = head;
        while(newhead != nullptr && newhead->val == val ){
            newhead = newhead -> next;
        }
        if(newhead == nullptr){
            return nullptr;
        }
        ListNode* prev = newhead;
        cur = newhead -> next;
        while(cur != nullptr){
            cout << cur -> val << endl;
            if(cur-> val == val){
                prev-> next = cur->next;
                cur = cur -> next;
            }
            else{
                prev = prev -> next;
                cur = cur -> next;
            }  
        }
        return newhead;
    }
};