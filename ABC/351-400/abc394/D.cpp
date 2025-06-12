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
const char c[3][2] = {{'[', ']'}, {'(', ')'}, {'<', '>'}};
deque<char> deq;

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 2; k++) {
        if (s[i] == c[j][k]) {
          if (k == 0) {
            deq.push_back(c[j][1]);
          } else {
            if (deq.empty()) {
              No();
              return 0;
            }

            char now = deq.back();
            if (now == c[j][k]) {
              deq.pop_back();
            } else {
              No();
              return 0;
            }
          }
        }
      }
    }
  }

  deq.empty() ? Yes() : No();

  return 0;
}
