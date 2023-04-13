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

int main() {
  cin >> s;
  int n = s.length();

  if (n == 8 && 'A' <= s[0] && s[0] <= 'Z') {
    if ('A' <= s[7] && s[7] <= 'Z') {
      if ('1' <= s[1] && s[1] <= '9') {
        bool flag = true;
        for (int i = 2; i < 7; i++) {
          if (!('0' <= s[i] && s[i] <= '9')) {
            flag = false;
          }
        }

        if (flag) {
          Yes();
          return 0;
        }
      }
    }
  }

  No();
  return 0;
}