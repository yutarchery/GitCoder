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
string a, b;

const ll p = 2;
const ll mods[3] = {MOD, MOD2, MOD3};

int solve() {
  cin >> a;
  cin >> b;
  n = a.length();

  ll diff[3] = {};
  for (int j = 0; j < 3; j++) {
    diff[j] = my_pow(p, n - 1, mods[j]);
  }

  array<ll, 3> hash_a = {0, 0, 0}, hash_b = {0, 0, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      hash_a[j] = hash_a[j] * p % mods[j];
      if (a[i] == '1') {
        hash_a[j]++;
      }
      hash_b[j] = hash_b[j] * p % mods[j];
      if (b[i] == '1') {
        hash_b[j]++;
      }
    }
  }

  if (hash_a == hash_b) {
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      for (int j = 0; j < 3; j++) {
        hash_a[j] -= diff[j];
        hash_a[j] %= mods[j];
        if (hash_a[j] < 0) {
          hash_a[j] += mods[j];
        }
      }
    }

    for (int j = 0; j < 3; j++) {
      hash_a[j] *= p;
      hash_a[j] %= mods[j];
    }

    if (a[i] == '1') {
      for (int j = 0; j < 3; j++) {
        hash_a[j]++;
        hash_a[j] %= mods[j];
      }
    }

    if (hash_a == hash_b) {
      return i + 1;
    }
  }

  return -1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
