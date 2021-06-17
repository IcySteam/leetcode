            }
            temp = temp / 10;
            numDigits++;
        }
​
        int dp[numDigits][digits.size()];
        int rowSums[numDigits];
        for (int i = 0; i < numDigits; ++i) {rowSums[i] = 0;}
        
        int res = 0;
        for (int i = 0; i < numDigits; ++i) {
            int rowSum = 0;
            for (int j = 0; j < digits.size(); ++j) {
                if (i == 0) {
                    dp[i][j] = 1;
                    rowSum += dp[i][j];
                } else if (i < numDigits - 1) {
                    dp[i][j] = rowSums[i - 1];
                    rowSum += dp[i][j];
                } else if (i == numDigits - 1) {
                    if (digits[j][0] - '0' < firstDigit) {
                        dp[i][j] = rowSums[i - 1];
                        rowSum += dp[i][j];
                    } else if (digits[j][0] - '0' > firstDigit) {
                        // do nothing
                    } else {
                        // do nothing for now
                    }
                }
                
            }
            rowSums[i] = rowSum;
            res += rowSum;
        }
        
        unordered_map<int, int> leq;
        int digitCntArr[10];
        for (int i = 0; i < 10; ++i) {digitCntArr[i] = 0;}
        for (int i = 0; i < digits.size(); ++i) {
            digitCntArr[digits[i][0] - '0'] = 1;
        }
        int sumSoFar = 0;
        for (int i = 0; i < 10; ++i) {
            sumSoFar += digitCntArr[i];
            leq[i] = sumSoFar;
        }
        
        string n_itos = to_string(n);
        int plussed = digitCntArr[firstDigit]? sameDigitMatch(digits, leq, n_itos, 1) : 0;
        cout << plussed;
        res += plussed;
        return res;
    }
    
    int sameDigitMatch(vector<string>& digits, unordered_map<int, int>& leq, string& num, int startingIndex) {
        if (startingIndex > num.size() - 1) {return 0;}
        if (startingIndex == num.size() - 1) {return leq[num[startingIndex] - '0'];}
        
        int res = 0;
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i][0] - '0' < num[startingIndex] - '0') {
                res += pow(digits.size(), num.size() - 1 - startingIndex);
            } else if (digits[i][0] - '0' == num[startingIndex] - '0') {
                res += sameDigitMatch(digits, leq, num, startingIndex + 1);
            }
        }
        return res;
    }
};
