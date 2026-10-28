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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, l;
char s[int(3e5 + 5)];

int last_used[26];
int dp[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    last_used[s[i] - 'a'] = i;
    int now = 1e9;
    for (int j = 0; j < 26; j++) {
      if (last_used[j] == 0) {
        continue;
      }

      if (last_used[j] + l - 1 > i) {
        now = min(now, dp[last_used[j] - 1] + 1);
      }
    }

    dp[i] = now;
    last_used[s[i] - 'a'] = i;
  }
  cout << dp[n] << '\n';

  return 0;
}
