#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>

void maxheap(int h[], int n) {
    int i, j, k, v, heap;
    for (i = n/2; i >= 1; i--) {				//parent node > both children
        k = i;									// n/2 gives index of the right most parent, k points to right most parent
        v = h[k];								//v points to value of right most parent
        heap = 0;
        while (heap == 0 && 2 * k <= n) {		// 2*k is always less than or equal to n. k is right most parent
            j = 2 * k;							//j points to left child of k(right most parent)
            if (j < n) {						// this condition checks if right h=child is present 
                if (h[j] < h[j + 1])			// nth child is right child. if j<n, ie right child exists
                    j++;						// compare left and right child, if right child greater, j points to right child 
            }									
            if (v >= h[j])						//parent > child						
                heap = 1;						// mark heap as 1
            else {								
                h[k] = h[j];					//overwrite parent with child
                k = j;							// see the exchanged nodes, child
            }
            h[k] = v;							//v holds root node value
        }
    }
}

void heapsort(int h[], int n) {
    int temp, i;
    for (i = n; i >= 1; i--) {			//keep calling max heap func
        maxheap(h, i);					//h = heap
        temp = h[1];					
        h[1] = h[i];					
        h[i] = temp;					//parent node and right most node are getting swapped
    }									//you're ignoring the right most node because i--
}										

int main(void) {
    struct timeval tv1, tv2;
    struct rusage r_usage;
    int i, n, a[20];
    printf("Enter the input size\n");
    scanf("%d", &n);
    printf("Enter elements\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    gettimeofday(&tv1, NULL);
    heapsort(a, n);
    gettimeofday(&tv2, NULL);
    
    printf("Sorted elements\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nTime taken = %0.2f microseconds\n", (double) (tv2.tv_usec - tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory consumed = %ld kilobytes\n", r_usage.ru_maxrss);
    
    return 0;
}
