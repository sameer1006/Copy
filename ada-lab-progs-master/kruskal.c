#include <stdio.h>

int min, cost[100][100], parent[100], i, j, x, y, n;		//kruskal has no source node

void find_min() {								//MST has no cycles
    min = 999;									//set to some large value
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (cost[i][j] < min) {				//cost is less than min
                min = cost[i][j];				//that is the new min value
                x = i;							//x, y hold the value of the cheapest paths
                y = j;							//min holds the cheapest value
            }
}
int check_cycle(int x, int y) {
    if((parent[x] == parent[y]) && (parent[x] != 0))	//already added to the MST, it gives cycle
        return 0;
    else if (parent[x] == 0 && parent[y] == 0)
        parent[x] = parent[y] = x;						//unique value that is common to all the nodes connected directly or 																indirectly within MST is reassigned x.
   
    else if (parent[x] == 0)							// y exists, x doesn't				
        parent[x] = parent[y];
    else if (parent[x] != parent[y])					// x exists, y doesn't
        parent[y] = parent[x];
    return 1;
}

int main(void) {
    int count = 0, tot = 0, flag=0;
    printf("Enter the number of vertices \n");
    scanf("%d", &n);
    printf("Enter the cost matrix \n");
    printf("Enter 999 for No edges and self loops \n");		
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);						//input is cost matrix
            parent[j] = 0;									//initilises all values as 0 in parent[]
        }

    // start here
    while (count != n - 1 && min != 999) {					
        find_min();
        flag = check_cycle(x,y);							//cheapest path index is passed as parameter
        if (flag == 1) {
            printf("\n%d --> %d = %d\n", x, y, cost[x][y]);
            count++;
            tot += cost[x][y];
        }
        cost[x][y] = cost[y][x] = 999;					//remove shortest path from being considered in next iteration
    }
    printf("\nThe total cost of minimum spanning tree = %d", tot);

    return 0;
}
