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

int n, m, a[1005];
bool visited[1005];

vector<int> ans;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    visited[a[i]] = true;
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1) {
      cout << ' ';
    }
  }
  cout << endl;

  return 0;
}
