#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Cashier {
    int cno;
    int n;
    int discount;
    unordered_set<int, int> inventory; 

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
	    cno = 0;
        this->n = n;
        this->discount = discount;

        for(int i = 0; i < products.size(); ++i) {
            inventory[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double total = 0;

        for(int i = 0; i < product.size(); ++i) {
            total += (this->inventory[product[i]] * amount[i]);
        }

        total -= (((cno % n == 0 && n != 0) * total * discount) / 100);
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
