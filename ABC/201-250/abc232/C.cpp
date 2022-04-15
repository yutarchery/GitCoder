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

int n, m, node[10];
vector<int> graph1[10], graph2[10];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph1[a].push_back(b);
    graph1[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    sort(graph1[i].begin(), graph1[i].end());
    node[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int c, d;
    cin >> c >> d;
    graph2[c].push_back(d);
    graph2[d].push_back(c);
  }

  do {
    vector<int> graph3[10];
    for (int i = 1; i <= n; i++) {
      int now = node[i];
      for (int j : graph2[i]) {
        int next = node[j];
        if (now < next) {
          graph3[now].push_back(next);
          graph3[next].push_back(now);
        }
      }
    }

    bool ans = true;
    for (int i = 1; i <= n; i++) {
      sort(graph3[i].begin(), graph3[i].end());
      if (graph1[i] != graph3[i]) {
        ans = false;
        break;
      }
    }

    if (ans) {
      Yes();
      return 0;
    }

  } while (next_permutation(node + 1, node + n + 1));

  No();

  return 0;
}