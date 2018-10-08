// convert chebyshev distance to manhattan, the rest is easy

# include <bits/stdc++.h>

# define y1 aasjdladljskdj

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(2e6) + 5;
const int inf = (int)1e9 + 7;

int n;
int x[N], y[N];
ll ans[N];

void doit(){
  vector < int > id;
  for(int i = 1; i <= n; ++i){
    id.push_back(i);
  }
  sort(id.begin(), id.end(), [](int i, int j){
    return x[i] < x[j];
  });
  for(int t = 0; t < 2; ++t){
    ll sum = 0;
    for(int i = 0; i < (int)id.size(); ++i){
      ans[id[i]] += t == 0 ? x[id[i]] * 1ll * i - sum : sum - x[id[i]] * 1ll * i;
      sum += x[id[i]];
    }
    reverse(id.begin(), id.end());
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d %d", x + i, y + i);
    int f = x[i], s = y[i];
    x[i] = (f - s);
    y[i] = (f + s);
  }
  doit();
  for(int i = 1; i <= n; ++i){
    swap(x[i], y[i]);
  }
  doit();
  ll tot = (ll)1e18;
  for(int i = 1; i <= n; ++i){
    tot = min(ans[i], tot);
  }
  printf("%lld\n", tot / 2);
  return 0;
}
