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

ll Pow(ll A, ll N){
  if (N == 0) return 1;
  if (N % 2 == 0) return Pow(A * A % MOD, N / 2);
  else return Pow(A * A % MOD, N / 2) * A % MOD;
}

ll N, K, A[int(1e5 + 5)];
ll nCk[int(1e5 + 5)];

int main(){
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);

  nCk[K - 1] = 1;
  for (ll i = K; i <= N - 1; i++){
    nCk[i] = nCk[i - 1] * i % MOD;
    nCk[i] *= Pow(i - K + 1, MOD - 2);
    nCk[i] %= MOD;
  }

  ll ans = 0;
  for (int i = 0; i < N; i++){
    ll now = A[i] * nCk[N - 1 - i] % MOD;
    ans -= now; ans %= MOD;
  }
  for (int i = N - 1; i >= 0; i--){
    ll now = A[i] * nCk[i] % MOD;
    ans += now; ans %= MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << endl;

  return 0;
}