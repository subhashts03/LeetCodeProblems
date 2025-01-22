int solve(int i,int j,int m,int n ,int a[][n]){
    if(i >= m || j >= n) return 0;//Boundary

    if(a[i][j] != 0) return a[i][j];//Already found path

    if(i == m -1 && j == n - 1) return 1;//Homme

    else return a[i][j] = solve(i + 1, j , m , n,a) + solve(i , j + 1 , m , n , a);//two choice
 }
int uniquePaths(int m, int n) {
    //To avoid overlapping subproblem
     int a[m][n];//Must initalize Zero for 2d matrix
     for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
        }
     }
    return solve(0,0,m,n,a);
}