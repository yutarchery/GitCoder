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

int n, m, input[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

priority_queue<int, vector<int>, greater<int>> que;
vector<int> ans;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    input[b]++;
  }

  for (int i = 1; i <= n; i++) {
    if (input[i] == 0) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int q = que.top();
    que.pop();
    ans.push_back(q);

    for (int next : graph[q]) {
      input[next]--;
      if (input[next] == 0) {
        que.push(next);
      }
    }
  }

  if (ans.size() == n) {
    cout << ans[0];
    for (int i = 1; i < n; i++) {
      cout << " " << ans[i];
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}