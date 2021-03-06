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
            // ���������������Ҫһ��ʼ�ж��Ƿ����
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