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
char s[2005][2005];

int cnt[2005][2005];
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int ans = 0;
queue<Pii> que;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '.') {
        for (int k = 0; k < 4; k++) {
          if (s[i + di[k]][j + dj[k]] == '#') {
            cnt[i][j]++;
          }
        }

        if (cnt[i][j] > 2) {
          que.push({i, j});
        }
      }
    }
  }

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    int i = q.first, j = q.second;
    if (s[i][j] == '#') {
      continue;
    }
    ans++;
    s[i][j] = '#';
    for (int k = 0; k < 4; k++) {
      if (s[i + di[k]][j + dj[k]] == '.') {
        cnt[i + di[k]][j + dj[k]]++;
        if (cnt[i + di[k]][j + dj[k]] > 2) {
          que.push({i + di[k], j + dj[k]});
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
