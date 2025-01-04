/*
    Suggested Learning Path
    -> Start with Flood Fill to understand DFS/BFS basics.
    -> Solve Island Perimeter to get comfortable with navigating grid edges.
    ->  Attempt Max Area of Island to practice similar logic to Problem 200.
    ->  Finally, tackle Number of Islands to consolidate your learning.
*/ 
class Solution {
    public int AreaDirectional(int [][] grid,int row,int col){
        if(row < 0 || row >=grid.length ||col < 0|| col >=grid[0].length || grid[row][col] == 0) 
            return 0;
        if(grid[row][col] == -1) 
            return 0;
        grid[row][col] = -1;
        return 1 + AreaDirectional(grid,row + 1,col) //Down
         + AreaDirectional(grid,row - 1,col) //Up
         + AreaDirectional(grid,row,col +1) //right
         + AreaDirectional(grid,row,col - 1);//left
    }
    public int maxAreaOfIsland(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int max = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0;j < col; j++){
                int area = AreaDirectional(grid,i,j);
                if(max < area){
                    max = area;
                }
            }
        }
        return max;
    }
}