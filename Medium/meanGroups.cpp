// CodeSignal Mock Test

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
// Returns LCM of array elements 
int findlcm(std::vector<int>& arr) 
{
    int ans = arr[0]; 
    for (int i = 1; i < arr.size(); i++) 
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans))); 
  
    return ans; 
}

std::vector<std::vector<int>> meanGroups(std::vector<std::vector<int>> a) {
    
    std::unordered_map<int, std::vector<int>>mapp;
    std::vector<std::vector<int>>result;
    
    if(a.size() == 0) return result;
    
    std::vector<int>arr;
    for(int i = 0; i < a.size(); i++) {
        arr.push_back(a[i].size());
    }
    
    int lcm = findlcm(arr);
    
    for(int x = 0; x < a.size(); x++) {
        int sum = 0;
        for(int i : a[x]) sum+=i;
        
        if(arr[x] == 0) sum = 0;
        else sum = (sum * lcm) / arr[x];
        
        mapp[sum].push_back(x);   
    }
    
    int i = 0;
    for(auto itr = mapp.begin(); itr != mapp.end(); itr++, i++) {
        result.push_back(itr->second);
        
        std::sort(result[i].begin(), result[i].end());
    }
    
    std::sort(result.begin(), result.end(), [](std::vector<int>& aa, std::vector<int>& bb) {
        return aa < bb;
    });
    
    return result;
}

