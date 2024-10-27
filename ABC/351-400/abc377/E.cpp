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

ll n, k, p[int(2e5 + 5)];

int cycle_count = 0;
vector<int> cycles[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
int ans[int(2e5 + 5)];

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    cycle_count++;
    cycles[cycle_count].push_back(i);
    visited[i] = true;
    int now = p[i];
    while (now != i) {
      cycles[cycle_count].push_back(now);
      visited[now] = true;
      now = p[now];
    }
  }

  for (int i = 1; i <= cycle_count; i++) {
    ll l = cycles[i].size(), p = my_pow(2, k, l);
    for (int j = 0; j < l; j++) {
      ans[cycles[i][j]] = cycles[i][(j + p) % l];
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
