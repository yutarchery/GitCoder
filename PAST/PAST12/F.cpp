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

int n, a[105], q;
vector<int> x[int(2e5 + 5)];

bool visited[105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    for (int j = 0; j < c; j++) {
      int b;
      cin >> b;
      x[b].push_back(i);
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    fill(visited, visited + n + 1, false);

    int d;
    cin >> d;
    for (int j = 0; j < d; j++) {
      int y;
      cin >> y;
      for (int k : x[y]) {
        visited[k] = true;
      }
    }

    vector<Pii> rest;
    for (int j = 1; j <= n; j++) {
      if (!visited[j]) {
        rest.push_back({a[j], j});
      }
    }
    sort(rest.begin(), rest.end(), greater<Pii>());

    if (rest.size() == 0) {
      cout << -1 << endl;
    } else {
      cout << rest[0].second << endl;
    }
  }

  return 0;
}