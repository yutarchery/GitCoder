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

int n, m, a[105], point[105], max_point;
char s[105][105];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
      if (s[i][j] == 'o') {
        point[i] += a[j];
      }
    }
    point[i] += i;
    max_point = max(max_point, point[i]);
  }

  for (int i = 1; i <= n; i++) {
    priority_queue<int> que;
    for (int j = 1; j <= m; j++) {
      if (s[i][j] != 'o') {
        que.push(a[j]);
      }
    }

    int cnt = 0;
    while (point[i] < max_point && !que.empty()) {
      int q = que.top();
      que.pop();
      point[i] += q;
      cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}
