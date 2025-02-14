class ProductOfNumbers {
    vector<int> nums;
public:
    ProductOfNumbers() {}
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n = nums.size();
        int res = 1;

        for(int i=n-k; i<n; i++) res *= nums[i];

        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */