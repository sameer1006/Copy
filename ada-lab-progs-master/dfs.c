#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>

int visited[10];

int dfs(int v, int n, int a[][n]) {
    int i;
    visited[v] = 1;								//initial source node is 1
    printf("Visited node: %d\n", v);			//print, at a time we visit only one node

    for (i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {			//path from source node to next node
            dfs(i, n, a);						//node shouldn't be visited
        }										//so, node i can be visited, pass i as source node
    }
}

int main(void) {
    struct timeval tv1, tv2;
    int i, j, n;
    struct rusage r_usage;
    
    printf("Enter row size\n");
    scanf("%d", &n);

    int a[n][n];
    
    printf("Enter the matrix elements\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter index for source node\n");
    scanf("%d", &i);

    printf("Source node is %d\n", i);

    gettimeofday(&tv1, NULL);
    dfs(i, n, a);
    gettimeofday(&tv2, NULL);

    printf("Time of dfs = %.2f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec));

    getrusage(RUSAGE_SELF, &r_usage);

    printf("Memory usage %ld kilobytes\n", r_usage.ru_maxrss);

    return 0;
}
