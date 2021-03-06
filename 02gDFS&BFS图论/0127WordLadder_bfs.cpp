class Solution {
public:
    vector<vector<int>> edge;
    unordered_map<string, int> wordId;
    int nodeNum = 0;

    void addWord(string& word)
    {
        if (!wordId.count(word))
        {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word)
    {
        addWord(word);
        int id = wordId[word];
        for (char& c : word)
        {
            char tmp = c;
            c = '*';
            addWord(word);
            int vir_id = wordId[word];
            edge[id].push_back(vir_id);
            edge[vir_id].push_back(id);
            c = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        for (string& word : wordList)
            addEdge(word);
        addEdge(beginWord);
        if (!wordId.count(endWord))
            return 0;

        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while (!que.empty())
        {
            int curr = que.front();
            que.pop();
            if (curr == endId)
                return dis[curr] / 2 + 1;
            for (const int& id : edge[curr])
            {
                // ∑¿÷π÷ÿ∏¥±È¿˙
                if (dis[id] == INT_MAX)
                {
                    dis[id] = dis[curr] + 1;
                    que.push(id);
                }
            }
        }
        return 0;
    }
};