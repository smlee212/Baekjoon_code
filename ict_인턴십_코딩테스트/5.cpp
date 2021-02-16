int numPaths(vector<vector<int>> warehouse) {
    int n = warehouse.size(), m = warehouse[0].size(); // 행, 열 개수
    
    // dp[x][y]는 warehouse[x-1][y-1]에 도착할 수 있는 모든 경우의 수
    int dp[1001][1001] = {0,};
    
    // 초기값 dp[1][1]을 1로 주기 위함
    dp[1][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(warehouse[i-1][j-1]==0){ // 제한된 좌표이면 경우의 수는 0이다.
                dp[i][j] = 0;
            }
            else{ // 왼쪽에서 오거나, 위에서 내려오는 경우를 더해준다.
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
    }
    
    return dp[n][m];
}