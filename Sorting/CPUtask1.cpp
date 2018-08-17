// https://leetcode.com/problems/task-scheduler/description/

// taskScheduler.cpp -> in greedy part using priority_queue

int hash[26];

bool compare(char a, char b) {
        if(::hash[a-'A'] > ::hash[b-'A']) {
            return true;
        }
        return false;
    }

class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        
        if(tasks.size() == 0) return 0;
        
        int intervals, taskCount;
        
        for(int i = 0; i < 26; i++) {
            ::hash[i] = 0;
        }
        
        for(int i = 0; i < tasks.size(); i++) {
            ::hash[tasks[i]-'A']++;
        }
        
        vector<char> sortTask;
        for(int i = 0; i < 26; i++) {
            if(::hash[i]) {
                sortTask.push_back('A'+i);
            }
        }
        
        sort(sortTask.begin(), sortTask.end(), compare);
        
        int totalTask = sortTask.size();
        int currentLastTask = 0;
        
        deque<char> dq;
        
        while(currentLastTask < sortTask.size() && dq.size() <= n) {
            dq.push_back(sortTask[currentLastTask++]);
        }
        
        taskCount = intervals = 0;
        
        int count;
        while(!dq.empty()) {
            
            count = 0;
            for(auto itr = dq.begin(); itr != dq.end() && count <= n; itr++, count++) {
                intervals++;
                taskCount++;
                printf("%c ", *itr);
                ::hash[*itr -'A']--;
            }
            
            if(count <= n && taskCount < tasks.size()) {
                intervals += (n - count + 1);
            }
            
            while(!dq.empty() && ::hash[dq.back()-'A'] == 0) {
                dq.pop_back();
            }
            while(currentLastTask < sortTask.size() && dq.size() <= n) {
                dq.push_back(sortTask[currentLastTask++]);
            }
        }
        
        
        
        
        return intervals;
    }
};
