// Input:
// N = 4
// M = 3
// E = 5
// Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
// Output: 
// 1
// Explanation: 
// It is possible to colour the given graph using 3 colours.

int adjacent(vector<int>& colours,bool graph[101][101],int node,int colour,int n)
{
    for(int i=0;i<n;i++)
    {
        if(graph[node][i])// || graph[i][node])
            if(colour==colours[i])
                return 1;
    }
    return 0;
}
int assign(int node,vector<int>& colours,bool graph[101][101],int n,int m)
{
    if(node==n)
        return 1;
    for(int i=1;i<=m;i++)
    {
        if(!adjacent(colours,graph,node,i,n))
        {
            colours[node]=i;
            if(assign(node+1,colours,graph,n,m))
                return 1;
            colours[node]=0;
        }
    }
    return 0;
}
bool graphColoring(bool graph[101][101], int m, int n) 
{
    vector<int>colours(n,0);
    return assign(0,colours,graph,n,m);
}
