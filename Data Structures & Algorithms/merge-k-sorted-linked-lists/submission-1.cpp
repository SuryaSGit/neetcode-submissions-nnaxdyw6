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
        int min = 0;
        while(lists[min]==nullptr){
            min++;
            if(min >= lists.size()){
                return nullptr;
            }
        }
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]!=nullptr&&lists[i]->val < lists[min] -> val){
                min = i;
            }
        }
        ListNode* head = new ListNode(lists[min]->val);
        ListNode* cur = head;
        lists[min] = lists[min] -> next;
        bool temp = true;
        while(temp){
            temp = false;
            min = 0;
            while(lists[min]==nullptr){
                min++;
                if(min >= lists.size()){
                    return head;
                }
            }
            for(int i = min; i < lists.size(); i++){
                if(lists[i]!=nullptr&&lists[i]->val < lists[min] -> val){
                    min = i;
                    temp = true;
                }
            }
            cout << lists[min] -> val << endl;
            if(temp == false && lists[min]==nullptr){
                return head;
            }
            cur -> next = new ListNode(lists[min]->val);
            cur = cur -> next;
            lists[min] = lists[min] -> next;
            temp = true;
        }
        return head;
    }
};
