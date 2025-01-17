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

int n, p[int(1.5e5 + 5)], root;
int q, a[int(1e5 + 5)], b[int(1e5 + 5)];

vector<int> graph[int(1.5e5 + 5)];
int dist[int(1.5e5 + 5)], parents[int(1.5e5 + 5)][30];

void prepare() {
  queue<int> que;
  que.push(root);
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      dist[next] = dist[q] + 1;
      que.push(next);
    }
  }

  for (int j = 1; j < 30; j++) {
    for (int i = 1; i <= n; i++) {
      if (parents[i][j - 1] == -1) {
        parents[i][j] = -1;
      } else {
        parents[i][j] = parents[parents[i][j - 1]][j - 1];
      }
    }
  }

  return;
}

bool solve(int a, int b) {
  if (dist[a] < dist[b]) {
    return false;
  }

  while (dist[a] > dist[b]) {
    int diff = dist[a] - dist[b];
    for (int j = 29; j >= 0; j--) {
      if ((1 << j) <= diff) {
        a = parents[a][j];
        break;
      }
    }
  }

  return a == b;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (p[i] == -1) {
      root = i;
    } else {
      graph[p[i]].push_back(i);
    }
    parents[i][0] = p[i];
  }
  prepare();

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= q; i++) {
    if (solve(a[i], b[i])) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}
