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

int h, w, p, q;
ll x, s[505][505];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
bool visited[505][505];

typedef pair<ll, Pii> P;
priority_queue<P, vector<P>, greater<P>> que;

int main() {
  cin >> h >> w >> x;
  cin >> p >> q;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  ll ans = s[p][q];
  visited[p][q] = true;
  for (int k = 0; k < 4; k++) {
    int i = p + di[k], j = q + dj[k];
    if (1 <= i && i <= h && 1 <= j && j <= w) {
      visited[i][j] = true;
      que.push({s[i][j], {i, j}});
    }
  }

  while (!que.empty()) {
    P q = que.top();
    if (q.first >= (ans + x - 1) / x) {
      break;
    }
    ans += q.first;
    que.pop();
    for (int k = 0; k < 4; k++) {
      int i = q.second.first + di[k], j = q.second.second + dj[k];
      if (1 <= i && i <= h && 1 <= j && j <= w && !visited[i][j]) {
        visited[i][j] = true;
        que.push({s[i][j], {i, j}});
      }
    }
  }

  cout << ans << endl;

  return 0;
}
