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
char c[2005][2005];

bool h_visited[2005], w_visited[2005];
int h_cnt[2005][26], w_cnt[2005][26];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> c[i][j];
      h_cnt[i][c[i][j] - 'a']++;
      w_cnt[j][c[i][j] - 'a']++;
    }
  }

  int h_rest = h, w_rest = w;
  for (int l = 0; l <= h + w; l++) {
    vector<Pii> ph, pw;
    for (int i = 1; i <= h; i++) {
      if (h_visited[i]) {
        continue;
      }

      for (int k = 0; k < 26; k++) {
        if (h_cnt[i][k] == w_rest && w_rest >= 2) {
          ph.push_back({i, k});
        }
      }
    }

    for (int j = 1; j <= w; j++) {
      if (w_visited[j]) {
        continue;
      }

      for (int k = 0; k < 26; k++) {
        if (w_cnt[j][k] == h_rest && h_rest >= 2) {
          pw.push_back({j, k});
        }
      }
    }

    for (Pii p : ph) {
      for (int j = 1; j <= w; j++) {
        w_cnt[j][p.second]--;
      }
      h_visited[p.first] = true;
      h_rest--;
    }
    for (Pii p : pw) {
      for (int i = 1; i <= h; i++) {
        h_cnt[i][p.second]--;
      }
      w_visited[p.first] = true;
      w_rest--;
    }
  }

  cout << h_rest * w_rest << endl;

  return 0;
}
