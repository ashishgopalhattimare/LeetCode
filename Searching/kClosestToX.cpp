// k-th closest elements to x

class Solution {
public:
    
    int binarySearch(vector<int>& A, int start, int end, int x)
    {
        if(start > end) {
            if(end == -1) return 0;
            else if(start == A.size()) return A.size()-1;
            
            int left = abs(x-A[start]);
            int right = abs(x-A[end]);
                
            if(left < right) return start;
            return end;
        }
        
        if(end == start+1) {
            if(A[start] == x) return start;
            if(A[end] == x) return end;
            else {
                int left = abs(x-A[start]);
                int right = abs(x-A[end]);
                
                if(left < right) return start;
                return end;
            }
        }
        
        int mid = start + (end - start)/2;
        
        if(A[mid] == x) return mid;
        
        if(x < A[mid]) return binarySearch(A, start, mid, x);
        return binarySearch(A, mid, end, x);
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        if(arr.size() == 1) return arr;
        
        int index = binarySearch(arr, 0, arr.size()-1, x);
        
        // printf("%d\n", index);
        
        vector<int> result;
        
        if(index == 0) {
            for(int i = 0; k > 0 && i < arr.size(); i++) {
                result.push_back(arr[i]);
                k--;
            }
        }
        else if(index == arr.size() - 1) {
            for(int i = index; k > 0 && i >= 0; i--) {
                result.push_back(arr[i]);
                k--;
            }
        }
        else {
            int left = index;
            int right = index+1;
            
            
            while(left >= 0 && right < arr.size() && k > 0) {
                
                // printf("%d %d %d", arr[left], x, arr[right]);
                
                if(abs(x-arr[left]) <= abs(x-arr[right])) {
                    // printf(": %d\n", arr[left]);
                    result.push_back(arr[left--]);
                }
                else {
                    // printf(": %d\n", arr[right]);
                    result.push_back(arr[right++]);
                }
                k--;
            }
            
            while(k > 0 && left >= 0) {
                result.push_back(arr[left--]);
                k--;
            }
            while(k > 0 && right < arr.size()) {
                result.push_back(arr[right++]);
                k--;
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};