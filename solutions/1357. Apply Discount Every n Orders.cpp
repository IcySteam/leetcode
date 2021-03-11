class Cashier {
public:
    int gap;
    int priceOff;
    unordered_map<int, int> priceLookup;
    int iter;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        int size = products.size();
        for (int i = 0; i < size; i++) {
            priceLookup[products[i]] = prices[i];
        }
        gap = n;
        priceOff = discount;
        iter = 1;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double output = 0;
        int size = product.size();
        for (int i = 0; i < size; i++) {
            output += (priceLookup[product[i]] * amount[i]);
        }
        if (iter % gap == 0) {output = output * (100 - priceOff) / 100;}
        iter++;
        return output;
    }
};
​
/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
