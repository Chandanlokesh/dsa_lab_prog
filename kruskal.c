#include<stdio.h>
#include<conio.h>

void main(){
	int v,i,j,n,u,a,b,min;
	int count=1,mincost=0;
	int cost[20][20],parent[20]={0};
	printf("enter the number of vertices:");
	scanf("%d",&n);
	printf("\nenter the cost of the matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]==999;
			}
		}
	}
	while(count<n){
		min=999;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(parent[u])
			u=parent[u];
		while(parent[v])
			v=parent[v];
		if(u!=v)
		{
			count++;
			printf("\n Edge(%d,%d)=%d",a,b,min);
			mincost+=min;
			parent[v]=u;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n minimum cost=%d",mincost);
	getch();
}