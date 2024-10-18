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

int n, a[int(2e5 + 5)], q, num, x, y;

map<int, int> before_num, next_num;
vector<int> ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    before_num[a[i]] = a[i - 1];
    next_num[a[i - 1]] = a[i];
  }

  cin >> q;
  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> x >> y;

      int z = next_num[x];
      next_num[x] = y;
      before_num[z] = y;

      before_num[y] = x;
      next_num[y] = z;
    } else {
      cin >> x;

      int b = before_num[x], nxt = next_num[x];
      next_num[b] = nxt;
      before_num[nxt] = b;
    }
  }

  int now = next_num[0];
  while (now != 0) {
    ans.push_back(now);
    now = next_num[now];
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
