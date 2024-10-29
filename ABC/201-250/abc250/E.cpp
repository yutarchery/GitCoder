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

int n, q, x[int(2e5 + 5)], y[int(2e5 + 5)];
ll a[int(2e5 + 5)], b[int(2e5 + 5)];

map<ll, bool> visited_a, visited_b;
ll cnt_a[int(2e5 + 5)], cnt_b[int(2e5 + 5)];
const ll mods[3] = {MOD, MOD2, MOD3};
ll hash_a[int(2e5 + 5)][3], hash_b[int(2e5 + 5)][3];
ll sum_a[int(2e5 + 5)][3], sum_b[int(2e5 + 5)][3];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 1; i <= n; i++) {
    cnt_a[i] = cnt_a[i - 1];
    cnt_b[i] = cnt_b[i - 1];
    for (int j = 0; j < 3; j++) {
      hash_a[i][j] = hash_a[i - 1][j];
      sum_a[i][j] = sum_a[i - 1][j];
      hash_b[i][j] = hash_b[i - 1][j];
      sum_b[i][j] = sum_b[i - 1][j];
    }

    if (!visited_a[a[i]]) {
      cnt_a[i]++;
      for (int j = 0; j < 3; j++) {
        ll h = a[i] * (a[i] + ll(1e9 + 1)) % mods[j];
        h %= mods[j];
        h *= (a[i] + ll(1e9 + 3)) * (a[i] + ll(1e9 + 5)) % mods[j];
        h %= mods[j];
        hash_a[i][j] = hash_a[i - 1][j] * h % mods[j];
        sum_a[i][j] = (sum_a[i - 1][j] + h) % mods[j];
      }
      visited_a[a[i]] = true;
    }
    if (!visited_b[b[i]]) {
      cnt_b[i]++;
      for (int j = 0; j < 3; j++) {
        ll h = b[i] * (b[i] + ll(1e9 + 1)) % mods[j];
        h %= mods[j];
        h *= (b[i] + ll(1e9 + 3)) * (b[i] + ll(1e9 + 5)) % mods[j];
        h %= mods[j];

        hash_b[i][j] = hash_b[i - 1][j] * h % mods[j];
        sum_b[i][j] = (sum_b[i - 1][j] + h) % mods[j];
      }
      visited_b[b[i]] = true;
    }
  }

  for (int i = 1; i <= q; i++) {
    if (cnt_a[x[i]] != cnt_b[y[i]]) {
      No();
      continue;
    }

    bool flag = true;
    for (int j = 0; j < 3; j++) {
      if (hash_a[x[i]][j] != hash_b[y[i]][j]) {
        flag = false;
      }
      if (sum_a[x[i]][j] != sum_b[y[i]][j]) {
        flag = false;
      }
    }

    if (flag) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}
