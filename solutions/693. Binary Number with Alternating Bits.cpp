class Solution {
public:
    bool hasAlternatingBits(int n) {
        string nBin = convertToBase(n, 2);
        if (nBin.size() == 1) {return true;}
        for (int i = 1; i < nBin.size(); i++) {
            if (nBin[i] == nBin[i - 1]) {return false;}
        }
        return true;
    }
    
    string convertToBase(int num, int base) {
        if (num == 0) {return "0";}
        stack<int> output_int;
        int abs_num = abs(num);
        while (abs_num > 0) {
            output_int.push(abs_num % base);
            abs_num = abs_num / base;
        }
        string output_str = "";
        if (num < 0) {output_str.append("-");}
        while (!output_int.empty()) {
            output_str.append(to_string(output_int.top()));
            output_int.pop();
        }
        return output_str;
    }
};
