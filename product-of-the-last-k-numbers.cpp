class ProductOfNumbers {
private:
    vector<int> prefix; 

public:
    ProductOfNumbers() {
        prefix.push_back(1); 
    }

    void add(int num) {
        if (num == 0) {
            // If 0 is added, reset the prefix product list
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(num * prefix.back());
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) {
            return 0; // If k is greater than available elements after a reset
        }
        return prefix.back() / prefix[n - 1 - k];
    }
};
