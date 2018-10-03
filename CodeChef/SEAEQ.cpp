/*
  Fix the length of segment, and calculate the rest with dp and combinatorics.
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
const int E = 501 * 501;

int d[501][E];
int s[501][E];
int c[501][501], f[501];

void calc(){
  d[1][0] = 1;
  for(int i = 0; i < E; ++i){
    s[1][i] = 1;
  }
  for(int i = 2; i <= 500; ++i){
    for(int j = 0, e = i * (i - 1) / 2; j <= e; ++j){
      d[i][j] = s[i - 1][j] - (j - i < 0 ? 0 : s[i - 1][j - i]);
      if(d[i][j] < 0) d[i][j] += inf;
    }
    for(int j = 0; j < E; ++j){
      s[i][j] = (!j ? 0 : s[i][j - 1]) + d[i][j];
      if(s[i][j] >= inf) s[i][j] -= inf;
    }
  }
  for(int i = 0; i <= 500; ++i){
    c[i][0] = c[i][i] = 1;
    f[i] = (i == 0 ? 1 : f[i - 1] * 1ll * i % inf);
    for(int j = 1; j < i; ++j){
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      if(c[i][j] >= inf) c[i][j] -= inf;
    }
  }
}

int main(){
  calc();
  int t;
  scanf("%d", &t);
  while(t--){
    int n, p;
    scanf("%d %d", &n, &p);
    p = min(p, E - 1);
    int ans = 0;
    for(int len = 1; len <= n; ++len){
      int now = c[n][len] * 1ll * c[n][len] % inf;
      now = now * 1ll * (n - len + 1) % inf;
      now = now * 1ll * s[len][p] % inf;
      now = now * 1ll * (f[n - len] * 1ll * f[n - len] % inf) % inf;
      ans += now;
      if(ans >= inf) ans -= inf;
    }
    printf("%d\n", ans);
  }
  return 0;
}
