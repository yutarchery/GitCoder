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

int n, c[105], a, x;
bool bet[105][40];

vector<int> ans;
vector<Pii> p;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 1; j <= c[i]; j++) {
      cin >> a;
      bet[i][a] = true;
    }
  }
  cin >> x;

  for (int i = 1; i <= n; i++) {
    if (bet[i][x]) {
      p.push_back({c[i], i});
    }
  }
  sort(p.begin(), p.end());

  for (int i = 0; i < p.size(); i++) {
    if (p[i].first == p[0].first) {
      ans.push_back(p[i].second);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
