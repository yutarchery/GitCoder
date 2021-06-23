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

ll N, Q, A[int(1e5 + 5)];

ll cnt(ll num){
  if (num >= A[N]) return num - N;
  ll L = 0, R = N;
  while (R - L > 1){
    ll mid = (L + R) / 2;
    if (num < A[mid]) R = mid;
    else L = mid;
  }
  return num - L;
}

int solve(){
  ll K; cin >> K;

  ll L = 0, R = ll(1e18) + K + 1;
  while (R - L > 1){
    ll mid = (L + R) / 2;
    if (cnt(mid) <= K - 1) L = mid;
    else R = mid;
  }
  cout << R << endl;
  return 0;
}

int main(){
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) cin >> A[i];
  sort(A, A + N + 1);
  for (int i = 0; i < Q; i++) solve();

  return 0;
}