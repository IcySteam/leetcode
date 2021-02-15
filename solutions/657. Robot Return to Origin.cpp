class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> coord(2, 0);
        for (auto& letter : moves) {
            switch (letter) {
                case 'U':
                    coord[0]++;
                    break;
                case 'D':
                    coord[0]--;
                    break;
                case 'L':
                    coord[1]--;
                    break;
                case 'R':
                    coord[1]++;
                    break;
            }
        }
        return (coord[0] == 0 && coord[1] == 0);
    }
};
