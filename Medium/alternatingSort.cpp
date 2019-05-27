// CodeSignal Mock Test

bool alternatingSort(std::vector<int> a) {
    
    int l = 0, r = a.size()-1;
    int prev = INT_MIN;
    
    bool left = true;
    while(l <= r) {
        if(left) {
            if(prev >= a[l]) return false;
            prev = a[l];
            l++;
        }
        else {
            if(prev >= a[r]) return false;
            prev = a[r];
            r--;
        }
        left = !(left);
    }
    return true;
}

