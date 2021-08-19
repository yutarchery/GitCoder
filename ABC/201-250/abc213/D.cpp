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

int n;
vector <int> graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
vector <int> ans;

int solve(int node){

  for (int i = 0; i < graph[node].size(); i++){
    int next = graph[node][i];
    if (!visited[next]){
      visited[next] = true;
      ans.push_back(next);
      solve(next);
      ans.push_back(node);
    }
  }

  return 0;
}


int main(){
  cin >> n;
  for (int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; i++){
    sort(graph[i].begin(), graph[i].end());
  }

  visited[1] = true;
  solve(1);

  cout << 1;
  for (int i : ans) cout << " " << i;
  cout << endl;

  return 0;
}