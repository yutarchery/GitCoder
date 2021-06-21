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

int N, M;
vector <Pii> graph[int(1e5 + 5)];

bool visited[int(1e5 + 5)];
int dist[2][int(1e5 + 5)];

int calcDist(int start, int num){
  fill(visited, visited + N + 1, false);
  priority_queue <Pii, vector<Pii>, greater<Pii> > que;
  que.push({0, start});  

  while (!que.empty()){
    Pii Q = que.top(); que.pop();
    if (visited[Q.se]) continue;
    visited[Q.se] = true;
    dist[num][Q.se] = Q.fi;

    for (Pii P : graph[Q.se]){
      if (visited[P.se]) continue;
      que.push({Q.fi + P.fi, P.se});
    }
  }
  
  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int A, B, C; cin >> A >> B >> C;
    graph[A].push_back({C, B});
    graph[B].push_back({C, A});
  }
  calcDist(1, 0);
  calcDist(N, 1);

  for (int i = 1; i <= N; i++){
    cout << dist[0][i] + dist[1][i] << endl;
  }

  return 0;
}