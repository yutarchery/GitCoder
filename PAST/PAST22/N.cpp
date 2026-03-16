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

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

ll n, k;
char s[int(5e5 + 5)];

const ll pows[3] = {71, 97, 101};

ll hash_head[int(5e5 + 5)][3], hash_bottom[int(5e5 + 5)][3];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      hash_head[i][j] = hash_head[i - 1][j] * pows[j] + (s[i] - 'A' + 1);
      hash_head[i][j] %= MOD2;
    }
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 3; j++) {
      hash_bottom[i][j] = hash_bottom[i + 1][j] +
                          my_pow(pows[j], n - i, MOD2) * (s[i] - 'A' + 1);
      hash_bottom[i][j] %= MOD2;
    }
  }

  ll ans = n * k;
  for (int i = 1; i <= n - 1; i++) {
    bool flag = true;

    for (int j = 0; j < 3; j++) {
      if (hash_head[i][j] != hash_bottom[n + 1 - i][j]) {
        flag = false;
      }
    }

    if (flag) {
      ans = min(ans, n * k - ll(i) * (k - 1));
    }
  }
  cout << ans << endl;

  return 0;
}
