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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
ll p[3], a[int(2e5 + 5)];

vector<Pli> min_cnt[8];
int orders[7] = {1, 2, 3, 4, 5, 6, 7};
bool visited[int(2e5 + 5)];

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

ll my_lcm(ll a, ll b) {
  ll g = my_gcd(a, b);
  return (a / g) * b;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> p[0] >> p[1] >> p[2];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < 8; i++) {
    ll now = 1, rest = i;
    for (int j = 0; j < 3; j++) {
      if (rest % 2 == 1) {
        now = my_lcm(now, p[j]);
      }
      rest /= 2;
    }

    for (int j = 1; j <= n; j++) {
      min_cnt[i].push_back({(now - a[j] % now) % now, j});
    }
  }

  for (int i = 1; i < 8; i++) {
    sort(min_cnt[i].begin(), min_cnt[i].end());
  }

  ll ans = 4e18;
  do {
    if (((orders[0] | orders[1]) | orders[2]) != 7) {
      continue;
    }

    int now = 0;
    ll res = 0;
    vector<int> used;

    for (int i = 0; i < min(3, n); i++) {
      for (Pli m : min_cnt[orders[i]]) {
        if (visited[m.second]) {
          continue;
        }
        visited[m.second] = true;
        used.push_back(m.second);
        res += m.first;
        now |= orders[i];
        break;
      }

      if (now == 7) {
        break;
      }
    }

    for (int u : used) {
      visited[u] = false;
    }

    if (now == 7) {
      ans = min(ans, res);
    }
  } while (next_permutation(orders, orders + 7));

  cout << ans << '\n';

  return 0;
}
