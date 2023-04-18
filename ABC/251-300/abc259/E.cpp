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
vector<Pii> pe[int(2e5 + 5)];

map<Pii, int> cnt;
map<int, int> e_max;

vector<int> erased[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int p, e;
      cin >> p >> e;
      pe[i].push_back({p, e});

      cnt[{p, e}]++;
      e_max[p] = max(e_max[p], e);
    }
  }

  for (int i = 1; i <= n; i++) {
    int m = pe[i].size();

    for (int j = 0; j < m; j++) {
      int p = pe[i][j].first, e = pe[i][j].second;

      if (e_max[p] == e && cnt[{p, e}] == 1) {
        erased[i].push_back(p);
      }
    }
    sort(erased[i].begin(), erased[i].end());
  }
  sort(erased + 1, erased + n + 1);

  int ans = 1;
  for (int i = 2; i <= n; i++) {
    if (erased[i] != erased[i - 1]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}