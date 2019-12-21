// https://leetcode.com/problems/employee-importance/
// Easy

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    
    unordered_map<int,Employee*>hash;
    
    int totalImportance(int id, int prev = -1) {
        
        Employee * employee = hash[id];
        
        int total = employee->importance;
        
        for(int _id : employee->subordinates) {
            if(_id != prev)
                total += totalImportance(_id, id);
        }
        
        return total;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        for(Employee * x : employees) hash[x->id] = x;
        
        return totalImportance(id);
    }
};