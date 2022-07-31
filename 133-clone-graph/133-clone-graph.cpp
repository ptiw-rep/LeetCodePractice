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
        unordered_map<Node *, Node *> mp;
        if( node==NULL )
            return NULL;
        queue<Node *> q;
        Node * first = new Node(node->val);
        mp[node] = first;
        q.push(node);
        while(!q.empty()) {
            Node * curr = q.front();
            q.pop();
            for( Node* nxt : curr->neighbors) {
                if( mp.find(nxt)==mp.end() ) {
                    mp[nxt] = new Node(nxt->val);
                    q.push(nxt);
                }
                mp[curr]->neighbors.push_back(mp[nxt]);
            }
        }
        return mp[node];
    }
};