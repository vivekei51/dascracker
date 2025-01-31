class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int dfs(vector<vector<int>>& grid, int i, int j, int islandID, unordered_map<int, int>& islandSize) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return 0;

        grid[i][j] = islandID;  // Mark the cell with islandID
        int size = 1;

        // Explore 4 directions
        for (auto dir : directions) {
            size += dfs(grid, i + dir[0], j + dir[1], islandID, islandSize);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;  // Map to store islandID -> island size
        int islandID = 2;  // Unique ID for each island (starting from 2)
        int maxIsland = 0;

        // Step 1: Identify islands and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandID, islandSize);
                    islandSize[islandID] = size;
                    maxIsland = max(maxIsland, size);
                    islandID++;
                }
            }
        }

        // Step 2: Try changing a `0` to `1` and compute new max island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIslands;
                    int newSize = 1;

                    // Check all 4 neighbors
                    for (auto dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] > 1) {
                            neighborIslands.insert(grid[ni][nj]);
                        }
                    }

                    // Sum the sizes of unique neighboring islands
                    for (int id : neighborIslands) {
                        newSize += islandSize[id];
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
