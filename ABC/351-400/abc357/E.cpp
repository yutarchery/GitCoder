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

int n, a[int(2e5 + 5)], input_cnt[int(2e5 + 5)];

ll ans[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
vector<int> loops[int(2e5 + 5)];
void loop_search(int now, int loop_idx) {
  if (visited[now]) {
    return;
  }
  visited[now] = true;
  loops[loop_idx].push_back(now);
  loop_search(a[now], loop_idx);
  return;
}

ll solve(int now) {
  if (visited[now]) {
    return ans[now];
  }
  visited[now] = true;
  ll res = solve(a[now]) + 1;
  return ans[now] = res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    input_cnt[a[i]]++;
  }
  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (input_cnt[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    input_cnt[a[q]]--;
    if (input_cnt[a[q]] == 0) {
      que.push(a[q]);
    }
  }

  int loop_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (input_cnt[i] == 0) {
      continue;
    }
    if (visited[i]) {
      continue;
    }
    loop_search(i, loop_cnt);
    loop_cnt++;
  }
  for (int i = 0; i < loop_cnt; i++) {
    for (int j : loops[i]) {
      ans[j] += loops[i].size();
    }
  }

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += solve(i);
  }
  cout << sum << endl;

  return 0;
}
