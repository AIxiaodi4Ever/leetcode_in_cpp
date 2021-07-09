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

    int getImportance(vector<Employee*> employees, int id) {
        for (auto& employee : employees) {
            mp[employee->id] = employee;
        }
        int ans = 0;
        queue<int> eq;
        eq.push(id);
        while (!eq.empty()) {
            int curId = eq.front();
            eq.pop();
            ans += mp[curId]->importance;
            for (int sub : mp[curId]->subordinates) {
                eq.push(sub);
            }
        }
        return ans;
    }
};