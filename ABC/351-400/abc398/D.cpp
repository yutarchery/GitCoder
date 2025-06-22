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

int n, r, c;
char s[int(2e5 + 5)];

const char dir[4] = {'N', 'W', 'S', 'E'};
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

Pii p[int(2e5 + 5)];
map<Pii, int> cnt;
bool ans[int(2e5 + 5)];

int main() {
  cin >> n >> r >> c;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = n; i >= 1; i--) {
    for (int k = 0; k < 4; k++) {
      if (s[i] == dir[k]) {
        p[i].first = p[i + 1].first + di[k];
        p[i].second = p[i + 1].second + dj[k];
        cnt[p[i]]++;
      }
    }
  }

  for (int i = n; i >= 1; i--) {
    if (cnt[{r, c}] >= 1) {
      ans[i] = true;
    }
    cnt[p[i]]--;

    for (int k = 0; k < 4; k++) {
      if (s[i] == dir[k]) {
        r += di[k];
        c += dj[k];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
