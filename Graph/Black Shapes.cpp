void VisitDFS(vector<string> &A, int i, int j){
    
    if(A[i][j]=='O')
        return;
    
    A[i][j] = 'O';  //make that x -> 0
    
    if(i>0){
        VisitDFS(A,i-1,j);  //top
    }
    if(j<A[0].length()-1){
        VisitDFS(A,i,j+1);  //right
    }
    if(i<A.size()-1){
        VisitDFS(A,i+1,j);  //bottom
    }
    if(j>0){
        VisitDFS(A,i,j-1);  //left
    }
}

int Solution::black(vector<string> &A) {
    
    //we have to find number of components
    if(A.empty()){
        return 0;
    }
    
    int component=0;
    for(auto i=0;i<A.size();i++){
        for(auto j=0;j<A[0].length();j++){
            if(A[i][j]=='X'){
                VisitDFS(A,i,j);
                component++;
            }
        }
    }
    
    return component;
}
