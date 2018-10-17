#include <stdio.h>
#include <stdlib.h>

int main()
{
  int nodes;
  int undirectedEdges;

  //Enter the number of nodes
  scanf("%d", &nodes);
  //Enter number of edges
  scanf("%d", &undirectedEdges);
  //Create a pointer of a pointer to point towards a pointer... these things are pure evil
  int ** edges = (int **)malloc(sizeof(int*)*undirectedEdges);
  //Allocate space off the heap to store an int pointer
  for(int i = 0; i < undirectedEdges; i++)
    edges[i] = (int *) malloc(sizeof(int)*3);

  //Build the matrix
  int ** dist = (int **) malloc(sizeof(int *)*nodes);
  for(int i = 0; i <= nodes; i++){
    dist[i] = (int *) malloc(sizeof(int)*nodes);
  }

  //Give values to edges. 0 if i == j, else change to 2
  for(int i = 0; i < nodes; i++)
  {
    for(int j = 0; j < nodes; j++)
    {
      if(i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = 2;
    }
  }
  
 
  //Enter the edges (1 2 1, 2 3 1, 3 4 1, 4 1 1, etc)
  for(int i = 0; i < undirectedEdges; i++)
  {
    scanf("%d %d %d", &edges[i][0],&edges[i][1], &edges[i][2]);
				   dist[edges[i][0]][edges[i][1]] = edges[i][2];
                   dist[edges[i][1]][edges[i][0]] = edges[i][2];
  }
  
  //fw alg
  for(int k = 0; k <= undirectedEdges; k++)
  {
    for(int i = 0; i < undirectedEdges; i++)
    {
      for(int j = 0; j < undirectedEdges; j++)
      {
        if(dist[i][k] + dist[k][j] < dist[i][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  } 

  //print matrix
  for(int i = 0; i < nodes; i++)
  {
    for(int j = 0; j < nodes; j++)
      printf("%d ", dist[i][j]);
    printf("\n");
  }

  return 0;
}

