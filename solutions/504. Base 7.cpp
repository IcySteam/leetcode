class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {return "0";}
        stack<int> output_int;
        int abs_num = abs(num);
        while (abs_num > 0) {
            output_int.push(abs_num % 7);
            abs_num = abs_num / 7;
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
