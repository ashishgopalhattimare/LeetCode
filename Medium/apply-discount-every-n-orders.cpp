// https://leetcode.com/problems/apply-discount-every-n-orders/
// Medium

class Cashier {
public:
	
	int customerCount = 0;
	int count, dis;

	unordered_map<int,int>mapi;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        dis = discount;
        count = n;

        for(int i = 0; i < products.size(); i++) {
        	mapi[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        
        customerCount++;

        double total = 0;
        for(int i = 0; i < product.size(); i++) {
        	total += (amount[i] * mapi[product[i]]); 
        }

        if(customerCount % count == 0) {
        	total = total - total *(dis/100.0);
        }

        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */