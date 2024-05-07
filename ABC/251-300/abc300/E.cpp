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

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

ll frac(ll a, ll b) { return a * my_pow(b, MOD2 - 2) % MOD2; }

const ll p = frac(1, 5);
ll dp[105][105][105];
bool visited[105][105][105];

ll solve(int i, int j, int k) {
  if (i < 0 || j < 0 || k < 0) {
    return 0;
  }
  if (i == 0 && j == 0 && k == 0) {
    return 1;
  }
  if (visited[i][j][k]) {
    return dp[i][j][k];
  }

  visited[i][j][k] = true;

  ll ans = 0;
  ans += p * solve(i - 1, j, k) % MOD2;
  ans += p * solve(i, j - 1, k) % MOD2;
  ans += p * solve(i, j, k - 1) % MOD2;
  ans += p * solve(i - 1, j - 1, k) % MOD2;
  ans += p * solve(i - 2, j, k) % MOD2;

  return dp[i][j][k] = ans % MOD2;
}

int main() {
  ll n;
  cin >> n;

  int i = 0, j = 0, k = 0;
  while (n % 2 == 0) {
    n /= 2;
    i++;
  }
  while (n % 3 == 0) {
    n /= 3;
    j++;
  }
  while (n % 5 == 0) {
    n /= 5;
    k++;
  }

  if (n == 1) {
    cout << solve(i, j, k) << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
