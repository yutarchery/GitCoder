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

string s, t;
string u[18] = {"B9", "B8", "B7", "B6", "B5", "B4", "B3", "B2", "B1",
                "1F", "2F", "3F", "4F", "5F", "6F", "7F", "8F", "9F"};
int a, b;

int main() {
  cin >> s >> t;
  for (int i = 0; i < 18; i++) {
    if (s == u[i]) {
      a = i;
    }
    if (t == u[i]) {
      b = i;
    }
  }
  cout << abs(a - b) << endl;

  return 0;
}
