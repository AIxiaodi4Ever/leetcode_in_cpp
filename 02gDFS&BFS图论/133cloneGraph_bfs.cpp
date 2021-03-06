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
        // ���ڵ�����
        queue<Node *> nodes;
        nodes.push(node);
        // ��¡��һ���ڵ㲢����hash
        visited[node] = new Node(node->val);

        // �������
        while (!nodes.empty())
        {
            // ȡ��ͷ�ڵ�
            auto n = nodes.front();
            nodes.pop();
            // �����ھ�
            for (auto &neighbor : n->neighbors)
            {
                // δ�����������hash���������
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