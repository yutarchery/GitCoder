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
string s[60];
char c1[4] = {'H', 'D', 'C', 'S'};
char c2[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
bool ans = true;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    bool now1 = false, now2 = false;
    for (int j = 0; j < 4; j++) {
      if (s[i][0] == c1[j]) {
        now1 = true;
      }
    }
    for (int j = 0; j < 13; j++) {
      if (s[i][1] == c2[j]) {
        now2 = true;
      }
    }
    ans &= (now1 & now2);
  }
  sort(s, s + n);
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      ans = false;
    }
  }

  if (ans) {
    Yes();
  } else {
    No();
  }

  return 0;
}