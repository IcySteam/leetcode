class Solution {
public:
    int scoreOfParentheses(string& S) {
        if (S.size() == 2) {return 1;}
        else if (S.size() == 4) {return 2;}
        else {
            int lastBalancingIndex = -1;
            int balancingIndex = -1;
            int output = 0;
            while (balancingIndex != S.size() - 1) {
                int counterL = 0;
                int counterR = 0;
                for (int i = lastBalancingIndex + 1; i < S.size(); i++) {
                    if (S[i] == '(') {counterL++;}
                    else if (S[i] == ')') {counterR++;}
                    if (counterL == counterR) {
                        balancingIndex = i;
                        break;
                    }
                }
                if (balancingIndex - lastBalancingIndex == 2) {output += 1;}
                else {
                    string nextSubStr = S.substr(lastBalancingIndex + 2, balancingIndex - lastBalancingIndex - 2);
                    cout << nextSubStr << endl;
                    cout << balancingIndex << endl;
                    output += 2 * scoreOfParentheses(nextSubStr);
                }
                lastBalancingIndex = balancingIndex;
            }
            return output;
        }
    }
};
