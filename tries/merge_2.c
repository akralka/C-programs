#include <stdio.h>

// funkcja bubble sort, ktora posortuje nam obie tablice
void sort(int t[], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N-i-1; j++){
            if(t[j] > t[j+1]){
                int x = t[j];
                t[j] = t[j+1];
                t[j+1] = x;
            }
        }
    }
}


//funkcja wypisujaca tablice
void wypisz(int t[], int N){
    for(int i=0; i<N; i++){
        printf("%d, ", t[i]);
    }
    printf("\n");
}


int merge(int t1[], int N1, int t2[], int N2, int t[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<N1 && j<N2){
        if(t1[i] <= t2[j]){
            if(t[k-1] != t1[i] || k == 0) {
                t[k] = t1[i];
                k++;
            }
            i++;
        } else if(t1[i] > t2[j]){
            if(t[k-1] != t2[j] || k == 0) {
                t[k] = t2[j];
                k++;
            }
            j++;
        }
    }

    // wprowadzamy reszte tabeli, ktorej jeszcze nie wprowadzilismy
    if(i == N1){
        while(j < N2){
            if(t[k-1] != t2[j] || k == 0) {
                t[k] = t2[j];
                k++;
            }
            j++;
        }
    } else {
        while(i < N1){
            if(t[k-1] != t1[i] || k == 0) {
                t[k] = t1[i];
                k++;
            }
            i++;
        }
    }
    return k;
}


int main() {
    int t1[] = {1, 2, 2, 5, 5, 5, 6, 6, 8, 9};
    int t2[] = { 1, 1, 1, 2, 4, 5, 6, 6, 8, 8, 8, 9, 9, 10, 10};
    int t[11];

    sort(t1, 10);
    sort(t2, 15);

    printf("t1: ");
    wypisz(t1, 10);

    printf("t2: ");
    wypisz(t2, 15);

    int l = merge(t1, 10, t2, 15, t);

    printf("Posortowana tabela: ");
    wypisz(t, l);
    return 0;
}
