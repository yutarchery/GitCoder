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

int n, f[int(3e5 + 5)], s[int(3e5 + 5)];
vector<int> t[int(3e5 + 5)];

int ans = 0, m1 = 0, m2 = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f[i] >> s[i];
    t[f[i]].push_back(s[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (t[i].size() == 0) {
      continue;
    }
    sort(t[i].begin(), t[i].end(), greater<int>());
    if (t[i][0] >= m1) {
      swap(m1, m2);
      m1 = t[i][0];
    } else if (t[i][0] >= m2) {
      m2 = t[i][0];
    }

    ans = max(ans, m1 + m2);
    if (t[i].size() >= 2) {
      ans = max(ans, t[i][0] + t[i][1] / 2);
    }
  }

  cout << ans << endl;

  return 0;
}
