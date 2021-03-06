class Solution {
public:
        vector<int> vis;
        int nums;

    void myDfs(int room, vector<vector<int>>& rooms)
    {
        ++nums;
        vis[room] = 1;
        for (auto &key : rooms[room])
        {
            // 加入这个条件则不需要一开始判断是否访问
            if (!vis[key])
                myDfs(key, rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vis.resize(n);
        myDfs(0, rooms);
        return nums == n;
    }
};