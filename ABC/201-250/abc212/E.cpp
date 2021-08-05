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

int n, m, k;
vector <int> graph[5005];
ll dp[5005][5005], sum[5005];

int main(){
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dp[0][1] = 1;
  sum[0] = 1;

  for (int i = 1; i <= k; i++){

    for (int j = 1; j <= n; j++){
      dp[i][j] -= dp[i - 1][j];
      for (int edge : graph[j]){
        dp[i][edge] -= dp[i - 1][j];
        dp[i][edge] %= MOD2;
      }
      sum[i] += dp[i - 1][j] * (n - 1 - graph[j].size());
      sum[i] %= MOD2;
    }

    for (int j = 1; j <= n; j++){
      dp[i][j] += sum[i - 1];
      dp[i][j] %= MOD2;
      if (dp[i][j] < 0) dp[i][j] += MOD2;
    }
  }

  cout << dp[k][1] << endl;

  return 0;
}