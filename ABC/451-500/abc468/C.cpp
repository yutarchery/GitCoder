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

int n, p[15], q[15], now[15];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }
  for (int i = 1; i <= n; i++) {
    now[i] = i;
  }

  int ans = 0;
  do {
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (p[i] == now[i]) {
        if (i == n) {
          flag = false;
        }
        continue;
      }
      if (p[i] < now[i]) {
        break;
      } else {
        flag = false;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (q[i] == now[i]) {
        if (i == n) {
          flag = false;
        }
        continue;
      }
      if (now[i] < q[i]) {
        break;
      } else {
        flag = false;
        break;
      }
    }

    if (flag) {
      ans++;
    }
  } while (next_permutation(now + 1, now + n + 1));

  cout << ans << '\n';

  return 0;
}
