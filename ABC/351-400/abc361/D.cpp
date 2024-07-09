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

int n;
string s, t;

queue<string> que;
map<string, bool> visited;
map<string, int> dist;

void solve() {
  que.push(s);
  visited[s] = true;

  while (!que.empty()) {
    string now = que.front();
    que.pop();

    int start_idx;
    for (int i = 0; i < n + 2; i++) {
      if (now[i] == '.') {
        start_idx = i;
        break;
      }
    }

    for (int i = 0; i + 1 < n + 2; i++) {
      if (now[i] == '.' || now[i + 1] == '.') {
        continue;
      }

      string next = now;
      swap(next[i], next[start_idx]);
      swap(next[i + 1], next[start_idx + 1]);

      if (!visited[next]) {
        visited[next] = true;
        dist[next] = dist[now] + 1;
        que.push(next);
      }
    }
  }

  return;
}

int main() {
  cin >> n;
  cin >> s;
  cin >> t;

  s += "..";
  t += "..";
  solve();

  if (visited[t]) {
    cout << dist[t] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
