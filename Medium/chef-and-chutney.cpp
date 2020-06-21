#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define MAXBIT 26

int BIT[3] = {1,2,4};

// Power Exponentiation using modulo (GeeksForGeeks)
LL powerExponentiation(LL a, LL b/*, LL n*/){
    LL x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) x = (x*y) /*% n*/; // multiplying with base

        y = (y*y) /*% n*/; // squaring the base
        b /= 2;
    }
    return x /*% n*/;
}

LL getBinary(string str, LL num, int maxLen)
{
    vector<int> binary(maxLen, 0), result(ceil(MAXBIT/3));
    for(int i = maxLen-1; i >= 0 && num; i--) {
        if(num % 2 == 1) binary[i] = 1;
        num /= 2;
    }

    int k = 0, data = 0;
    for(int i = 0, k = 0; i < maxLen; i++) {
        data = 2*data + (binary[i] == 1);
        if((i + 1) % 3 == 0) {
            result[k++] = data; data = 0;
        }
    }
    result[k++] = data; data = 0;

    LL decimal = 0;
    for(int x : result) decimal = 10*decimal+x;

    // cout << str << " " << decimal << endl;

    return decimal;
}

bool print(vector<int>& binary, vector<string>& chutney, int L) {
    
    // for(int x : binary) cout << x; cout << "    ";
    // for(int i = 0; i < binary.size(); i++) {
    //     if(binary[i]) cout << chutney[i+L] << " ";
    // }
    // cout << '\n';

    vector<int>freq(26, 0);
    for(int i = 0; i < binary.size(); i++) {
        if(binary[i]) { // use this chuntney in concatenation
            for(char x : chutney[i+L]) freq[x-'a']++;
        }
    }

    int oddCount = 0; for(int x : freq) if(x % 2 == 1) oddCount++;

    // if(oddCount <= 1) { for(int x : binary) printf("%-2d ", x); printf("\n"); }
    return oddCount <= 1;
}

int getBitSet(string& str)
{
    bitset<MAXBIT> binary;
    for(char x : str) {
        binary[x-'a'] = binary[x-'a'] ^ 1;
    }
    return binary.to_ulong();
}

int subsetXOR(vector<int>& arr, int n) 
{ 
    // Find maximum element in arr[] 
    int max_ele = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        max_ele = max(max_ele, arr[i]);
    }
  
    // Maximum possible XOR value 
    int m = (1 << (int)(log2(max_ele) + 1)) - 1;

    int row = n+1, col = m+1;
    
    vector<int>dp(row * col, 0);

    // The xor of empty subset is 0 
    dp[0] = 1;
  
    // Fill the dp table 
    for(int i=1; i < row; i++) {
        for (int j=0; j < col; j++) {
            dp[i*col+j] = dp[(i-1)*col+j] + dp[(i-1)*col + (j^arr[i-1])];
        }
    }

    int k, multi = 1, result = dp[n*col+0];

    for(int x = 0; x < ceil(MAXBIT/3); x++) {
        for(int i = 0; i < 3; i++) {
            k = BIT[i] * multi;

            if(k > m) break;
            else {
                result += dp[n*col+k];
            }
        }
        multi *= 10;
    }

    return result;
}

void optimal(vector<string>& chutney, int N, int Q, ifstream& infile)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int type, X, L, R;

    vector<int> bitnum(chutney.size());
    for(int i = 1; i < chutney.size(); i++) {
        bitnum[i] = getBinary(chutney[i], getBitSet(chutney[i]), MAXBIT);
    }

    while(Q--)
    {
        infile >> type;
        switch(type)
        {
            case 1: // Update Chutney
                infile >> X;
                infile >> chutney[X];
                
                bitnum[X] = getBinary(chutney[X], getBitSet(chutney[X]), MAXBIT);

                break;
            
            case 2: // Get Combination of palindromic chutneys
                infile >> L >> R;

                vector<int>arr(R-L+1);
                for(int i = 0; i < arr.size(); i++) {
                    arr[i] = bitnum[L+i];
                }

                int result = subsetXOR(arr, R-L+1);
                cout << result<< endl;
        }
    }
}

void bruteForce(vector<string>& chutney, int Q, ifstream& infile)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int type, X, L, R;
    /*
    while(Q--)
    {
        cin >> type;
        switch(type)
        {
            case 1: // Update Chutney
                cin >> X;
                cin >> chutney[X];
                
                break;
            
            case 2: // Get Combination of palindromic chutneys
                cin >> L >> R;

                int length = R - L + 1;
                LL total = powerExponentiation(2, length);

                int result = 0;
                for(LL num = 1; num < total; ++num) {
                    vector<int> binary = getBinary(num, length);
                    result += print(binary, chutney, L);
                }
                cout << result << endl;
        }
    }
    */
}

int main()
{
    ifstream infile; infile.open("input.txt");

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, Q;

    infile >> N >> Q;
    
    vector<string> chutney(N + 1);
    for(int i = 1; i <= N; ++i) {
        infile >> chutney[i];
    }

    // bruteForce(chutney, Q, infile);
    optimal(chutney, N, Q, infile);
    
    return 0;
}