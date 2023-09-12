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

ll n, a[int(1e5 + 5)], b[int(1e5 + 5)], c[int(1e5 + 5)];
int m;

map<ll, int> idx;
vector<Pli> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
ll dist[int(2e5 + 5)];

void prepare() {
  vector<ll> steps;
  map<ll, bool> used;
  steps.push_back(1);
  used[1] = true;
  steps.push_back(n);
  used[n] = true;

  for (int i = 1; i <= m; i++) {
    if (!used[a[i]]) {
      steps.push_back(a[i]);
      used[a[i]] = true;
    }
    if (!used[b[i]]) {
      steps.push_back(b[i]);
      used[b[i]] = true;
    }
  }
  sort(steps.begin(), steps.end());

  for (int i = 0; i < steps.size(); i++) {
    idx[steps[i]] = i;
    if (i > 0) {
      graph[i].push_back({steps[i] - steps[i - 1], i - 1});
      graph[i - 1].push_back({steps[i] - steps[i - 1], i});
    }
  }
  for (int i = 1; i <= m; i++) {
    graph[idx[a[i]]].push_back({c[i], idx[b[i]]});
    graph[idx[b[i]]].push_back({c[i], idx[a[i]]});
  }
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  prepare();

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, idx[1]});

  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    dist[q.second] = q.first;

    for (Pli next : graph[q.second]) {
      if (!visited[next.second]) {
        que.push({q.first + next.first, next.second});
      }
    }
  }
  cout << dist[idx[n]] << endl;

  return 0;
}