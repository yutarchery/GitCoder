#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int t;

void solve() {
  ll x[3], sum = 0;
  for (int i = 0; i < 3; i++) {
    cin >> x[i];
    sum += x[i];
  }

  if (sum % 3 != 0) {
    cout << -1 << endl;
    return;
  }

  ll ans = 0;
  for (int i = 0; i < 3; i++) {
    if ((x[i] - sum / 3) % 2 != 0) {
      cout << -1 << endl;
      return;
    }
    ans += abs(x[i] - sum / 3) / 2;
  }
  cout << ans / 2 << endl;

  return;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}