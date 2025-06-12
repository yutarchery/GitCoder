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
  ll res = 1;
  while (n--) {
    res *= a;
  }
  return res;
}

int n;
string s;

int a[15][int(16e5 + 5)], dp[15][int(16e5 + 5)];
bool visited[15][int(16e5 + 5)];

int solve(int i, int j) {
  if (visited[i][j]) {
    return dp[i][j];
  }

  visited[i][j] = true;
  if (i == n) {
    return dp[i][j] = 1;
  }

  vector<int> now;
  for (int k = 0; k < 3; k++) {
    if (a[i + 1][3 * j + k] == a[i][j]) {
      now.push_back(solve(i + 1, 3 * j + k));
    }
  }
  sort(now.begin(), now.end());

  int res = 0;
  for (int i = 0; i < (int(now.size()) + 1) / 2; i++) {
    res += now[i];
  }

  return dp[i][j] = res;
}

int main() {
  cin >> n;
  cin >> s;

  for (int j = 0; j < my_pow(3, n); j++) {
    a[n][j] = s[j] - '0';
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < my_pow(3, i); j++) {
      int sum = 0;
      for (int k = 0; k < 3; k++) {
        sum += a[i + 1][3 * j + k];
      }

      if (sum <= 1) {
        a[i][j] = 0;
      } else {
        a[i][j] = 1;
      }
    }
  }

  cout << solve(0, 0) << endl;

  return 0;
}
