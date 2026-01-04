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
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

ll n;
int ans = 0;

void solve(ll now = 0, bool three = false, bool five = false,
           bool seven = false) {
  if (now > n) {
    return;
  }
  if (three && five && seven) {
    ans++;
  }

  solve(now * 10 + 3, true, five, seven);
  solve(now * 10 + 5, three, true, seven);
  solve(now * 10 + 7, three, five, true);
  return;
}

int main() {
  cin >> n;
  solve();
  cout << ans << endl;

  return 0;
}
