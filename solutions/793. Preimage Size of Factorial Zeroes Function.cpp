class Solution {
public:
    int preimageSizeFZF(int K) {
        int currentZeros = 0;
        double product = 1;
        int iteration = 1;
        int output = 0;
        while (currentZeros <= K && iteration <= 171) {
            cout << product << endl;
            currentZeros = 0;
            double tempProduct = product;
            cout << iteration << ": " << fmod(tempProduct, 10) << endl; // double not cutting it; neither is unsigned long long
            while (fmod(tempProduct, 10) == 0) {
                currentZeros++;
                tempProduct /= 10;
            }
            if (currentZeros == K) {output++;}
            product *= iteration;
            iteration++;
        }
        return output;
    }
};
