struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if(!vals_.contains(key)){
            return -1;
        }
        justUsed(key);
        return vals_[key];
    }
    
    void put(int key, int value) {
        if(vals_.contains(key)){
            justUsed(key);
            vals_[key] = value;
        }
        else if(numnodes_ == capacity_){
            vals_.erase(head_->val);
            vals2_.erase(head_ -> val);
            head_ = head_ -> next;
            vals_[key] = value;
            tail_ -> next = new ListNode(key);
            tail_ -> next -> prev = tail_;
            tail_ = tail_ -> next;
            vals2_[key] = tail_;
        }
        else{
            numnodes_++;
            if(tail_== nullptr){
                head_ = new ListNode(key);
                tail_ = head_;
            }
            else{
                tail_ -> next = new ListNode(key);
                tail_ -> next -> prev = tail_;
                tail_ = tail_ -> next;
            }
            vals_[key] = value; 
            vals2_[key] = tail_;  
        }
    }
    void justUsed(int key){
        ListNode* temp = vals2_[key];
        if(temp == tail_){
            return;
        }
        if(temp == head_){
            head_ = head_ -> next;
            head_ -> prev = nullptr;
            tail_ -> next = temp;
            temp -> prev = tail_;
            tail_ = tail_ -> next;
            tail_ -> next = nullptr;
            return;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        tail_ -> next = temp;
        temp -> prev = tail_;
        tail_ = tail_ -> next;
        temp -> next = nullptr;
        vals2_[key] = temp;
    }
private:
    unordered_map<int,int> vals_;
    unordered_map<int,ListNode*> vals2_;
    ListNode* head_ = nullptr;
    ListNode* tail_ = nullptr;
    int capacity_;
    int numnodes_ = 0;
};
