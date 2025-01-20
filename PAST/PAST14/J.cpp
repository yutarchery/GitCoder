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

int h, w;
string s[int(4e5 + 5)], t[int(4e5 + 5)];

ll a[int(4e5 + 5)], b[int(4e5 + 5)];
ll hash_a, hash_b, root = 1;

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    cin >> t[i];
  }

  for (int j = 0; j < w; j++) {
    ll now_s = 0, now_t = 0;
    for (int i = 0; i < h; i++) {
      a[j] = (a[j] * 2) % MOD2;
      b[j] = (b[j] * 2) % MOD2;

      if (s[i][j] == '#') {
        a[j]++;
      }
      if (t[i][j] == '#') {
        b[j]++;
      }
    }

    a[j] %= MOD2;
    b[j] %= MOD2;

    hash_a = ((hash_a * (w * 10)) + a[j]) % MOD;
    hash_b = ((hash_b * (w * 10)) + b[j]) % MOD;
  }
  for (int j = 0; j < w - 1; j++) {
    root = (root * w * 10) % MOD;
  }

  if (hash_a == hash_b) {
    Yes();
    return 0;
  }

  for (int j = 0; j < w; j++) {
    hash_a = (hash_a - (a[j] * root)) % MOD;
    if (hash_a < 0) {
      hash_a += MOD;
    }
    hash_a = (hash_a * (w * 10) + a[j]) % MOD;

    if (hash_a == hash_b) {
      Yes();
      return 0;
    }
  }

  No();

  return 0;
}
