#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//////////////////////////////////Merge Sort
void interclasare(int *x,int *v,  int sx, int fx, int sy, int fy)
{
    int t;
	int i = sx, j = sy, k = 0;
	while (i <= fx && j <= fy)
	{
		if (x[i] <= x[j])
		{
			v[++k] = x[i];
			++i;
		}
		else
		{
			v[++k] = x[j];
			++j;
		}
	}
	if (i>fx)
		for (t = j;t <= fy;++t)
			v[++k] = x[t];
	if (j>fy)
		for (t = i;t <= fx;++t)
			v[++k] = x[t];

	for (i = 1;i <= k;i++)
		x[sx + i - 1] = v[i];

}

void mergesort(int *x,int *v, int s, int f)
{
	if (s != f)
	{
		mergesort(x,v,  s, (s + f) / 2);
		mergesort(x,v, (s + f) / 2 + 1, f);
		interclasare(x,v, s, (s + f) / 2, (s + f) / 2 + 1, f);
	}
}
void print(int *a, int n)
{
    int i;
    for (i = 1; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//Heap sort

typedef struct node  {
    int data;
    struct node *l;
    struct node *r;
} node_heap;
void initialise_heap(node_heap **root, int data)
{
	*root = (node_heap*)malloc(sizeof(node_heap));

	(*root)->data = data;
	(*root)->l = NULL;
	(*root)->r = NULL;
}


void add_to_heap(node_heap *root, int data)
{
	if (data < root->data)
	{
		if (root->l == NULL)
		{
			node_heap *temp_node_heap = (node_heap*)malloc(sizeof(node_heap));
			temp_node_heap->data = data;
			temp_node_heap->l = 0;
			temp_node_heap->r = 0;

			root->l = temp_node_heap;

		}
		else
			add_to_heap(root->l, data);
	}
	else
	{
		if (root->r == NULL)
		{
			node_heap *temp_node_heap = (node_heap*)malloc(sizeof(node_heap));
			temp_node_heap->data = data;
			temp_node_heap->l = 0;
			temp_node_heap->r = 0;

			root->r = temp_node_heap;
		}
		else
			add_to_heap(root->r, data);
	}

}

void heap_sort(node_heap *root, int *vec, int *size)
{
	if (root->l != 0)
		heap_sort(root->l, vec, size);

	*size = *size + 1;
	vec[*size] = root->data;

	if (root->r != 0)
		heap_sort(root->r, vec, size);
}
//////////////////////////////////DFS
    //////////////////////////////////Matrix Implementation
void DFS(int);
int G[10][10],visited[10],n;

void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;

    for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}
/*8
0 1 1 1 1 0 0 0
1 0 0 0 0 1 0 0
1 0 0 0 0 1 0 0
1 0 0 0 0 0 1 0
1 0 0 0 0 0 1 0
0 1 1 0 0 0 0 1
0 0 0 1 1 0 0 1
0 0 0 0 0 1 1 0 */

    //////////////////////////////////List Implementation

typedef struct node
{
    struct node *next;
    int vertex;
}node;

node *G[20];
int visited[20];

void DFS2(int i)
{
    node *p;

    printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;

       if(!visited[i])
            DFS2(i);
        p=p->next;
    }
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    FILE *fp;
    fp = fopen("filedfs" ,"r");
    //printf("Enter number of vertices:");

    fscanf(fp,"%d",&n);
    printf("%d", n);

    for(i=0;i<n;i++)
    {
        G[i]=NULL;

        //printf("Enter number of edges:");
        fscanf(fp,"%d",&no_of_edges);

           for(i=0;i<no_of_edges;i++)
        {
            //printf("Enter an edge(u,v):");
            fscanf(fp,"%d %d",&vi,&vj);
            insert(vi,vj);
        }
    }
}

void insert(int vi,int vj)
{
    node *p,*q;

    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;

    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        p=G[vi];

        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

//////////////////////////////////BFS
#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

void BF_Traversal()
{
    int v;

    for(v=0; v<n; v++)
        state[v] = initial;

    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &v);//0
    BFS(v);
}

void BFS(int v)
{
    int i;

    insert_queue(v);
    state[v] = waiting;

    while(!isEmpty_queue())
    {
        v = delete_queue( );
        printf("%d ",v);
        state[v] = visited;

        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front+1;
    return delete_item;
}

void create_graph()
{
    int count,max_edge,origin,destin;
    FILE *fp;
    fp = fopen("filebfs", "r");
    //printf("Enter number of vertices : ");
    fscanf(fp,"%d",&n);
    max_edge = n*(n-1);

    for(count=1; count<=max_edge; count++)
    {
        fscanf(fp,"%d %d",&origin,&destin);

        if((origin == -1) && (destin == -1))
            break;

        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}

//////////////////////////////////Gen Backtraking
void  init(int *st, int k)
{
	st[k] = 0;
}

int succesor(int *st, int k, int N)
{
	if (st[k]<N)
	{
		++st[k];
		return 1;
	}
	return 0;
}

int solutie(int *st, int k, int N)
{
	return k == N;
}
void tipar(int *st, int k)
{
	for (int i = 1;i <= k;i++)
		printf("%d", st[i]);

	printf("\n");
}
int valid(int *st, int k)
{
	for (int i = 1;i<k;i++)
		if (st[i] == st[k])
			return 0;
	return 1;
}
void bkt(int *st, int k, int N)
{
	init(st, k);
	while (succesor(st, k, N))
	{
		if (valid(st, k))
			if (solutie(st, k, N))
				tipar(st, k);
			else
				bkt(st, k + 1, N);
	}
}
