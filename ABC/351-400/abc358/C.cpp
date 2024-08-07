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
string s[15];

int ans = 0;
bool visited[15];

void solve(int idx) {
  fill(visited, visited + m, false);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (idx % 2 == 1) {
      cnt++;
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'o') {
          visited[j] = true;
        }
      }
    }
    idx /= 2;
  }

  bool flag = true;
  for (int j = 0; j < m; j++) {
    if (!visited[j]) {
      flag = false;
    }
  }
  if (flag) {
    ans = min(ans, cnt);
  }

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  ans = n;
  for (int i = 0; i < (1 << n); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
