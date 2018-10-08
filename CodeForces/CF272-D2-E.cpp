/*
  Change the color of vertex v if there is >= 2 enemies with same color. This will work O(N+M) because number of such edges will decrease when switching colors.
*/

# include <bits/stdc++.h>

# define y1 aasjdladljskdj

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(2e6) + 5;
const int inf = (int)1e9 + 7;

int n, m;
int c[N], u[N];
vector < int > g[N];

void dfs(int v){
  int t = 0;
  u[v] = 1;
  for(int i : g[v]){
    t += c[i] == c[v];
  }
  if(t >= 2){
    c[v] ^= 1;
    for(int i : g[v]){
      dfs(i);
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1; i <= n; ++i){
    if(!u[i]){
      dfs(i);
    }
  }
  for(int i = 1; i <= n; ++i){
    printf("%d", c[i]);
  }
  return 0;
}
