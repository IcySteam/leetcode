class Solution {
public:
    int countOrders(int n) {
        long long res = 1, mod = 1e9 + 7;
        for (int i = n; i >= 1; i--)
            res = res * i * (i * 2 - 1) % mod;
        return res;
    }
};
