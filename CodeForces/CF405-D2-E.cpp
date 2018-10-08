/*
  Try to match all v's sons' edges, and then create pairs like u, v, w. If there is anything left match it with par[v]'s son's edges.
*/

# include <bits/stdc++.h>

# define y1 aasjdladljskdj

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(2e5) + 5;
const int inf = (int)1e9 + 7;

int n, m;
vector < pii > g[N];
int ban[N];

int dfs(int v){
  vector < int > to;
  for(pii i : g[v]){
    if(ban[i.second]){
      continue;
    }
    ban[i.second] = 1;
    to.push_back(i.first);
  }
  vector < int > all;
  for(int i : to){
    int w = dfs(i);
    if(w == 0){
      all.push_back(i);
    } else{
      printf("%d %d %d\n", w, i, v);
    }
  }
  while((int)all.size() >= 2){
    printf("%d %d %d\n", all.back(), v, all[(int)all.size() - 2]);
    all.pop_back(), all.pop_back();
  }
  return all.empty() ? 0 : all.back();
}

int main(){
  scanf("%d %d", &n, &m);
  if(m & 1){
    printf("No solution");
    return 0;
  }
  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back({y, i});
    g[y].push_back({x ,i});
  }
  dfs(1);

  return 0;
}
