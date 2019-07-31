vector<int> parent;

void initializeDisjointSet(int A){
    parent = vector<int>(A+1,0);
    for(int i=1;i<=A;i++){
        parent[i]=i;
    }
}


int root(int x){
    if(parent[x]==x){
        return x;
    }
    return root(parent[x]);
}

void unite(int x, int y){
    
    int rootofx = root(x);
    int rootofy = root(y);
    
    parent[rootofx] = parent[rootofy];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<pair<int,pair<int,int> > > E;
    for(auto edge:B){
        E.push_back(make_pair(edge[2],make_pair(edge[0],edge[1])));
    }
    sort(E.begin(),E.end());
    
    initializeDisjointSet(A);
    
    int cost = 0;
    for(auto edge: E){
        
        if(root(edge.second.first)!=root(edge.second.second)){
            //both vertices are not in the same set
            //so include this edge
            cost += edge.first;
            //make them in common set
            unite(edge.second.first,edge.second.second);
            
            //cout<<edge[0]<<" "<<edge[1]<<endl;
        }
        
    }
    
    
    return cost;
}
