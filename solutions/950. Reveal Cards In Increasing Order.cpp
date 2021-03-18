class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> sortedDeck;
        for (auto& ele : deck) {
            sortedDeck.push_back(ele);
        }
        deque<int> outDeck;
        while (!sortedDeck.empty()) {
            if (!outDeck.empty()) {
                int outBottom = outDeck.back();
                outDeck.pop_back();
                outDeck.push_front(outBottom);
            }
            int sortedBottom = sortedDeck.back();
            sortedDeck.pop_back();
            outDeck.push_front(sortedBottom);
        }
        
        vector<int> output;
        while (!outDeck.empty()) {
            output.push_back(outDeck.front());
            outDeck.pop_front();
        }
        return output;
    }
};
