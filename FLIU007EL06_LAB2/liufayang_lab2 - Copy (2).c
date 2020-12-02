#include<stdio.h>
#define maxV 100

int V,E,x,y;
int m =0;
int a[maxV][maxV];
int visit[maxV];
int DFS[maxV][maxV];
int count=0;
int component =1 ;

void read_graph(void);
void print_graph(void);

void main(){
    read_graph();
    print_graph();
    Check_Connectivity();
    printf("\nThere exist %d disconnected components.\n",component);
    for(int n=1;n<=component;n++){
        printf("Component %d (vertex): ",n);
        for(int m=0;m<V;m++){
            printf("%d",DFS[n-1][m]);
        }
        printf("\n");
    }

    for(int i=0;i<component;i++){
        for(int j=maxV;j>0;j--){
            if(DFS[i][j]!=0 && DFS[i][j-1]!=0){
                printf("Vertex %d's parent is %d\n",DFS[i][j],DFS[i][j-1]);
            }
        }
        printf("Vertex %d has no parent.\n",DFS[i][0]);
    }
}

void read_graph(void){
    int edge,x;
    printf("\nInput number of vertices :");
    scanf("%d", &V);
    if(V>maxV)
        printf("Exceed the maximum number of vertices permitted.");
    else{
        for(x=1;x<=V;x++)
            for(y=1;y<=V;y++)
                a[x][y]=0;

        for(x=1;x<=V;x++)
            for(y=1;y<=V;y++){
                printf("\na[%d][%d]=",x,y);
                scanf("%d", &edge);
                a[x][y]=edge;
                a[y][x]=edge;
            }
    }
}

void print_graph(void){
    int x,y;
    for(x=1;x<=V;x++){
        for(y=1;y<=V;y++){
             printf("a[%d][%d]=%d  ", x, y, a[x][y]);
        }
        printf("\n");
    }

}

void Check_Connectivity(){
    for(int i=1;i<=V;i++){
        visit[i] = 0;
    }



    printf("\nVisiting sequence :");
    dfs(1);


    for(int i=V;i>0;i--){
        if(visit[i] == 0){
            component = component +1;
            dfs(i);
            }

    }

    return 1;
}

void dfs(v){
    visit[v]=1;
    printf("%d",v);

    DFS[component-1][m]=v;
    m+=1;

    for(int i=V;i>0;i--){
        if(a[v][i]!=0 && visit[i]==0){
            dfs(i);
        }
    }
    m=0;
}
