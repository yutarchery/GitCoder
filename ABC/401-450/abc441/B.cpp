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

int n, m;
char s[26], t[26];
int q;
string w[105];

bool visited_s[26], visited_t[26];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    visited_s[s[i] - 'a'] = true;
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    visited_t[t[i] - 'a'] = true;
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> w[i];
    bool flag_s = true, flag_t = true;
    for (int j = 0; j < w[i].length(); j++) {
      if (!visited_s[w[i][j] - 'a']) {
        flag_s = false;
      }
      if (!visited_t[w[i][j] - 'a']) {
        flag_t = false;
      }
    }

    if (flag_s && flag_t) {
      cout << "Unknown" << endl;
    } else if (flag_s) {
      cout << "Takahashi" << endl;
    } else if (flag_t) {
      cout << "Aoki" << endl;
    }
  }

  return 0;
}
