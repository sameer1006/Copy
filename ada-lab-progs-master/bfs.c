#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>

int q[30], f = 0, r = -1;							//f and r is queue 								
int visited[20];

void bfs(int v, int n, int a[][n]) {				//v is source node
    int i;
    visited[v] = 1;									//source node is marked as 1 initially 

    for (i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {				//running through all the nodes, not visited
            q[++r] = i;								//checking if there's link between source node and all other nodes
        }											//pushes all nodes that have a link with source and node
    }												//direct connection from node to source

    while (f <= r) {
        visited[q[f]] = 1;							//q[f] has index values. stores value 0 or 1
        
        printf("Visited node index: %d\t", q[f++]); //visited output
    }

    f = 0;
    r = -1;

    if (v < n - 1) {						//checks if it is on the last node
        bfs(v + 1, n, a);					//makes next row as source vertex
    }
}

int main(void) {
    struct timeval tv1, tv2;
    int i, j, n;
    struct rusage r_usage;
    
    printf("Enter number of nodes\n");
    scanf("%d", &n);

    int a[n][n];
    
    printf("Enter the matrix elements\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter index for source node\n");
    scanf("%d", &i);

    printf("Source node is %d\n", i);

    gettimeofday(&tv1, NULL);
    bfs(i, n, a);
    gettimeofday(&tv2, NULL);

    printf("Time of bfs = %.2f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage %ld kilobytes\n", r_usage.ru_maxrss);

    return 0;
}
