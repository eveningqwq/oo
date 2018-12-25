# include <bits/stdc++.h>

# define y1 aasjdladljskdj
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(4e5) + 5;
const int inf = (int)1e9 + 7;

int n, k;
int a[N];
set < pair < ll, int > > s;
vector < ll > e;

int main(){
  scanf("%d %d", &n, &k);
  ll add = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    if(a[i] < 0){
      add += a[i];
      a[i] = -a[i];
    }
  }
  sort(a + 1, a + 1 + n);
  s.insert(make_pair(0ll, 0));
  while(k--){
    auto v = *s.begin();
    s.erase(s.begin());
    printf("%lld\n", v.first + add);
    if(v.second < n){
      s.insert(make_pair(v.first + a[v.second + 1], v.second + 1));
      s.insert(make_pair(v.first - a[v.second] + a[v.second + 1], v.second + 1));
    }
  }

  return 0;
}
