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

int n, m, c[int(2e5 + 5)];
string s;

vector<int> v[int(2e5 + 5)];
char ans[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    v[c[i]].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    v[i].push_back(v[i][0]);
    for (int j = 1; j < v[i].size(); j++) {
      ans[v[i][j]] = s[v[i][j - 1]];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
