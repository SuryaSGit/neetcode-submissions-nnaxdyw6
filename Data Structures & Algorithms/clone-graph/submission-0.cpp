/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        unordered_map<int,Node*> vals;
        queue<Node*> to_make;
        Node* root = new Node(node->val);
        vals[node->val] = root;
        to_make.push(node);
        Node* cur = node;
        Node* cur_clone = root;
        while(!to_make.empty()){
            cur = to_make.front();
            cur_clone = vals[cur->val];
            to_make.pop();
            for(int i = 0; i < cur->neighbors.size(); i++){
                int temp = (cur->neighbors[i])->val;
                if(!vals.contains(temp)){
                    vals[temp] = new Node(temp);
                    to_make.push(cur->neighbors[i]);
                }
                (cur_clone -> neighbors).push_back(vals[temp]);
            }
        }
        return root;
    }
};
