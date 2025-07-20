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

int n, k;
vector<int> ans, rest;

int main() {
  cin >> n >> k;

  if (n % 2 == 0) {
    ans.push_back(n / 2);
    for (int i = 1; i <= n; i++) {
      if (i == n / 2) {
        for (int j = 1; j <= k - 1; j++) {
          rest.push_back(i);
        }
      } else {
        for (int j = 1; j <= k; j++) {
          rest.push_back(i);
        }
      }
    }
  } else {
    for (int j = 1; j <= k; j++) {
      ans.push_back((n + 1) / 2);
    }
    ans.push_back(n / 2);

    for (int i = 1; i <= n; i++) {
      if (i == (n + 1) / 2) {
        continue;
      }
      if (i == n / 2) {
        for (int j = 1; j <= k - 1; j++) {
          rest.push_back(i);
        }
      } else {
        for (int j = 1; j <= k; j++) {
          rest.push_back(i);
        }
      }
    }
  }

  sort(rest.begin(), rest.end(), greater<int>());
  for (int i : rest) {
    ans.push_back(i);
  }
  for (int i = 0; i < n * k; i++) {
    cout << ans[i] << (i == n * k - 1 ? '\n' : ' ');
  }

  return 0;
}
