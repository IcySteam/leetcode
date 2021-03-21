class Solution {
public:
    void DFS(vector<vector<int>>& rooms, vector<int>& visited, int currentRoom) {
        if (visited[currentRoom] == 1) {return;}
        visited[currentRoom] = 1;
        for (int i = 0; i < rooms[currentRoom].size(); i++) {
            DFS(rooms, visited, rooms[currentRoom][i]);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        DFS(rooms, visited, 0);
        
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == 0) {return false;}
        }
        return true;
    }
};
