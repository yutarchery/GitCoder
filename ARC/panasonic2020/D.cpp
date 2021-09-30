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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
int ans[10];

void display() {
  for (int i = 0; i < n; i++) {
    char now = 'a' + ans[i];
    cout << now;
  }
  cout << endl;
}

int solve(int turn, int m) {
  if (turn == n) {
    display();
    return 0;
  }
  for (int i = 0; i <= m; i++) {
    ans[turn] = i;
    solve(turn + 1, max(m, i + 1));
  }
  return 0;
}

int main() {
  cin >> n;
  solve(0, 0);
  return 0;
}