/*
  Answer is TAK if there is >= 1 number equal to n, >=2 number greater or equal to n - 1, and so on. 
  Let's create segtree where we store count - numbers_needed, now answer is TAK if minimum is >= 0.
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
 
struct segtree{
  int mn[N * 4];
  int add[N * 4];
 
  void push(int v){
    if(add[v] != 0){
      mn[v * 2] += add[v];
      mn[v * 2 + 1] += add[v];
      add[v * 2] += add[v];
      add[v * 2 + 1] += add[v];
      add[v] = 0;
    }
  }
 
  void inc(int v, int tl, int tr, int l, int r, int x){
    if(l > r) return;
    if(l == tl && r == tr){
      mn[v] += x;
      add[v] += x;
      return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    inc(v * 2, tl, tm, l, min(r, tm), x);
    inc(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
  }
  int get(int v, int tl, int tr, int p){
    if(tl == tr){
      return mn[v];
    }
    int tm = (tl + tr) >> 1;
    push(v);
    if(p <= tm){
      return get(v * 2, tl, tm, p);
    } else{
      return get(v * 2 + 1, tm + 1, tr, p);
    }
  }
 
}tr;
 
int n;
int a[N];
 
int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    tr.inc(1, 1, n, i, i, -(n - i + 1));
  }
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    tr.inc(1, 1, n, 1, a[i], 1);
  }
  int m;
  scanf("%d", &m);
  if(tr.mn[1] >= 0){
    printf("TAK\n");
  } else{
    printf("NIE\n");
  }
  for(int i = 1; i <= m; ++i){
    int p, v;
    scanf("%d %d", &p, &v);
    tr.inc(1, 1, n, 1, a[p], -1);
    a[p] = v;
    tr.inc(1, 1, n, 1, a[p], 1);
    if(tr.mn[1] >= 0){
      printf("TAK\n");
    } else{
      printf("NIE\n");
    }
  }
  return 0;
}
 
