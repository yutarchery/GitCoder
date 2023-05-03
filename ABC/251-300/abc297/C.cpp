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
string s[105];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];

    for (int j = 1; j < w; j++) {
      if (s[i][j] == 'T' && s[i][j - 1] == 'T') {
        s[i][j - 1] = 'P';
        s[i][j] = 'C';
      }
    }
  }

  for (int i = 0; i < h; i++) {
    cout << s[i] << endl;
  }

  return 0;
}