#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[100];     
    int N, ITEM, k;
    int i,j;

    printf("Dizinin eleman sayisini girin: ");
    scanf("%d", &N);

    printf("Dizi elemanlarini girin:\n");
    for( i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("Eklenecek elemani girin: ");
    scanf("%d", &ITEM);

    printf("Eklenecek indexi girin: ");
    scanf("%d", &k);

    // Elemanlari saga kaydir
    for(j = N - 1; j >= k; j--) {
        A[j + 1] = A[j];
    }

    // Yeni elemani ekle
    A[k] = ITEM;
    N++;

    printf("Yeni dizi:\n");
    for( i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
