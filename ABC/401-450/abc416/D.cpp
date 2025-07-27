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

ll n, m, a[int(3e5 + 5)], b[int(3e5 + 5)];

ll solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  multiset<ll> now_b;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    now_b.insert(b[i]);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    auto iter = now_b.lower_bound(m - a[i]);

    if (iter == now_b.end()) {
      iter = now_b.begin();
    }

    ll val = *iter;
    ans += (a[i] + val) % m;
    now_b.erase(iter);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
