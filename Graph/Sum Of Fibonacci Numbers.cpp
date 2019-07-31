int Solution::fibsum(int A) {
    //Non-Graph Approach
    
    vector<int> fibs(1,1);
    fibs.push_back(1);
    // 1 1  => initial two numbers of fib
    
    while(fibs.back()<A){
        fibs.push_back(fibs[fibs.size()-1] + fibs[fibs.size()-2]);
    }
    if(fibs.back()>A){
        fibs.pop_back();
    }
    // now we have fibs upto number N;
    
    //     see because here we have coins as fibonacci numbers, we can actually use greedy to add coins to sum up to N.
    
    // Proof:
    //     let a,b,c are fibonacci where c = a+b;
    //     so instead of adding a and b into beg of coins we can add directly c. 
    //     so keep adding higher coins as you can. this gives minimum number of coins in bag 
    //     which sum up to N.
    
    int count=0;
    while(A && !fibs.empty()){
        count += A/fibs.back();
        
        A = A%fibs.back();
        
        fibs.pop_back();
        
    }
    
    return count;
    
}
