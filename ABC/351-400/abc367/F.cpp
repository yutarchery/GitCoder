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
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

int n, q;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];

ll my_hash[int(1e6 + 5)][2];
ll sum_a[int(2e5 + 5)][2], sum_b[int(2e5 + 5)][2];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= int(1e6); i++) {
    my_hash[i][0] = my_pow(i, MOD - 1 - i, MOD);
    my_hash[i][1] = my_pow(i, MOD2 - 1 - i, MOD2);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      sum_a[i][j] = sum_a[i - 1][j] + my_hash[a[i]][j];
      sum_b[i][j] = sum_b[i - 1][j] + my_hash[b[i]][j];
    }
  }

  for (int i = 1; i <= q; i++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    bool flag = true;
    for (int j = 0; j < 2; j++) {
      if (sum_a[r1][j] - sum_a[l1 - 1][j] != sum_b[r2][j] - sum_b[l2 - 1][j]) {
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
