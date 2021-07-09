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
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
            return node;
        
        unordered_map<Node *, Node *> visited;
        // 将节点入列
        queue<Node *> nodes;
        nodes.push(node);
        // 克隆第一个节点并加入hash
        visited[node] = new Node(node->val);

        // 广度优先
        while (!nodes.empty())
        {
            // 取出头节点
            auto n = nodes.front();
            nodes.pop();
            // 遍历邻居
            for (auto &neighbor : n->neighbors)
            {
                // 未被访问则加入hash并加入队列
                if (visited.find(neighbor) == visited.end())
                {
                    visited[neighbor] = new Node(neighbor->val);
                    nodes.push(neighbor);
                }
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};