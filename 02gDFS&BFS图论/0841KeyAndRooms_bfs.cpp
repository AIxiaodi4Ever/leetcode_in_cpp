class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        queue<int> accessible;
        accessible.push(0);
        vector<int> vis(rooms.size(), 0);
        vis[0] = 1;
        int nums = 0;
        while (!accessible.empty())
        {
            int curr = accessible.front();
            ++nums;
            accessible.pop();
            for (int &room : rooms[curr])
            {
                if (!vis[room])
                {
                    accessible.push(room);
                    vis[room] = 1;
                }
            }
        }
        return nums == rooms.size();
    }
};