#include <stdio.h>

int main(void) {
    int n, i, j, a[10][10], s[10], d[10], v, k, min, u;

    printf("Enter the number of vertices\n");					//s[] holds if a node has been added to MST or not
    scanf("%d", &n);

    printf("Enter the cost matrix \n");
    printf("Enter 999 if no edge between vertices \n");
																//distance, cost, weight are all same
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the source vertex \n");
    scanf("%d", &v);
    // start from here
    for (i = 1; i <= n; i++) {
        s[i] = 0;									//initialise all nodes as 0 in s[] array
        d[i] = a[v][i];								//d[] holds distance from v to all nodes 
    }
    
    d[v] = 0;										//cost of a node going to itself is 0
    s[v] = 1;										//mark source as 1 
    for (k = 2; k <= n; k++) {						
        min = 999;									//initialise	
        for (i = 1; i <= n; i++) 
            if (s[i] == 0 && d[i] < min) {			//has the node been visited? if not, ok && d[i]<min means min is being 															initiliased and replaced  
                min = d[i];							//min value, (smallest weight, cost, path)
                u = i;								//holds index of min
            }
        s[u] = 1;									//shortest destination node is added to MST
        for (i = 1; i <= n; i++) 
            if (s[i] == 0) {						//hasn't been added to MST yet					
                if (d[i] > (d[u] + a[u][i]))		//if distance is greater than this path
                    d[i] = d[u] + a[u][i];			//this path being least distance is now the new distance
            }
    }
         
    printf("The shortest distance from %d is \n", v);
    for(i = 1; i <= n; i++)
        printf("%d --> %d = %d\n", v, i, d[i]);

    return 0;
}
