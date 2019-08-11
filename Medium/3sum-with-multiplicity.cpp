// https://leetcode.com/problems/3sum-with-multiplicity/
// Medium (starred)
// logic : Sort the array, get the frequency of each element in the array
//         then perform O(n^2) to find 3-sum target.
//         Once found, there are 4 cases [a!=b==c][a==b==c][a==b!=c][a!=b!=c]
//         and each has different way to find
//         [a==b==c] is a nCr problem which requires modular division (not possible)
//         thus inverse is found and then calculated.

class Solution {
public:
    
    unordered_map<int,int>freq;
    long long mod = 1e9+7;
    
    long long fact[3001];
    
    long long gcdExtended(long long a, long long b, long long *x, long long *y) 
    { 
        // Base Case 
        if (a == 0) 
        { 
            *x = 0, *y = 1; 
            return b; 
        } 

        long long x1, y1; // To store results of recursive call 
        long long gcd = gcdExtended(b%a, a, &x1, &y1); 

        // Update x and y using results of recursive 
        // call 
        *x = y1 - (b/a) * x1; 
        *y = x1; 

        return gcd; 
    }
    
    long long inverseOf(long long b, long long m) 
    { 
        long long x, y; // used in extended GCD algorithm 
        long long g = gcdExtended(b, m, &x, &y); 

        // Return -1 if b and m are not co-prime 
        if (g != 1) 
            return -1; 

        // m is added to handle negative x 
        return (x%m + m) % m; 
    }
    
    // n! / r! * (n - r)! = nC3
    long long combinationFormula(int value) {
        if(value == 3) return 1;
        
        cout << value << endl;
        
        long long upper = fact[value];
        long long lower = fact[3] * fact[value-3];
        
        long long inverse = inverseOf(lower, mod);
        
        return upper * inverse;
    }
    
    long long evaluateCombination(int a, int b, int c)
    {
        if(a != b && b == c) {
            return freq[a] * ((freq[b] * (freq[c]-1))/2);
        }
        else if(a == b && b != c) {
            return ((freq[a] * (freq[b]-1))/2) * freq[c];
        }
        else if(a == b && b == c) {
             return combinationFormula(freq[a]);
        }
        
        return freq[a] * freq[b] * freq[c];
    }
    
    int threeSumMulti(vector<int>& A, int target) {
        
        sort(A.begin(), A.end());
        
        // Break the question into three parts
        fact[1] = 1;
        for(int i = 2; i < 3001; i++) fact[i] = (fact[i-1] * i) % mod;
        
        for(int x : A) freq[x]++;
        
        long long result = 0;
        int l, r, sum;
        for(int i = 0; i < A.size(); i++) {
            if(i && A[i-1] == A[i]) continue;
            
            l = i+1; r = A.size()-1;
            while(l < r) {
                sum = A[i] + A[l] + A[r];
                
                if(sum == target) {
                    result += evaluateCombination(A[i], A[l], A[r]);
                    result %= mod;
                    
                    while(l < r && A[l] == A[l+1]) l++;
                    l++;
                    while(l < r && A[r-1] == A[r]) r--;
                    r--;
                }
                else if(sum < target) {
                    l++;
                    while(l < r && A[l-1] == A[l]) l++;
                }
                else {
                    r--;
                    while(l < r && A[r] == A[r+1]) r--;
                }
            }   
        }
        
        return result;
    }
};

// breakdown load question
// N^2
