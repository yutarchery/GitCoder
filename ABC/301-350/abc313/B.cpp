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

int n, m, a, b, cnt, ans;
bool top[55], bottom[55];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    top[a] = true;
    bottom[b] = true;
  }

  for (int i = 1; i <= n; i++) {
    if (top[i] && !bottom[i]) {
      cnt++;
      ans = i;
    } else if (!top[i] && !bottom[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  if (cnt == 1) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
