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

int n, m, s[int(2e5 + 5)], t[int(2e5 + 5)];
bool used[2];
bool zero = false, one = false;

int main() {
  cin >> n >> m;

  int dist = n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] != s[0]) {
      dist = min(dist, min(i, n - i));
    }

    used[s[i]] = true;
  }

  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  int ans = 0, now = s[0];
  bool flag = false;
  for (int i = 0; i < m; i++) {
    if (!used[t[i]]) {
      cout << -1 << endl;
      return 0;
    }

    if (t[i] == now) {
      ans++;
    } else {
      if (flag) {
        ans += 2;
      } else {
        ans += dist + 1;
        flag = true;
      }
    }
    now = t[i];
  }
  cout << ans << endl;

  return 0;
}