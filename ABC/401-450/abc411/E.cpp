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

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return my_pow(a, n - 1, mod) * a % mod;
  }
}

int n;
ll a[int(1e5 + 5)][6];

vector<ll> vals;
map<ll, bool> visited;
map<ll, int> idx;

vector<int> idxes[int(6e5 + 5)];
ll p[int(6e5 + 5)], used_count[int(1e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> a[i][j];
      if (!visited[a[i][j]]) {
        visited[a[i][j]] = true;
        vals.push_back(a[i][j]);
      }
    }
  }
  vals.push_back(0);
  sort(vals.begin(), vals.end());

  for (int i = 0; i < vals.size(); i++) {
    idx[vals[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      idxes[idx[a[i][j]]].push_back(i);
    }
  }

  bool flag = false;
  int cnt = 0;
  ll now = 0;
  for (int i = 1; i < vals.size(); i++) {
    for (int j : idxes[i]) {
      if (used_count[j] == 0) {
        cnt++;
      }
      used_count[j]++;

      if (flag) {
        now *= used_count[j] * my_pow(used_count[j] - 1, MOD2 - 2, MOD2) % MOD2;
        now %= MOD2;
      }
    }

    if (!flag && cnt == n) {
      now = 1;
      for (int j = 1; j <= n; j++) {
        now *= used_count[j];
        now %= MOD2;
      }
      flag = true;
    }

    p[i] = now;
  }

  ll ans = 0;
  for (int i = 1; i < vals.size(); i++) {
    ans += vals[i] * (p[i] - p[i - 1]) % MOD2;
    ans %= MOD2;
    if (ans < 0) {
      ans += MOD2;
    }
  }
  ans *= my_pow(my_pow(6, n, MOD2), MOD2 - 2, MOD2);
  ans %= MOD2;
  cout << ans << endl;

  return 0;
}
