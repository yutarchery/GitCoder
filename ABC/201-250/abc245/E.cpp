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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)], d[int(2e5 + 5)];
Pii ab[int(2e5 + 5)], cd[int(2e5 + 5)];

multiset<int> rest_d;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    ab[i] = {a[i], b[i]};
  }
  sort(ab + 1, ab + n + 1, greater<Pii>());

  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> d[i];
    cd[i] = {c[i], d[i]};
  }
  sort(cd + 1, cd + m + 1, greater<Pii>());

  int c_idx = 1;
  for (int i = 1; i <= n; i++) {
    while (cd[c_idx].first >= ab[i].first) {
      rest_d.insert(cd[c_idx].second);
      c_idx++;
    }

    auto iter = rest_d.lower_bound(ab[i].second);
    if (iter == rest_d.end()) {
      No();
      return 0;
    }
    rest_d.erase(iter);
  }

  Yes();

  return 0;
}
