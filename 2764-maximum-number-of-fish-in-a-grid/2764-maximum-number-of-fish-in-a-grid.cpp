class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        // Boundary conditions
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        
        // Store fish count and mark cell as visited (set it to 0)
        int fish = grid[i][j];
        grid[i][j] = 0;

        // Explore all 4 directions and sum up fish counts
        fish += solve(grid, i + 1, j);
        fish += solve(grid, i - 1, j);
        fish += solve(grid, i, j + 1);
        fish += solve(grid, i, j - 1);

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxi = 0;  // Start from 0 instead of INT_MIN

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    // Compute the max fish count in connected components
                    maxi = max(maxi, solve(grid, i, j));
                }
            }
        }
        return maxi;
    }
};
