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

int n, m, stage, card[int(2e5 + 5)];
string s;

int main() {
  cin >> n >> m;
  cin >> s;

  for (int i = 0; i < m; i++) {
    if (s[i] == '0') {
      card[i % n]++;
    } else if (s[i] == '-') {
      stage += card[i % n] + 1;
      card[i % n] = 0;
    } else {
      card[i % n] += stage + 1;
      stage = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << card[i] << endl;
  }

  return 0;
}