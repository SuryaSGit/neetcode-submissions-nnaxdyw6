/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* temp;
        unordered_map<int,Node*> vals;
        temp = new Node(head -> val);
        head->val = 0;
        Node* temp2;
        Node* temp3 = head;
        Node* temp4 = temp;
        int count = 0 ;
        cout << "25" << endl;
        vals[count] = temp;
        while(head -> next != nullptr){
            head = head -> next;
            temp2 = new Node(head-> val);
            count++;
            head-> val = count;
            vals[count] = temp2;
            temp -> next =temp2;
            temp = temp2;
        }
        head = temp3;
        temp = temp4;
        cout << "37" << endl;
        while(head != nullptr){
            if(head->random==NULL){
                temp4 -> random = NULL;
            }
            else{
                temp4->random = vals[(head->random) ->val];
            }
            head = head -> next;
            temp4 = temp4 -> next;
        }
        
        return temp;
    }
};
