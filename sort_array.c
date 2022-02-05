#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** createArrayOfArrays(int n) {
    if(n <= 0) {
        return NULL;
    }
    int** a =(int**)malloc(sizeof(int*) * n);
    if(a == NULL) {
        return NULL;
    }
    int arrSize = 16;
    for(int k = 0; k < n; ++k) {
        a[k] = (int*)malloc(sizeof(int) * arrSize);
        if(a[k] == NULL) {
            for(int j = 0; j < k; ++j) {
                free(a[j]);
            }
            free(a);
            return NULL;
        }
        for(int j = 0; j < arrSize-1; ++j) {
            a[k][j] = rand()%1000;
        }
        a[k][arrSize-1] = INT_MIN;
        //bubble sort
        while(1) {
            int ok = 1;
            for(int j = 0; j < arrSize-2; ++j) {
                if((k%2 == 1 && a[k][j] > a[k][j+1]) || (k%2 == 0 && a[k][j] < a[k][j+1])) {
                    int tmp = a[k][j];
                    a[k][j] = a[k][j+1];
                    a[k][j+1] = tmp;
                    ok = 0;
                }
            }
            if(ok) break;
        }
        arrSize += 4 * (rand()%2 + 1);
    }
    return a;
}

int main(void) {
    int n = 0;
    fprintf(stdout, "input number of arrays: ");
    int z = fscanf(stdin, "%d", &n);
    if(z == 0) {
        fprintf(stderr, "incorrect input\n");
        return 1;
    }
    int** pointers = createArrayOfArrays(n);
    if(pointers == NULL) {
        fprintf(stderr, "incorrect n or not enough memory\n");
        return 1;
    }
    for(int k = 0; k < n; ++k) {
        int j = 0;
        while(pointers[k][j] != INT_MIN) {
            fprintf(stdout, "%d ", pointers[k][j]);
            ++j;
        }
        fprintf(stdout, "\n\n");
    }
    for(int j = 0; j < n; ++j) {
        free(pointers[j]);
    }
    free(pointers);

    return 0;
}
