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

int h, w;
vector<int> a[int(2e5 + 5)];
vector<Pii> ans;

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    a[i].resize(w);
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i + 1 < h) {
        ans.push_back({a[i][j], a[i + 1][j]});
      }
      if (j + 1 < w) {
        ans.push_back({a[i][j], a[i][j + 1]});
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    if (ans[i].first > ans[i].second) {
      swap(ans[i].first, ans[i].second);
    }
  }
  sort(ans.begin(), ans.end());
  for (Pii p : ans) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
