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

int n, k[105], a, cnt[105][int(1e5 + 5)];
vector<int> cards[105];

double ans = 0;

void solve(int i, int j) {
  double now = 0;
  for (int c : cards[i]) {
    now +=
        (double(cnt[i][c]) / double(k[i])) * (double(cnt[j][c]) / double(k[j]));
  }
  ans = max(ans, now);
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    for (int j = 1; j <= k[i]; j++) {
      cin >> a;
      if (cnt[i][a] == 0) {
        cards[i].push_back(a);
      }
      cnt[i][a]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      solve(i, j);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
