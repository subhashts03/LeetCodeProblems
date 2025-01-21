//TC : O(2 ^ N)
// SC : O(N) [Stack] + O(N) [Array] = O(2N) = O(N)
//DP : Top to Down 
int Sum(int n ,int arr[]){
    if(n == 0 || n == 1) return n;
    if(arr[n] != -1) return arr[n];
    return arr[n] = Sum(n - 1,arr) + Sum(n - 2,arr);
}
int fib(int n){
    if(n == 0 || n == 1) return n;
   int arr[n+1];
   for(int i = 0; i < n + 1; i++){
    arr[i] = -1;
   } 
   arr[0] = 0;
   arr[1] = 1;
    Sum(n,arr);
    return arr[n];
    
}