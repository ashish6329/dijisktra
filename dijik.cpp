#include<iostream>
using namespace std;
void dijkstra(int G[20][20],int n,int source)
{
 
    int weight[20][20],distance[20],pred[20], check[20],count,minimum,next,i,j;
    
    /*
    while(count<0)*/
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
            {
                weight[i][j]=1000;
            }
            else
            {
                weight[i][j]=G[i][j];
            }
          }
    }
    
    
    for(i=0;i<n;i++)
    {
        distance[i]=weight[source][i];
        pred[i]=source;
        check[i]=0;
    }
    
    distance[source]=0;
    check[source]=1;
    
    
    for(count=1;count<(n-1);count++)
    {
        minimum=1000;
        
        
        for(i=0;i<n;i++)
        {
        
            if(distance[i]<minimum && (check[i]!=1))
            {
                minimum=distance[i];
                next=i;
            }
                     
            check[next]=1;
         }
            for(i=0;i<n;i++)
            {
                if(check[i]!=1)
                    if((minimum+weight[next][i])<(distance[i]))
                    {
                        distance[i]=minimum+weight[next][i];
                        pred[i]=next;
                    }
            }
        
    }
 
    
    for(i=0;i<n;i++)
    {
        if(i!=source)
        {
            
            cout<<endl<<"path find using dijistra algo "<<i;
            j=i;
            do
            {
                j=pred[j];
                cout<<"\t"<<j;
            }
            while(j!=source);
            
    }
    }
}
main()
{
    int G[20][20],i,j,n,u;
    cout<<"enter no. of vertices"<<endl;
    cin>>n;
    cout<<"eneter the matrix from graph"<<endl;
    cout<<"enter the  matrix"<<endl;
    cout<<"enter only adjacency matrix"<<endl;
    for(i=0;i<n;i++)

    {
        for(j=0;j<n;j++)
        {
            cin>>G[i][j];
        }
    }
    cout<<"source is zero vertex"<<endl;
    int sr=0;
    cout<<"destination is"<<"\t"<<n<<"vertex"<<endl;
    dijkstra(G,n,sr);
}
