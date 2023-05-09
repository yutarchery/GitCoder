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

string s;
vector<vector<int>> v = {{6}, {3}, {1, 7}, {0, 4}, {2, 8}, {5}, {9}};
int cnt[7];

int main() {
  cin >> s;
  if (s[0] == '1') {
    No();
    return 0;
  }

  for (int i = 0; i < 7; i++) {
    for (int j : v[i]) {
      if (s[j] == '1') {
        cnt[i]++;
      }
    }
  }

  for (int i = 0; i < 7; i++) {
    for (int j = i + 2; j < 7; j++) {
      if (cnt[i] == 0 || cnt[j] == 0) {
        continue;
      }

      for (int k = i + 1; k < j; k++) {
        if (cnt[k] == 0) {
          Yes();
          return 0;
        }
      }
    }
  }
  No();

  return 0;
}