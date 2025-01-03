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

int n, m;
vector<vector<int>> ans;

void solve(vector<int> now, int last, int turn) {
  if (turn == n) {
    if (now[n - 1] <= m) {
      ans.push_back(now);
    }
    return;
  }

  for (int i = last + 10; i + 10 * (n - turn - 1) <= m; i++) {
    vector<int> next;
    next = now;
    next.push_back(i);
    solve(next, i, turn + 1);
  }
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i + 10 * (n - 1) <= m; i++) {
    solve({i}, i, 1);
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i][0];
    for (int j = 1; j < n; j++) {
      cout << " " << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
