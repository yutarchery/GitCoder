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

int n, q, parent[int(1e5 + 5)], child[int(1e5 + 5)];

int display(int start) {
  int now = start;
  while (parent[now] != now) {
    now = parent[now];
  }

  vector<int> ans;
  ans.push_back(now);
  while (child[now] != now) {
    now = child[now];
    ans.push_back(now);
  }

  cout << ans.size();
  for (int res : ans) {
    cout << " " << res;
  }
  cout << endl;

  return 0;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    child[i] = i;
  }

  for (int i = 0; i < q; i++) {
    int idx;
    cin >> idx;

    if (idx == 1) {
      int x, y;
      cin >> x >> y;
      child[x] = y;
      parent[y] = x;
    } else if (idx == 2) {
      int x, y;
      cin >> x >> y;
      child[x] = x;
      parent[y] = y;
    } else {
      int x;
      cin >> x;
      display(x);
    }
  }

  return 0;
}