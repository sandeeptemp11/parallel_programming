#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <omp.h>
#include "time.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

// Single Source Shortest Path
void bfs(int s, struct graph* G, int pred[], long long int dis[]){
	for(int u = 1; u <= G->numVertices; u++){
		pred[u-1] = -1;
		dis[u-1] = LLONG_MAX;
	}
	
	dis[s-1] = 0;
	bool relaxed;
	while(true){
		relaxed = false;
		for(int u = 1; u <= G->numVertices; u++){
			struct node* head = G->adjlist[u-1];
			while(head != NULL){
				int v = head->vertex;
				int w = head->weight;
				if(dis[u-1] != LLONG_MAX && dis[v-1] > dis[u-1] + w){
					dis[v-1] = dis[u-1] + w;
					pred[v-1] = u;
					relaxed = true;
				}
				head = head->next;		
			}
		}
		printf("\n");
		for(int u = 1; u <= G->numVertices; u++){
			printf("Vertex %d : pred = %d, distance = %lld\n", u, pred[u-1], dis[u-1]);
		}		
		if(!relaxed) break;
	}
	return;
}


int main(){
	// n - number of vertices
	// m - number of edges;
	
	int input_fds = open("./input.txt", O_RDONLY | O_CREAT);
	dup2(input_fds, STDIN_FILENO);
	if(input_fds < 0){
		printf("File open failure\n");
		return 0;
	}	
	
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
	
	int s;
	printf("Enter source: ");
	scanf("%d", &s);
	int pred[G->numVertices];
	long long int dis[G->numVertices];
	
	double t1 = rtclock();
	bfs(s, G, pred, dis);
	double t2 = rtclock();
	printf("\nTime: %f\n", t2-t1); 	
	close(input_fds);
	return 0;
}
