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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];
vector<int> graph[int(4e5 + 5)];
bool visited[int(4e5 + 5)];

map<int, int> index_map;
int idx[int(4e5 + 5)];

int main() {
  cin >> n;
  index_map[1] = 1;
  idx[1] = 1;

  int next_idx = 2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];

    if (index_map[a[i]] == 0) {
      index_map[a[i]] = next_idx;
      idx[next_idx] = a[i];
      next_idx++;
    }
    if (index_map[b[i]] == 0) {
      index_map[b[i]] = next_idx;
      idx[next_idx] = b[i];
      next_idx++;
    }

    graph[index_map[a[i]]].push_back(index_map[b[i]]);
    graph[index_map[b[i]]].push_back(index_map[a[i]]);
  }

  queue<int> que;
  que.push(1);
  visited[1] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        que.push(next);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= 2 * n + 1; i++) {
    if (visited[i]) {
      ans = max(ans, idx[i]);
    }
  }
  cout << ans << endl;

  return 0;
}