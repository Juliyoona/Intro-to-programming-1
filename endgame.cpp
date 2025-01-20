#include<iostream>
//#include<-std=c++17>
#include<queue>
#include<tuple>
using namespace std;

int n,m;
char table[1005][1005];
queue<tuple<int,int,int>> q;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int ans=0;
int d=0;

void bfs()
{
    while(!q.empty())
    {
        auto [x,y,s]=q.front();
        q.pop();
        if(x<0||n<=x) continue;
        if(y<0||n<=y) continue;
        if(table[x][y]=='C') continue;
        if(table[x][y]=='T') ans=max(ans,s),d--;
        table[x][y]='C';
        for(int i=0;i<4;i++)
        {
           q.push({x+dx[i],y+dy[i],s+1});
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) scanf("%s",&table[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(table[i][j]=='I') q.push({i,j,0});
            else if(table[i][j]=='T') d++;
        }
    }
    bfs();
    printf("%d\n",d!=0?-1:ans);
}