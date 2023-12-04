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

int n, m;
string s, t;

bool visited[int(2e5 + 5)], started[int(2e5 + 5)];
queue<int> que;

bool check(int start) {
  if (start < 0 || start + m - 1 >= n) {
    return false;
  }

  for (int i = 0; i < m; i++) {
    if (visited[start + i]) {
      continue;
    }

    if (s[start + i] != t[i]) {
      return false;
    }
  }

  for (int i = 0; i < m; i++) {
    visited[start + i] = true;
  }

  return true;
}

int main() {
  cin >> n >> m;
  cin >> s;
  cin >> t;

  for (int i = 0; i + m - 1 < n; i++) {
    if (check(i)) {
      que.push(i);
      started[i] = true;
    }
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int i = 1; i < m; i++) {
      if (q + i < n && check(q + i) && !started[q + i]) {
        que.push(q + i);
        started[q + i] = true;
      }

      if (q - i >= 0 && check(q - i) && !started[q - i]) {
        que.push(q - i);
        started[q - i] = true;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}