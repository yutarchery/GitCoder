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

int n, m, input_cnt[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

bool flag = true;
vector<Pii> ans;
int ans_idx = 1;

void solve(int start) {
  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    ans.push_back({q, ans_idx});
    ans_idx++;

    for (int next : graph[q]) {
      input_cnt[next]--;

      if (input_cnt[next] == 0) {
        que.push(next);
      }
    }

    if (que.size() >= 2) {
      flag = false;
    }
  }

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    input_cnt[v]++;
    graph[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    if (input_cnt[i] == 0) {
      solve(i);
      break;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (input_cnt[i] != 0) {
      flag = false;
    }
  }

  if (ans.size() != n) {
    flag = false;
  }

  if (flag) {
    Yes();
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
      cout << ans[i].second;

      if (i == n - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  } else {
    No();
  }

  return 0;
}