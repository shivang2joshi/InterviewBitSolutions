#define MAXN 100005
#define BLACK 0
#define BLUE 1
#define GREY 2
vector<int> g[MAXN];

void check_cycle(int u, int visited[],bool &hasCycle) {
  visited[u] = BLUE;
  for(auto v : g[u]) {
    if(visited[v] == BLACK) {
      check_cycle(v, visited, hasCycle);
    } else if(visited[v] == BLUE) {
      hasCycle = true;
    }
  }
  visited[u] = GREY;
}

int Solution::solve(int N, vector<int> &B, vector<int> &C) {
    bool hasCycle = false;
    int visited[MAXN] = {0};
    for(int i = 1;i <= N; i++) {
      g[i].clear();
    }
    for(int i=0; i<B.size(); i++) {
      g[B[i]].push_back(C[i]);
    }
    for(int i = 1; i <= N; i++) {
      if(visited[i] == BLACK) {
        check_cycle(i, visited, hasCycle);
        if(hasCycle) {
          break;
        }
      }
    }
    return !hasCycle;
}
