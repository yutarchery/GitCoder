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

int n, s, m, l, ans = 1e9;

void solve(int now_s, int now_m, int now_l) {
  if (now_s * 6 + now_m * 8 + now_l * 12 >= n) {
    ans = min(ans, now_s * s + now_m * m + now_l * l);
    return;
  }

  solve(now_s + 1, now_m, now_l);
  solve(now_s, now_m + 1, now_l);
  solve(now_s, now_m, now_l + 1);
  return;
}

int main() {
  cin >> n >> s >> m >> l;
  solve(0, 0, 0);
  cout << ans << endl;

  return 0;
}
