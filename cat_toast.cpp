#include <iostream>
using namespace std;
int visited[1005];
int px[1005], py[1005];
int r,count,n;
int dist2(int l,int r)
{
    int dis=(px[l]-px[r])*(px[l]-px[r])+(py[l]-py[r])*(py[l]-py[r]);
    return dis;
}
void dfs(int now)
{
    if(visited[now]) return;
    visited[now]=1;
    for(int i=0;i<n;i++)
    {
        if(dist2(now,i)<=r*r&&i!=now)
        {
            count++;
            dfs(i);
        }
    }
}
int main()
{
    int alone=0;
    int group=0;
    cin>>n>>r;
    count=n;
    for(int i=0;i<n;i++)
    {
        cin>>px[i]>>py[i];
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            count=0;
            dfs(i);
            if(count>0) group++;
            else alone++;
        }
    }
    cout<<alone<<" "<<group<<endl;
}
