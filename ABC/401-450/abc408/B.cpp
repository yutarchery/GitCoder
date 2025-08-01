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

int n, a[105];
bool visited[105];
vector<int> ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!visited[a[i]]) {
      visited[a[i]] = true;
      ans.push_back(a[i]);
    }
  }
  sort(ans.begin(), ans.end());

  int m = ans.size();
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << ans[i] << (i == m - 1 ? '\n' : ' ');
  }

  return 0;
}
