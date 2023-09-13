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

int n, q, t, u, v;
int group[int(2e5 + 5)];
vector<int> ans[int(2e5 + 5)];

void unite(int a, int b) {
  int ga = group[a], gb = group[b];

  if (ga == gb) {
    return;
  }
  if (ans[ga].size() < ans[gb].size()) {
    swap(ga, gb);
  }

  for (int elem : ans[gb]) {
    ans[ga].push_back(elem);
    group[elem] = ga;
  }
  ans[gb] = {};

  return;
}

void solve(int a) {
  int ga = group[a];
  sort(ans[ga].begin(), ans[ga].end());

  cout << ans[ga][0];
  for (int i = 1; i < ans[ga].size(); i++) {
    cout << " " << ans[ga][i];
  }
  cout << endl;

  return;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
    ans[i].push_back(i);
  }

  for (int i = 0; i < q; i++) {
    cin >> t;

    if (t == 1) {
      cin >> u >> v;
      unite(u, v);
    } else {
      cin >> u;
      solve(u);
    }
  }

  return 0;
}