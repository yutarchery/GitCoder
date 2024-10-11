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

int n;
char s[5005];

ll mods[3] = {MOD, MOD2, MOD3};
ll hash_val[5005][5005][3];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; i + j - 1 <= n; j++) {
      for (int k = 0; k < 3; k++) {
        hash_val[i][j][k] = hash_val[i][j - 1][k] * 27;
        hash_val[i][j][k] += s[i + j - 1] - 'A' + 1;
        hash_val[i][j][k] %= mods[k];
      }
    }
  }

  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    bool now = false;

    for (int i = 1; i <= n; i++) {
      for (int j = i + mid; j + mid - 1 <= n; j++) {
        bool flag = true;
        for (int k = 0; k < 3; k++) {
          if (hash_val[i][mid][k] != hash_val[j][mid][k]) {
            flag = false;
          }
        }

        if (flag) {
          now = true;
          break;
        }
      }
      if (now) {
        break;
      }
    }

    if (now) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << endl;

  return 0;
}
