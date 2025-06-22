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

int n, p[105], ans[105];
Pii p_idx[105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    p_idx[i] = {p[i], i};
  }
  sort(p_idx + 1, p_idx + n + 1, greater<Pii>());

  int now = 1, cnt = 1;
  ans[p_idx[1].second] = 1;
  for (int i = 2; i <= n; i++) {
    if (p_idx[i - 1].first == p_idx[i].first) {
      cnt++;
    } else {
      now += cnt;
      cnt = 1;
    }

    ans[p_idx[i].second] = now;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
