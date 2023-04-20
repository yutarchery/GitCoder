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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, a[25][25];
ll dp[1 << 21];

int bit_count(int num) {
  int res = 0;
  while (num > 0) {
    if (num % 2 == 1) {
      res++;
    }
    num /= 2;
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  dp[0] = 1;
  for (int k = 0; k < (1 << n); k++) {
    int i = bit_count(k);
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        continue;
      }
      if ((k & (1 << j)) > 0) {
        continue;
      }

      dp[(k | (1 << j))] += dp[k];
      dp[(k | (1 << j))] %= mod;
    }
  }
  cout << dp[(1 << n) - 1] << endl;

  return 0;
}