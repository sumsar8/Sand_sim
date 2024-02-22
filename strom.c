#include <stdio.h>
#include <stdbool.h>

int main() {
    int array[10][10];
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            array[y][x] = 0;
        } 
    }
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            printf("%d ",array[y][x]);
        } 
        printf("\n");
    } 
    printf("\n");
    array[3][3] = 1;
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            printf("%d ",array[y][x]);
        } 
        printf("\n");
    }
    
    return 0;
}
