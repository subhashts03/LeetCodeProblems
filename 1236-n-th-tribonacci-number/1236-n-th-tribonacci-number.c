//Go to Top to Down;
int Sum(int n,int dp[]){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    
    if(dp[n] != -1) return dp[n];

    return dp[n] = Sum(n - 1,dp) + Sum(n - 2,dp) + Sum(n - 3,dp);
}
int tribonacci(int n) {
    int dp[n+1];
    for(int i = 0; i < n + 1; i++){
        dp[i] = -1;
    }
    return Sum(n,dp);
}