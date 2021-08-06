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

int n, m;
vector <int> graph[int(2e5 + 5)];

int dist[int(2e5 + 5)];
ll dp[int(2e5 + 5)];

int main(){
  cin >> n >> m;
  fill(dist, dist + n + 1, -1);

  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  queue <int> que; que.push(1);
  dist[1] = 0;
  dp[1] = 1;
  
  while (!que.empty()){
    int q = que.front(); que.pop();
    for (int v : graph[q]){
      if (dist[v] == -1){
        que.push(v);
        dist[v] = dist[q] + 1;
      }
      if (dist[v] == dist[q] + 1){
        dp[v] += dp[q];
        dp[v] %= MOD;
      }
    }
  }
  cout << dp[n] << endl;

  return 0;
}