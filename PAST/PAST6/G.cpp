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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m, q, x[int(2e5 + 5)];
vector<Pii> graph[int(2e5 + 5)];

int ans = 1;
bool visited[int(2e5 + 5)];
priority_queue<Pii, vector<Pii>, greater<Pii>> que;

int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  for (int i = 1; i <= q; i++) {
    cin >> x[i];
  }
  visited[1] = true;
  for (Pii next : graph[1]) {
    que.push(next);
  }

  for (int i = 1; i <= q; i++) {
    vector<int> next;

    while (!que.empty()) {
      Pii q = que.top();
      if (q.first > x[i]) {
        break;
      }
      que.pop();
      if (visited[q.second]) {
        continue;
      }
      visited[q.second] = true;
      next.push_back(q.second);
      ans++;
    }

    cout << ans << endl;

    for (int j : next) {
      for (Pii k : graph[j]) {
        que.push(k);
      }
    }
  }

  return 0;
}