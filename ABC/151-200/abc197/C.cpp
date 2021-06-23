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

int N;
ll ans, A[20];

int solve(int num){
  ll now = 0, res = 0;
  for (int i = 0; i < N; i++){
    now |= A[i];
    if (num % 2 != 0){
      res ^= now;
      now = 0;
    }
    num /= 2;
  }
  res ^= now;
  ans = min(res, ans);
  return 0;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    ans ^= A[i];
  }

  for (int i = 0; i < (1 << N); i++){
    solve(i);
  }
  cout << ans << endl;

  return 0;
}