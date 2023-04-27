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

double calc_dist(double x1, double y1, double x2, double y2) {
  double dist2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(dist2);
}

int n, m;
double px[65], py[65], cx[10], cy[10], r[10];
vector<pair<double, int>> graph[65];

bool used[10], visited[65];
double solve(int state) {
  fill(visited, visited + n + m + 1, false);
  for (int j = 1; j <= m; j++) {
    if (state % 2 != 0) {
      used[j] = true;
    } else {
      used[j] = false;
    }
    state /= 2;
  }

  int cnt = 0;
  double ans = 0;
  priority_queue<pair<double, int>, vector<pair<double, int>>,
                 greater<pair<double, int>>>
      que;
  que.push({0, 1});

  while (cnt < n) {
    pair<double, int> q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    ans += q.first;
    if (q.second <= n) {
      cnt++;
    }

    for (pair<double, int> next : graph[q.second]) {
      if (!visited[next.second]) {
        if (next.second <= n) {
          que.push(next);
        } else {
          if (used[next.second - n]) {
            que.push(next);
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> px[i] >> py[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> cx[i] >> cy[i] >> r[i];
    px[n + i] = cx[i];
    py[n + i] = cy[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double dist = calc_dist(px[i], py[i], px[j], py[j]);
      graph[i].push_back({dist, j});
      graph[j].push_back({dist, i});
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = n + 1; j <= n + m; j++) {
      double dist = calc_dist(px[i], py[i], cx[j - n], cy[j - n]);
      if (dist <= r[j - n]) {
        graph[i].push_back({r[j - n] - dist, j});
        graph[j].push_back({r[j - n] - dist, i});
      } else {
        graph[i].push_back({dist - r[j - n], j});
        graph[j].push_back({dist - r[j - n], i});
      }
    }
  }

  for (int i = n + 1; i <= n + m; i++) {
    for (int j = i + 1; j <= n + m; j++) {
      double dist = calc_dist(cx[i - n], cy[i - n], cx[j - n], cy[j - n]);

      if (dist >= r[i - n] + r[j - n]) {
        graph[i].push_back({dist - (r[i - n] + r[j - n]), j});
        graph[j].push_back({dist - (r[i - n] + r[j - n]), i});
      } else if (max(r[i - n], r[j - n]) >= dist + min(r[i - n], r[j - n])) {
        double r_max = max(r[i - n], r[j - n]), r_min = min(r[i - n], r[j - n]);
        graph[i].push_back({r_max - (dist + r_min), j});
        graph[j].push_back({r_max - (dist + r_min), i});
      } else {
        graph[i].push_back({0, j});
        graph[j].push_back({0, i});
      }
    }
  }

  double ans = 1e18;
  for (int i = 0; i < (1 << m); i++) {
    ans = min(ans, solve(i));
  }
  cout << setprecision(32) << ans << endl;

  return 0;
}