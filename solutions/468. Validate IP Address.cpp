class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find('.') < IP.size() && IP.find(':') >= IP.size()) {
            string chars = "0123456789";
            vector<string> blocks;
            int index = 0;
            string tmp = "";
            while (index < IP.size()) {
                if (IP[index] != '.') {tmp.push_back(IP[index]);}
                else {
                    blocks.push_back(tmp);
                    tmp = "";
                }
                index++;
            }
            blocks.push_back(tmp);
            if (blocks.size() == 4) {
                for (auto& ele : blocks) {
                    if (ele.size() < 1 || ele.size() > 3) {return "Neither";}
                    for (auto& chara : ele) {
                        if (chars.find(chara) >= chars.size()) {return "Neither";}
                    }
                    if (stoi(ele) < 0 || stoi(ele) > 255 || to_string(stoi(ele)) != ele) {return "Neither";}
                }
                return "IPv4";
            }
            else {return "Neither";}
        }
        else if (IP.find(':') < IP.size() && IP.find('.') >= IP.size()) {
            string chars = "0123456789abcdefABCDEF";
            vector<string> blocks;
            int index = 0;
            string tmp = "";
            while (index < IP.size()) {
                if (IP[index] != ':') {tmp.push_back(IP[index]);}
                else {
                    blocks.push_back(tmp);
                    tmp = "";
                }
                index++;
            }
            blocks.push_back(tmp);
            if (blocks.size() == 8) {
                for (auto& ele : blocks) {
                    if (ele.size() < 1 || ele.size() > 4) {return "Neither";}
                    for (auto& chara : ele) {
                        if (chars.find(chara) >= chars.size()) {return "Neither";}
                    }
                }
                return "IPv6";
            }
            else {return "Neither";}
        }
        else {return "Neither";}
    }
};
