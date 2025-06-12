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

int n, k;
ll a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)];

map<array<ll, 3>, bool> visited;
const array<ll, 3> dir[3] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  sort(c + 1, c + n + 1);

  priority_queue<pair<ll, array<ll, 3>>> que;
  que.push({a[n] * b[n] + b[n] * c[n] + c[n] * a[n], {n, n, n}});
  visited[{n, n, n}] = true;

  int cnt = 0;
  while (!que.empty()) {
    pair<ll, array<ll, 3>> p = que.top();
    que.pop();
    cnt++;

    if (cnt == k) {
      cout << p.first << endl;
      return 0;
    }

    array<ll, 3> q = p.second;
    for (array<ll, 3> d : dir) {
      array<ll, 3> q = p.second;
      bool flag = true;
      for (int l = 0; l < 3; l++) {
        q[l] += d[l];
        if (q[l] <= 0) {
          flag = false;
        }
      }

      if (!visited[q] && flag) {
        que.push(
            {a[q[0]] * b[q[1]] + b[q[1]] * c[q[2]] + c[q[2]] * a[q[0]], q});
        visited[q] = true;
      }
    }
  }

  return 0;
}
