#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll N, A[int(1e5 + 5)], ans;
ll DP[int(1e5 + 5)][2];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  DP[1][0] = 1; DP[1][1] = 1;
  for (int i = 2; i < N; i++){
    DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
    DP[i][1] = DP[i - 1][0];
  }

  ans = A[0] * (DP[N - 1][0] + DP[N - 1][1]) % MOD;
  for (int i = 1; i < N - 1; i++){
    ll num = DP[i][0] * (DP[N - 1 - i][0] + DP[N - 1 - i][1]) - DP[i][1] * DP[N - 1 - i][0];
    num %= MOD;
    ans += A[i] * num % MOD;
    ans %= MOD;
  }
  ans += A[N - 1] * (DP[N - 1][0] - DP[N - 1][1]) % MOD;
  ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;

  return 0;
}