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

int n, a[int(5e5 + 5)], b[int(5e5 + 5)];
ll cnt_a[int(5e5 + 5)], cnt_b[int(5e5 + 5)], ans = 0;
string s[int(5e5 + 5)], t;

int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];

    int t_idx = 0;
    for (int j = 0; j < s[i].length(); j++) {
      if (s[i][j] == t[t_idx]) {
        a[i]++;
        t_idx++;
      }

      if (t_idx >= t.length()) {
        break;
      }
    }
    cnt_a[a[i]]++;

    t_idx = t.length() - 1;
    for (int j = s[i].length() - 1; j >= 0; j--) {
      if (s[i][j] == t[t_idx]) {
        b[i]++;
        t_idx--;
      }

      if (t_idx < 0) {
        break;
      }
    }
    cnt_b[b[i]]++;
  }

  for (int i = t.length(); i >= 0; i--) {
    cnt_b[i] += cnt_b[i + 1];
  }
  for (int i = 0; i <= t.length(); i++) {
    ans += cnt_a[i] * cnt_b[t.length() - i];
  }

  cout << ans << endl;

  return 0;
}
