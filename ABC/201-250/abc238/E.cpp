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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, q, l[int(2e5 + 5)], r[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
    graph[l[i] - 1].emplace_back(r[i]);
    graph[r[i]].emplace_back(l[i] - 1);
  }

  queue<int> que;
  visited[0] = true;
  que.push(0);

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int nxt : graph[q]) {
      if (visited[nxt]) {
        continue;
      }

      visited[nxt] = true;
      que.push(nxt);
    }
  }

  visited[n] ? Yes() : No();

  return 0;
}
