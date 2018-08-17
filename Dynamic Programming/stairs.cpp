// https://www.interviewbit.com/problems/stairs/

int countStairs(int steps, vector<int>& stairs) {
    
    if(steps == stairs.size()) return 1;
    if(steps > stairs.size()) return 0;
    
    if(stairs[steps] == -1) {
        stairs[steps] = countStairs(steps+1, stairs) + countStairs(steps+2, stairs);
    }
    
    return stairs[steps];
}

int Solution::climbStairs(int A) {
    
    vector<int>stairs(A, -1);
    return countStairs(0, stairs);
}
