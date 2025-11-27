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

array<array<int, 4>, 2> a;

int ans[int(2e7 + 5)];
bool visited[int(2e7 + 5)];

int get_idx(array<array<int, 4>, 2> v) {
  int idx = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      idx *= 8;
      idx += v[i][j];
    }
  }

  return idx;
}

int main() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  queue<array<array<int, 4>, 2>> que;
  que.push({{{0, 1, 2, 3}, {4, 5, 6, 7}}});
  visited[get_idx({{{0, 1, 2, 3}, {4, 5, 6, 7}}})] = true;

  while (!que.empty()) {
    array<array<int, 4>, 2> q = que.front();
    que.pop();
    int now = get_idx(q);

    for (int j = 0; j < 4; j++) {
      swap(q[0][j], q[1][j]);
      int next = get_idx(q);
      if (!visited[next]) {
        que.push(q);
        visited[next] = true;
        ans[next] = ans[now] + 1;
      }
      swap(q[0][j], q[1][j]);
    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        swap(q[i][j], q[i][j + 1]);
        int next = get_idx(q);
        if (!visited[next]) {
          que.push(q);
          visited[next] = true;
          ans[next] = ans[now] + 1;
        }
        swap(q[i][j], q[i][j + 1]);
      }
    }
  }

  cout << ans[get_idx(a)] << endl;

  return 0;
}
