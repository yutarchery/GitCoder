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
string s;
bool now[int(2e5 + 5)];
ll dp[int(2e5 + 5)], ans = 0;
vector<int> v;

void solve(int num) {
  fill(now, now + num, false);
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      now[i % num] = true;
    }
  }

  dp[num] = 1;
  for (int i = 0; i < num; i++) {
    if (!now[i]) {
      dp[num] *= 2;
      dp[num] %= MOD2;
    }
  }

  return;
}

int main() {
  cin >> n;
  cin >> s;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      solve(i);
      v.push_back(i);
    }
  }

  for (int i = 0; i < v.size(); i++) {
    ans += dp[v[i]];
    ans %= MOD2;
    for (int j = i + 1; j < v.size(); j++) {
      if (v[j] % v[i] == 0) {
        dp[v[j]] -= dp[v[i]];
      }
    }
  }

  if (ans < 0) {
    ans += MOD2;
  }
  cout << ans << endl;

  return 0;
}
