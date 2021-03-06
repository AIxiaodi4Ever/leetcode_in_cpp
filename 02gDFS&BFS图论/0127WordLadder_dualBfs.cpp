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

        vector<int> disBegin(nodeNum, INT_MAX);
        vector<int> disEnd(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        disBegin[beginId] = 0;
        disEnd[endId] = 0;

        queue<int> queBegin;
        queue<int> queEnd;
        queBegin.push(beginId);
        queEnd.push(endId);
        while (!queBegin.empty() && !queEnd.empty())
        {
            int beginSize = queBegin.size(), endSize = queEnd.size();
            for (int i = 0; i < beginSize; ++i)
            {
                int currBegin = queBegin.front();
                queBegin.pop();
                if (disEnd[currBegin] != INT_MAX)
                    return (disBegin[currBegin] + disEnd[currBegin]) / 2 + 1;
                for (const int& id : edge[currBegin])
                {
                    if (disBegin[id] == INT_MAX)
                    {
                        disBegin[id] = disBegin[currBegin] + 1;
                        queBegin.push(id);
                    }
                }
            }
            for (int i = 0; i < endSize; ++i)
            {
                int currEnd = queEnd.front();
                queEnd.pop();
                if (disBegin[currEnd] != INT_MAX)
                    return (disBegin[currEnd] + disEnd[currEnd]) / 2 + 1;
                for (const int& id : edge[currEnd])
                {
                    if (disEnd[id] == INT_MAX)
                    {
                        disEnd[id] = disEnd[currEnd] + 1;
                        queEnd.push(id);
                    }
                }
            }
        }
        return 0;
    }
};