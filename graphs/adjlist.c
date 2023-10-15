#include <stdio.h>
#include <stdlib.h>

struct node{
	int vertex;
	int weight;
	struct node* next;
};

struct graph{
	int numVertices;
	struct node** adjlist;
};

struct node* createNode(int vertex, int weight){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->vertex = vertex;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

void add_edge(struct graph* G, int u, int v, int w){
	struct node* newNode = createNode(v, w);
	newNode->next = G->adjlist[u-1];
	G->adjlist[u-1] = newNode;
	return;
}

int main(){
	// n - number of vertices
	// m - number of edges;
	int n, m;
	printf("Enter |V| and |E| : ");
	scanf("%d %d", &n, &m);
	struct graph* G = (struct graph*)malloc(sizeof(struct graph));
	G->numVertices = n;
	G->adjlist = (struct node**)calloc(n, sizeof(struct node*)); // every list is NULL
	
	printf("\n");
	int u, v, w;
	printf("Enter Edges\n");
	// Directed Weighted Graph
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &w);
		add_edge(G, u, v, w);	
	}
	
	// printing the adjacency list
	for(int i = 0; i < n; i++){
		printf("vertex = %d : ", i+1);
		struct node* head = G->adjlist[i];
		while(head != NULL){
			printf("%d w = %d, ", head->vertex, head->weight);
			head = head->next;
		} 
		printf("\n");
	}
	return 0;
}
