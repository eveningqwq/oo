/*
  It's obvious that answer is mst.
  Let's use dsu, when joining vertexes a, b you should add sz[b] * weight to a's sons and sz[a] * weight to b's sons. 
  To do this fast let's create new vertex c and add edges c -> a with weight sz[a] * weight, and c -> b with weight sz[b] * weight.
  Now answer is sum to the root, it can easily be  updated when compressing paths.
*/

# include <bits/stdc++.h>

# define y1 aasjdladljskdj
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(2e5) + 5;
const int inf = (int)1e9 + 7;


int p[N * 4]; 	
int sz[N * 4];
ll up[N * 4];

int t, cnt;

pair < int, ll > get(int v){
	if(p[v] == v){
		return make_pair(v, up[v]);
	} else{
		pair < int, ll > to = get(p[v]);
		p[v] = to.first;
		up[v] += to.second;
		return make_pair(p[v], up[v]);
	}
}

vector < pii > edge[10001];

void clr(){
	cnt = 0;
	fill(p, p + N * 4, 0);
	fill(up, up + N * 4, 0);
	fill(sz, sz + N * 4, 0);
	for(int i = 0; i <= 10000; ++i) edge[i].clear();
}

void join(int a, int b, int c){
	a = get(a).first;
	b = get(b).first;
	if(a == b) return;
	++cnt;
	p[cnt] = cnt;
	sz[cnt] = sz[a] + sz[b];
	p[a] = cnt;
	p[b] = cnt;
	up[a] += sz[b] * 1ll * c;
	up[b] += sz[a] * 1ll * c;
}

void solve(int tc){
	printf("Case %d:\n", tc);
	clr();
	int n, m;
	scanf("%d %d", &n, &m);
	cnt = n;
	for(int i = 1; i <= n; ++i){
		p[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i <= m; ++i){
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		edge[c].push_back(make_pair(x, y));
	}
	for(int i = 0; i <= 10000; ++i){
		for(pii j : edge[i]){
			join(j.first, j.second, i);
		}
	}
	for(int i = 1; i <= n; ++i){
		printf("%lld\n", get(i).second);
	}
}

int main(){
	freopen("road.in", "r", stdin);
  scanf("%d", &t);
  for(int i = 1; i <= t; ++i){
  	solve(i);
  }
  return 0;
}
