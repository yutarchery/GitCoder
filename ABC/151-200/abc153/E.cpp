#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int h, n, a[int(1e3 + 5)], b[int(1e3 + 5)];
int dp[int(1e3 + 5)][int(1e4 + 5)];

int main(){
  cin >> h >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i] >> b[i];
  }
  fill((int*)dp, (int*)(dp + n + 1), 1e9);
  dp[0][0] = 0;


  for (int i = 1; i <= n; i++){

    for (int j = 0; j <= h; j++){
      dp[i][j] = dp[i - 1][j];
    }

    for (int j = 0; j <= h; j++){
      int now = min(j + a[i], h);

      dp[i][now] = min(dp[i][now], dp[i - 1][j] + b[i]);
      dp[i][now] = min(dp[i][now], dp[i][j] + b[i]);
    }
  }

  cout << dp[n][h] << endl;

  return 0;
}