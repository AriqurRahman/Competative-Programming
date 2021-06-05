/*********************************************************************
 *-------------------------------------------------------------------*
 *                                                                   *
 *   Life is just a life. Lead it, Feel it & Enjoy It Properly.      *
 *   Nothing is impossible. Just believe in yourself & Almighty.     *
 *                                                                   *
 *-------------------------------------------------------------------*
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

///######################### Typedef Section #########################

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

///###################################################################

///######################### Define Section ##########################
#define FST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define READ          freopen("in.txt","r",stdin)
#define WRITE         freopen("out.txt","w",stdout);
#define nl            "\n"
#define pi            acos(-1.0)
#define mem(arr,val)  memset(arr,val,sizeof(arr))
#define pr            pair<ll,ll>
#define pb            push_back
#define mp            make_pair
#define pr            pair<ll,ll>
#define ff            first
#define ss            second
#define mod           1000000007
#define INF           0x3f3f3f3f
///###################################################################

///######################### Input Section ###########################

#define si1(x)        scanf("%d",&x)
#define si2(x,y)      scanf("%d %d", &x, &y)
#define si3(x,y,z)    scanf("%d %d %d", &x, &y, &z)

#define sd1(x)        scanf("%lf",&x)
#define sd2(x,y)      scanf("%lf %lf", &x, &y)
#define sd3(x,y,z)    scanf("%lf %lf %lf", &x, &y, &z)

#define sli1(x)       scanf("%lld",&x)
#define sli2(x,y)     scanf("%lld %lld", &x, &y)
#define sli3(x,y,z)   scanf("%lld %lld %lld", &x, &y, &z)

///###################################################################
///--------------------------- 2D ------------------------------------

///############################ BFS ##################################
#define GRng 1000
bool traverse[GRng];
ll dist[GRng],way[GRng];
vector<ll>G[GRng];
void BFS(ll sr)  /// Complete
{
    queue<ll>Q;
    Q.push(sr);
    traverse[sr]=true;
    dist[sr]=0;
    way[sr]=0;

    while(!Q.empty())
    {
        ll u = Q.front();
        Q.pop();

        for(ll i=0; i<G[u].size(); i++)
        {
            ll v = G[u][i];
            if(!traverse[v])
            {
                Q.push(v);
                traverse[v]=true;
                dist[v]=dist[u]+1;
                way[v]=u;
            }
        }
    }
}

///--------------------------- 0-1 BFS -------------------------------
vector<ll>d(n,INF);
void Zero_One_BFS(ll s)
{
    d[s] = 0;
    deque<ll> q;
    q.push_front(s);
    while (!q.empty()) {
        ll v = q.front();
        q.pop_front();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}

///--------------------------- 2D ------------------------------------
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int m=1000, n=1000;
struct Mat
{
    char ch;
    bool B;
}matrix[m][n];

ll BFS(ll x, ll y, ll m , ll n)   /// Complete
{
        int cnt=0;
        queue<pr>Q;
        Q.push({x,y});
        matrix[x][y].B = true;
        cnt++;

        while(!row.empty())
        {
            pr v = Q.front();
            Q.pop();

            for(ll i=0; i<4; i++)
            {
                ll r=v.first+dx[i];
                ll c=v.second+dy[i];

                if(r<0 || c<0 || r>=m || c>=n || matrix[r][c].B==true || matrix[r][c].ch=='#') continue;
                Q.push({r,c});
                matrix[r][c].B=true;
                cnt++;
            }
        }
        return cnt;
}
///--------------------------- 3D ------------------------------------
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct point
{
    ll x, y, z;
};

struct check
{
    bool chk = false;
    char ch;
    int mn = 0;
}matrix[32][32][32];

void BFS(point sr, ll p , ll q, ll r)   /// Complete
{
        int cnt=0;
        queue<point>Q;
        Q.push(sr);
        matrix[sr.x][sr.y][sr.z].chk = true;
        matrix[sr.x][sr.y][sr.z].mn = 0;

        while(!Q.empty())
        {
            point v = Q.front();
            Q.pop();

            for(ll i=0; i<6; i++)
            {
                ll xx=v.x+dx[i];
                ll yy=v.y+dy[i];
                ll zz=v.z+dz[i];

                if(xx<0 || yy<0  || zz<0 || xx>=p || yy>=q || zz>=r || matrix[xx][yy][zz].chk==true || matrix[xx][yy][zz].ch=='#') continue;
                point nw;
                nw.x = xx; nw.y = yy; nw.z = zz;
                Q.push(nw);
                matrix[xx][yy][zz].chk=true;
                matrix[xx][yy][zz].mn = matrix[v.x][v.y][v.z].mn + 1;   //dis[u]=dis[v]+1;
            }
        }
}
///--------------------------- Path ----------------------------------

void Graph_path(ll des)  /// Complete
{
    if(dist[des]==INF) cout << -1 << nl;
    else{
        vector<ll> path;
        for (ll u=des; u!=0; u=way[u]) path.pb(u);
        reverse(path.begin(), path.end());
        for (ll i=0; i<path.size(); i++) cout << path[i] << " ";
        cout << nl;
    }
}

///###################################################################

///############################ DFS ##################################
vector<ll>G[GRng];
ll way[GRng], dis[GRng], prv[GRng], pst[GRng], cnt=0;

void DFS(ll v)
{
    prv[v]=++cnt;
    for(ll i=0; i<G[v].size(); i++)
    {
        ll u=G[v][i];
        if(u!=way[v])
        {
            way[u]=v;
            dis[u]=dis[v]+1;
            DFS(u);
        }
    }
    pst[v]=++cnt;
}
///###################################################################
///##################### Connected Component #########################
vector<ll>comp;
void Connected_Component(ll node) {
    for(ll i = 0; i < node ; ++i)
        used [i] = false;
    for(ll i = 0; i < node ; ++i)
        if(!used[i]) {
            comp.clear();
            dfs(i);
            cout << "Component:" ;
            for (ll j = 0; j < comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << nl ;
        }
}
///###################################################################

///###################### Finding Bridge #############################
vector<bool> visited;
vector<ll> tin, low;
vector<pair<ll,ll> >bridge;
ll timer;

void DFS(ll v, ll p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (ll i=0; i<G[v].size(); i++) {
        ll u = G[v][i];
        if (u == p) continue;
        if (visited[u]) {
            low[v] = min(low[v], tin[u]);
        } else {
            DFS(u, v);
            low[v] = min(low[v], low[v]);
            if (low[u] > tin[v]){
                //IS_BRIDGE(v, to);
                bridge.pb({v,u});
            }
        }
    }
}

void find_bridges(ll n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            DFS(i);
    }
}
///###################################################################

///###################### Articulation Point #########################
vector<bool> visited;
vector<ll> tin, low, point;
int timer;

void DFS( v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    ll children=0;
    for (ll i=0; i<G[v].size(); i++) {
        ll u = G[v][i];
        if (u == p) continue;
        if (visited[u]) {
            low[v] = min(low[v], tin[u]);
        } else {
            DFS(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= tin[v] && p!=-1)
                point.bp(v); //IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        point.bp(v);//IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            DFS(i);
    }
}
///###################################################################
///###################### Dijkstra's Algorithm #######################
#define SZ 100005
vector<pr>G[SZ];
ll dist[SZ], way[SZ];
void Dijkstra(ll sr, ll node)  /// Complete
{
    priority_queue<ll>pq;
    pq.push(sr);

    for(ll i=1; i<=node; i++) dist[i]=INF;
    dist[sr]=0;
    way[sr]=0;

    while(!pq.empty()){
        ll u = pq.top();
        pq.pop();

        for(ll i=0; i<G[u].size(); i++){
            ll v = G[u][i].ff;
            ll cost = G[u][i].ss;
            if(dist[v]>dist[u]+cost){
                dist[v]=dist[u]+cost;
                way[v]=u;
                pq.push(v);
            }
        }
    }
}

///###################################################################
///######################### Bellman-Ford ############################
struct Edge
{
    ll from, to, val;
};
void BellmanFord()  /// Complete
{
    vector<ll>dist(node+1,INF);
    dist[1]=0;
    vector<ll>way(node+1,0);

    for(ll j=1; j<node-1; j++){
        bool any = false;
        for(ll i=0; i<edge; i++){
            if(dist[E[i].to]>dist[E[i].from]+E[i].val){
                dist[E[i].to]=dist[E[i].from]+E[i].val;
                way[E[i].to]=E[i].from;
                any = true;
            }
        }
        if(!any) break;
    }
}
///###################################################################
///######################### Floyd-Warshall ##########################
ll dist[node][node];
void FloydWarshall()  /// Complete
{
    for(ll k = 0; k < n; ++k){
      for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            if (dist[i][k] + dist[k][j] < dist[i][j])
                   dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
}

///###################################################################
///################### Shortest Path Faster Algorithm ################
bool spfa(ll s) {

    dist.assign(node, INF);
    vector<ll> cnt(node, 0);
    vector<bool> inqueue(node, false);
    queue<ll> q;

    dist[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        inqueue[v] = false;

        for(ll i=0; i<G[v].size(); i++) {
            ll to = edge.first;
            ll len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
///###################################################################
///######################## Tarjan's Algorithm #######################
stack<ll>stk;
ll id = 0, sccCount = 0, ids[100], lows[100];
bool onStack[100];
ll DFS(ll v)
{
    stk.push(v);
    onStack[v]=true;
    ids[v]=lows[v]=id++;

    for(ll i=0; i<G[v].size(); i++){
        ll u = G[v][i];
        if(ids[u]==-1) DFS(u);
        if(onStack[u]) lows[v] = min(lows[u],lows[v]);
    }

    if(ids[v]==lows[v]){
        while(!stk.empty()){
            ll t = stk.top();
            onStack[t] = false;
            lows[t] = ids[v];
            if(t==v) break;
        }
        sccCount++;
    }
}

void FindSCC(ll n)
{
    /// Tarjan Algorithms
    for(ll i=0; i<n; i++) ids[i] = -1;
    for(ll i=0; i<n; i++){
        if(ids[i]==-1) DFS(i);
    }
}

///###################################################################
///######################## Eulerian Path ############################
ll in[], out[];
bool Check_Path()
{
    ll str_node = 0, end_node = 0;
    for(ll i=0; i<node; i++){
        if(out[i]-in[i]>1 || in[i]-out[i]>1) return false;
        else if(out[i]-in[i]==1) str_node++;
        else if(in[i]-out[i]==1) end_node++;
    }
    return ((str_node==0 && end_node==0) || (str_node==1 && end_node==1));
}

ll FindStartNode()
{
    ll str = 0;
    for(ll i=0; i<node; i++){
        if(out[i]-in[i]==1) return i;
        if(out[i]>0) str = i;
    }
    return str;
}

ll DFS(ll v)
{
    while(out[v]!=0){
        out[v]--;
        next_edge = G[v].front();
        DFS(next_edge);
    }
    path.insert(v);
}

void FindEulerianPath()
{
    for(ll i=0; i<G.size(); i++){
        for(ll j=0; j<G[i].size(); j++){
            out[i]++;
            in[G[i][j]]++;
        }
    }

    if(!Check_Path()) return;

    DFS(FindStartNode());

    //if(path.size()==m+1) return path;
    //return null;
}
///###################################################################

int main()
{

    return 0;
}

///############################ BFS ##################################
///###################################################################
