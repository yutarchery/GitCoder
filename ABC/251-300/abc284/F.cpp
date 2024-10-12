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

int n;
char t[int(2e6 + 5)];

const ll mods[3] = {MOD, MOD2, MOD3};
ll pows[int(1e6 + 5)][3], hash_val[2][3];

int main() {
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> t[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int k = 0; k < 3; k++) {
      if (i == 0) {
        pows[i][k] = 1;
      } else {
        pows[i][k] = pows[i - 1][k] * 27 % mods[k];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 3; k++) {
      hash_val[0][k] *= 27;
      hash_val[0][k] += t[i] - 'a' + 1;
      hash_val[0][k] %= mods[k];

      hash_val[1][k] *= 27;
      hash_val[1][k] += t[2 * n + 1 - i] - 'a' + 1;
      hash_val[1][k] %= mods[k];
    }
  }

  for (int i = 0; i <= n; i++) {
    bool flag = true;
    for (int k = 0; k < 3; k++) {
      if (hash_val[0][k] != hash_val[1][k]) {
        flag = false;
      }
    }

    if (flag) {
      for (int j = 1; j <= n; j++) {
        cout << t[2 * n + 1 - i - j];
      }
      cout << endl;

      cout << n - i << endl;
      return 0;
    }

    if (i == n) {
      cout << -1 << endl;
      return 0;
    }

    for (int k = 0; k < 3; k++) {
      hash_val[0][k] -= (t[n - i] - 'a' + 1) * pows[i][k];
      hash_val[0][k] += (t[2 * n - i] - 'a' + 1) * pows[i][k];
      hash_val[0][k] %= mods[k];
      if (hash_val[0][k] < 0) {
        hash_val[0][k] += mods[k];
      }

      hash_val[1][k] -= (t[2 * n - i] - 'a' + 1) * pows[n - 1][k] % mods[k];
      hash_val[1][k] *= 27;
      hash_val[1][k] += t[n - i] - 'a' + 1;
      hash_val[1][k] %= mods[k];
      if (hash_val[1][k] < 0) {
        hash_val[1][k] += mods[k];
      }
    }
  }

  cout << -1 << endl;

  return 0;
}
