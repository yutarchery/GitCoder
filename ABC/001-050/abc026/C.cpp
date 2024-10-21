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

int n, b[25], ans[25];
bool visited[25];
vector<int> graph[25];

int solve(int now) {
  if (visited[now]) {
    return ans[now];
  }

  visited[now] = true;
  if (graph[now].size() == 0) {
    return ans[now] = 1;
  }

  int mi = int(1e9), ma = 0;
  for (int nxt : graph[now]) {
    mi = min(mi, solve(nxt));
    ma = max(ma, solve(nxt));
  }

  return ans[now] = mi + ma + 1;
}

int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> b[i];
    graph[b[i]].push_back(i);
  }
  cout << solve(1) << endl;

  return 0;
}
