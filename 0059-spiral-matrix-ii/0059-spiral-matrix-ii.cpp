class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v (n , vector<int> (n , 0));
        int x0 = 0 , y0 = 0;
        int cnt = 0;
        int sheet = 2;
        v[0][0] = 1;
        while(sheet <= n*n){
            if(cnt % 2 == 0){
                while(y0 < n - 1 && v[x0][y0+1] == 0){
                    v[x0][y0+1] = sheet;
                    sheet++;
                    y0++;
                }
                while(x0 < n - 1 && v[x0 + 1][y0] == 0){
                    v[x0 + 1][y0] = sheet;
                    sheet++;
                    x0++;
                }
                
            }
            else{
                while(y0 >= 1 && v[x0][y0-1] == 0){
                    v[x0][y0-1] = sheet;
                    sheet++;
                    y0--;
                }
                while(x0 >= 1 && v[x0-1][y0] == 0){
                    v[x0-1][y0] = sheet;
                    sheet++;
                    x0--;
                }
                
            }
            cnt++;
        }
        return v;
    }
};