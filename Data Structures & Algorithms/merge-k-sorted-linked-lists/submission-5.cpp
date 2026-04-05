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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        if(lists.size()==1){
            return lists[0];
        }
        if(lists.size() == 2){
            return merge(lists[0],lists[1]);
        }
        else{
            size_t half = lists.size() / 2;
            vector<ListNode*> first_half(lists.begin(), lists.begin() + half);
            vector<ListNode*> second_half(lists.begin() + half, lists.end());
            return merge(mergeKLists(first_half),mergeKLists(second_half));
        }
    }
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* head;
        if(a -> val < b -> val){
            head = a;
            a = a -> next;
        }
        else{
            head = b;
            b = b -> next;
        }
        ListNode* cur = head;
        while(a!=nullptr && b != nullptr){
            if(a -> val < b -> val){
                cur -> next = a;
                cur = a;
                a = a -> next;
            }
            else{
                cur -> next = b;
                cur = b;
                b = b -> next;
            }
        }
        if(a!=nullptr){
            cur -> next = a;
        }
        if(b!=nullptr){
            cur -> next = b;
        }
        return head;
    }
};
