void dfs(vector<vector<char>> &A, int i, int j, vector<vector<bool>> &visited){
    
    if(A[i][j]=='X' || visited[i][j]==true)
        return;
    
    visited[i][j] = true;
    
    if(i-1 >=0 ){   //top
        dfs(A,i-1,j,visited);
    }
    if(i+1 < A.size()){     //bottom
        dfs(A,i+1,j,visited);
    }
    if(j+1 < A[0].size()){  //right
        dfs(A,i,j+1,visited);
    }
    if(j-1 >=0){            //left
        dfs(A,i,j-1,visited);
    }
    
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    vector<vector<bool>> Marked(A.size(),vector<bool>(A[0].size(),false));
    
    //only corner touching groups are protected
    //Mark them
    
    //left col
    for(int i=0;i<A.size();i++){
        if(A[i][0]=='O' && !Marked[i][0]){
            dfs(A, i, 0, Marked);
        }
    }
    
    //top row
    for(int i=0;i<A[0].size();i++){
        if(A[0][i]=='O' && !Marked[0][i]){
            dfs(A, 0, i, Marked);
        }
    }    
    
    //right col
    for(int i=0;i<A.size();i++){
        if(A[i][A[0].size()-1]=='O' && !Marked[i][A[0].size()-1]){
            dfs(A, i, A[0].size()-1, Marked);
        }
    }
    
    //bottom row
    for(int i=0;i<A[0].size();i++){
        if(A[A.size()-1][i]=='O' && !Marked[A.size()-1][i]){
            dfs(A, A.size()-1, i, Marked);
        }
    }    
    
    //set all unmarked regions to X
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(!Marked[i][j])
                A[i][j] = 'X';
        }
    }
    
    
}
