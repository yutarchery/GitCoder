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

int n, q;
int x[int(1e5 + 5)];
int treeLevel[int(1e5 + 5)];

vector<int> graph[int(1e5 + 5)];
int maxNumber[int(1e5 + 5)][25];

Pii treeLevelAndNode[int(1e5 + 5)];

int makeTree(int start) {
  treeLevel[start] = 1;
  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (treeLevel[next] == 0) {
        treeLevel[next] = treeLevel[q] + 1;
        que.push(next);
      }
    }
  }

  return 0;
}

int makeData() {
  for (int i = 1; i <= n; i++) {
    treeLevelAndNode[i] = make_pair(treeLevel[i], i);
  }
  sort(treeLevelAndNode + 1, treeLevelAndNode + n + 1, greater<Pii>());

  for (int i = 1; i <= n; i++) {
    int node = treeLevelAndNode[i].se;

    priority_queue<int> que;
    que.push(x[node]);

    for (int next : graph[node]) {
      for (int j = 0; j < 20; j++) {
        que.push(maxNumber[next][j]);
      }
    }

    for (int j = 0; j < 20; j++) {
      maxNumber[node][j] = que.top();
      que.pop();
    }
  }

  return 0;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  makeTree(1);
  makeData();

  for (int i = 0; i < q; i++) {
    int v, k;
    cin >> v >> k;
    cout << maxNumber[v][k - 1] << endl;
  }

  return 0;
}