/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;

    int dfs(int id) {
        int ans = mp[id]->importance;
        for (int sub : mp[id]->subordinates) {
            ans += dfs(sub);
        }
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for (auto& employee : employees) {
            mp[employee->id] = employee;
        }
        int ans = dfs(id);
        return ans;
    }
};