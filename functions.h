#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "functions.c"

void interclasare(int *x,int *v,  int sx, int fx, int sy, int fy);
void mergesort(int *x,int *v, int s, int f);
void print(int *a, int n);

void initialise_heap(node_heap **root, int data);
void add_to_heap(node_heap *root, int data);
void heap_sort(node_heap *root, int *vec, int *size);

void DFS(int i);
void DFS2(int i);
void read_graph();
void insert(int vi,int vj);
void BF_Traversal();

void BFS(int v);
void insert_queue(int vertex);
int isEmpty_queue();
int delete_queue();
void create_graph();

void  init(int *st, int k);
int succesor(int *st, int k, int N);
int solutie(int *st, int k, int N);
void tipar(int *st, int k);
int valid(int *st, int k);
void bkt(int *st, int k, int N);

#endif // FUNCTIONS_H_INCLUDED
