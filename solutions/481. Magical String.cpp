class Solution {
public:
    int magicalString(int n) {
        string myMagicalString = "1221121221221121122";
        string seedStr = "1121122";
        queue<int> seed;
        for (int i = 0; i < 7; i++) {
            seed.push(seedStr[i] - '0');
        }
        while (myMagicalString.length() < n) {
            int lastNum = myMagicalString[myMagicalString.length() - 1] - '0';
            char appended;
            if (lastNum == 1) {appended = '2';}
            else if (lastNum == 2) {appended = '1';}
            for (int i = 0; i < seed.front(); i++) {
                myMagicalString.push_back(appended);
                seed.push(appended - '0');
            }
            seed.pop();
        }
        
        int output = 0;
        for (int i = 0; i < n; i++) {
            if (myMagicalString[i] - '0' == 1) {output++;}
        }
        return output;
    }
};
