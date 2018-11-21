
/*
	Let's count cnt[x] = number of elements divisible by x. Can be easily calculated in 10000*log(10000).
	Now let's calculate dp[x] = number of subsets with gcd x. It's cnk(cnt[x], 4) - dp[2 * x] - dp[3 * x] and so on.
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

int n;
ll dp[10001];

ll get(ll n){
	if(n < 4) return 0;
	return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

int main(){
	while(~scanf("%d", &n)){
		for(int i = 1; i <= 10000; ++i) dp[i] = 0;
		for(int i = 1; i <= n; ++i){
			int x;
			scanf("%d", &x);
			dp[x]++;
		}
		for(int i = 1; i <= 10000; ++i){
			for(int j = i + i; j <= 10000; j += i){
				dp[i] += dp[j];
			}
		}
		for(int i = 10000; i >= 1; --i){
			dp[i] = get(dp[i]);
			for(int j = i + i; j <= 10000; j += i){
				dp[i] -= dp[j];
			}
		}
		printf("%lld\n", dp[1]);
	}
  return 0;
}
