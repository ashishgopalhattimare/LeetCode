// https://leetcode.com/problems/fraction-addition-and-subtraction/

class Solution {
public:
    
    struct Fraction
    {
        long long int n, d;
        Fraction(long long int nn, long long int dd) : n(nn), d(dd) {}
    };
    
    string fractionAddition(string expression) {
        
        vector<Fraction*>fracArray;
        
        bool positive = true;
        int start = 0;
        
        if(expression[0] == '+') {
            start = 1;
            positive = true;
        }
        else if(expression[0] == '-') {
            start = 1;
            positive = false;
        }
        else {
            positive = true;
        }
        
        long long int n1 = 0, d1 = 0;
        bool numerator = true;
        
        for(int i = start; i < expression.length(); i++) {
            if(expression[i] == '+') {
                numerator = true;
                
                if(!positive) n1 = -1 *n1;
                fracArray.push_back(new Fraction(n1, d1));
                
                positive = true;
                n1 = d1 = 0;
            }
            else if(expression[i] == '-') {
                numerator = true;
                
                if(!positive) n1 = -1 *n1;
                fracArray.push_back(new Fraction(n1, d1));
                
                positive = false;
                n1 = d1 = 0;
            }
            else if(expression[i] == '/') {
                numerator = false;
            }
            else {
                if(numerator) {
                    n1 = n1*10 + (expression[i]-'0');
                }
                else {
                    d1 = d1*10 + (expression[i]-'0');
                }
            }
        }
        
        if(!positive) n1 = -1 *n1;
        fracArray.push_back(new Fraction(n1, d1));
        
        Fraction result(fracArray[0]->n, fracArray[0]->d);
        delete fracArray[0];
        
        long long int base, gcd;
        for(int i = 1; i < fracArray.size(); i++) {
            n1 = fracArray[i]->n;
            d1 = fracArray[i]->d;
            
            base = d1 * result.d;
            
            result.n = n1 * base/d1 + result.n * base/result.d;
            result.d = base;
            
            gcd = __gcd(result.n, result.d);
            result.n/=gcd;
            result.d/=gcd;
            
            delete fracArray[i];
        }
        
        if(result.n < 0 || result.d < 0) {
            if(result.n < 0 && result.d < 0) {
                result.n = abs(result.n);
            }
            else {
                result.n = -1* abs(result.n);
            }
            result.d = abs(result.d);
        }
        
        return to_string(result.n) + "/" + to_string(result.d);
    }
};