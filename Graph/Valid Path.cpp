string Solution::solve(int x, int y, int C, int R, vector<int> &X, vector<int> &Y) {

    int G[101][101] = {0};
    
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            for(int c=0;c<C;c++){
                if(sqrt(pow(X[c]-i,2) + pow(Y[c]-j,2))<=R){
                    G[i][j] = -1;
                }
            }
        }
    }
    
    if(G[0][0] == -1)
        return "NO";
        
    queue<vector<int> > q;
    q.push({0,0});
    
    int m = x, n=y;
    while(!q.empty()){
            vector<int> arr = q.front(); 
            q.pop(); 
            int elex = arr[0]; 
            int eley = arr[1]; 
          
            // Discover the eight adjacent nodes. 
            // check top-left cell 
            if ((elex > 0) && (eley > 0) &&  
                (G[elex - 1][eley - 1] == 0))  
            { 
              G[elex - 1][eley - 1] = 1; 
              vector<int> v = {elex - 1, eley - 1}; 
              q.push(v); 
            } 
              
            // check top cell 
            if ((elex > 0) &&  
                (G[elex - 1][eley] == 0)) 
            { 
              G[elex - 1][eley] = 1; 
              vector<int> v = {elex - 1, eley}; 
              q.push(v); 
            } 
              
            // check top-right cell 
            if ((elex > 0) && (eley < n) &&  
                (G[elex - 1][eley + 1] == 0))  
            { 
              G[elex - 1][eley + 1] = 1; 
              vector<int> v = {elex - 1, eley + 1}; 
              q.push(v); 
            } 
              
            // check left cell 
            if ((eley > 0) &&  
                (G[elex][eley - 1] == 0))  
            { 
              G[elex][eley - 1] = 1; 
              vector<int> v = {elex, eley - 1}; 
              q.push(v); 
            } 
              
            // check right cell 
            if ((eley < n) &&  
                (G[elex][eley + 1] == 0)) 
            { 
              G[elex][eley + 1] = 1; 
              vector<int> v = {elex, eley + 1}; 
              q.push(v); 
            } 
              
            // check bottom-left cell 
            if ((elex < m) && (eley > 0) &&  
                (G[elex + 1][eley - 1] == 0)) 
            { 
              G[elex + 1][eley - 1] = 1; 
              vector<int> v = {elex + 1, eley - 1}; 
              q.push(v); 
            } 
              
            // check bottom cell 
            if ((elex < m) &&  
                (G[elex + 1][eley] == 0)) 
            { 
              G[elex + 1][eley] = 1; 
              vector<int> v = {elex + 1, eley}; 
              q.push(v); 
            } 
              
            // check bottom-right cell 
            if ((elex < m) && (eley < n) &&  
                (G[elex + 1][eley + 1] == 0))  
            { 
              G[elex + 1][eley + 1] = 1; 
              vector<int> v = {elex + 1, eley + 1}; 
              q.push(v); 
            } 
        
    }
    
    return G[x][y]==1 ? "YES" : "NO";
}
