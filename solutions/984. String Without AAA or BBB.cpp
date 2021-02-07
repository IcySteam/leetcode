class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string output = "";
        while (abs(a - b) >= 2) {
            if (a > b) {
                output.append("aa");
                if (b > 0) {
                    output.push_back('b');
                    b--;
                }
                a -= 2;
            }
            else if (a < b) {
                output.append("bb");
                if (a > 0) {
                    output.push_back('a');
                    a--;
                }
                b -= 2;
            }
        }
        while (a > 0 || b > 0) {
            if (a >= b) {
                for (int i = 0; i < min({a, 2}); i++) {
                    output.push_back('a');
                }
                a -= min({a, 2});
            }
            else if (a < b) {
                for (int i = 0; i < min({b, 2}); i++) {
                    output.push_back('b');
                }
                b -= min({b, 2});
            }
        }
        return output;
    }
};
