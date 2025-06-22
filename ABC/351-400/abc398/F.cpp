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
  }
  if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

int n;
string s;
char c[int(5e5 + 5)];

ll hashes[int(5e5 + 5)][3], rev_hashes[int(5e5 + 5)][3];
const ll mods[3] = {MOD, MOD2, MOD3};
const ll pows[3] = {61, 71, 97};

bool judge(int l_start, int l_end, int r_start) {
  if (l_start <= 0) {
    return false;
  }

  ll tmp[3] = {};
  for (int j = 0; j < 3; j++) {
    tmp[j] = hashes[l_end][j];
    tmp[j] -= hashes[l_start - 1][j] *
              my_pow(pows[j], l_end - l_start + 1, mods[j]) % mods[j];
    tmp[j] %= mods[j];
    if (tmp[j] < 0) {
      tmp[j] += mods[j];
    }
  }

  for (int j = 0; j < 3; j++) {
    if (tmp[j] != rev_hashes[r_start][j]) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> s;
  n = s.length();
  for (int i = 1; i <= n; i++) {
    c[i] = s[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      hashes[i][j] = hashes[i - 1][j] * pows[j] + (c[i] - 'A' + 1);
      hashes[i][j] %= mods[j];
    }
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 3; j++) {
      rev_hashes[i][j] = rev_hashes[i + 1][j] * pows[j] + (c[i] - 'A' + 1);
      rev_hashes[i][j] %= mods[j];
    }
  }

  for (int i = 1; i <= n; i++) {
    if (judge(i - (n - i + 1), i - 1, i)) {
      for (int j = 1; j <= i - 1; j++) {
        cout << c[j];
      }
      for (int j = i - 1; j >= 1; j--) {
        cout << c[j];
      }
      cout << endl;
      return 0;
    }

    if (judge(i - (n - i), i - 1, i + 1)) {
      for (int j = 1; j <= i - 1; j++) {
        cout << c[j];
      }
      cout << c[i];
      for (int j = i - 1; j >= 1; j--) {
        cout << c[j];
      }
      cout << endl;
      return 0;
    }
  }

  return 0;
}
