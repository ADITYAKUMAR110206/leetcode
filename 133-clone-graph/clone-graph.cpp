#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        // Clone first node
        Node* clone = new Node(node->val);
        mp[node] = clone;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return clone;
    }
};