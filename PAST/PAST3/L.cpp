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

int n, k[int(1e5 + 5)];
vector<int> t[int(1e5 + 5)];
vector<bool> visited[int(1e5 + 5)];

int m, a[int(3e5 + 5)];

int firsts[int(1e5 + 5)], seconds[int(1e5 + 5)];
priority_queue<pair<int, Pii>> first_que, second_que;
int ans[int(3e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    t[i].resize(k[i], 0);
    visited[i].resize(k[i], false);

    for (int j = 0; j < k[i]; j++) {
      cin >> t[i][j];
    }

    first_que.push({t[i][0], {i, 0}});
    second_que.push({t[i][0], {i, 0}});
    firsts[i] = 0;

    if (k[i] >= 2) {
      second_que.push({t[i][1], {i, 1}});
      seconds[i] = 1;
    } else {
      seconds[i] = -1;
    }
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      while (!first_que.empty()) {
        pair<int, Pii> q = first_que.top();
        first_que.pop();

        if (visited[q.second.first][q.second.second]) {
          continue;
        }

        int idx = q.second.first;
        visited[idx][q.second.second] = true;
        ans[i] = q.first;

        if (seconds[idx] != -1) {
          first_que.push({t[idx][seconds[idx]], {idx, seconds[idx]}});
          firsts[idx] = seconds[idx];
        } else {
          firsts[idx] = -1;
        }

        if (seconds[idx] + 1 < k[idx]) {
          second_que.push({t[idx][seconds[idx] + 1], {idx, seconds[idx] + 1}});
          seconds[idx]++;
        } else {
          seconds[idx] = -1;
        }

        break;
      }
    } else {
      while (!second_que.empty()) {
        pair<int, Pii> q = second_que.top();
        second_que.pop();

        if (visited[q.second.first][q.second.second]) {
          continue;
        }

        int idx = q.second.first;
        ans[i] = q.first;
        visited[idx][q.second.second] = true;

        if (firsts[idx] == q.second.second) {
          if (seconds[idx] != -1) {
            first_que.push({t[idx][seconds[idx]], {idx, seconds[idx]}});
            firsts[idx] = seconds[idx];
          } else {
            firsts[idx] = -1;
          }

          if (seconds[idx] + 1 < k[idx]) {
            second_que.push(
                {t[idx][seconds[idx] + 1], {idx, seconds[idx] + 1}});
            seconds[idx]++;
          } else {
            seconds[idx] = -1;
          }
        } else {
          if (seconds[idx] + 1 < k[idx]) {
            second_que.push(
                {t[idx][seconds[idx] + 1], {idx, seconds[idx] + 1}});
            seconds[idx]++;
          } else {
            seconds[idx] = -1;
          }
        }

        break;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
