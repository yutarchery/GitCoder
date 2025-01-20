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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
int cnt[int(2e5 + 5)];

priority_queue<int, vector<int>, greater<int>> que;
vector<int> ans;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    graph[a[i]].push_back(b[i]);
    cnt[b[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int q = que.top();
    que.pop();
    ans.push_back(q);
    for (int next : graph[q]) {
      cnt[next]--;
      if (cnt[next] == 0) {
        que.push(next);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i == n - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
