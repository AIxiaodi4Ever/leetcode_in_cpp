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
    unordered_map<Node *, Node *> visited;
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
            return node;

        if (visited.find(node) != visited.end())
            return visited[node];

        // 克隆节点，注意这里不是赋值，而是构建一个新的节点
        // 并且不克隆节点的邻接表
        Node *CloneNode = new Node(node->val);

        // 存入hash
        visited[node] = CloneNode;

        for (auto &neighbor : node->neighbors)
        {
            CloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return CloneNode;
    }
};