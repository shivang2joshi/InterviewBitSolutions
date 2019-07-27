vector<int> Solution::solve(int A, int B, int C, int K) {
    
    //used BFS but using pq this time.
    
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    vector<int> sol;
    map<int,int> M;     //to check for repeated elements don't get inserted into pq
    
    while(sol.size()<K){
        
        int i = pq.top(); pq.pop();
        
        //children of i
        if(M[i*A]==0)
        {
            pq.push(i*A);
            M[i*A]=1;
        }
        if(M[i*B]==0)
        {
            pq.push(i*B);
            M[i*B]=1;
        }
        if(M[i*C]==0)
        {
            pq.push(i*C);
            M[i*C]=1;
        }
        
        if(i!=1){ 
                sol.push_back(i);
            //cout<<i<<endl;
        }
    }
    
    return sol;
}
