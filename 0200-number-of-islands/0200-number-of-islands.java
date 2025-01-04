class Solution {
    public void countIsLand(char[][] grid, int row, int col, int rows, int cols) {
        // Check boundaries and if the cell is water ('0')
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == '0') {
            return;
        }

        // Mark the cell as visited by changing it to '0'
        grid[row][col] = '0';

        // Explore all 4 directions
        countIsLand(grid, row + 1, col, rows, cols);
        countIsLand(grid, row - 1, col, rows, cols);
        countIsLand(grid, row, col + 1, rows, cols);
        countIsLand(grid, row, col - 1, rows, cols);
    }

    public int numIslands(char[][] grid) {
        int rows = grid.length;      // Total number of rows
        int cols = grid[0].length;  // Total number of columns
        int count = 0;

        // Iterate over each cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If the cell is land ('1'), start DFS
                if (grid[i][j] != '0') {
                    countIsLand(grid, i, j, rows, cols);
                    count++;  // Increment the island count
                }
            }
        }

        return count;
    }
}
