#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define A_SIZE 20 // A dizisinin uzunlugu tanimlanmis
#define G_SIZE 10 // G grafinin uzunlugu tanimlanmis dugum sayisi
#define MAX_W 10 // En yuksek agirlik tanimlanmis

//Max deger icin sonsuz sayi
#define INF INT_MAX

void generateRandomArray(int a[], int size);  // a dizisini olusturur
void quickSort(int a[], int low, int high); // quick sort ile siralar
int avgPositiveNumbers(int a[], int size); // pozitif elemanlarindan olusan alt dizinin ortalamasi int 
void floydWarshall(int g[][G_SIZE], int d[][G_SIZE], int size); //Floyd-Warshall algortimasi
void printArray(int a[], int size); // dizinin elemanlari 10 elemanda bir alt satira gecerek yazdirir.
void printGraph(int g[][G_SIZE], int size); // grafin matris temsilini yazdirir kenar agirligi sonsuza esitse inf degilse degeri varsa onu yazdirir
void printShortestDistances(int g[][G_SIZE], int size, int t); // ortalama t degerine ataniyor ve t agirligindan kucuk olan kenarlar ve dugumleri bastiriliyor

int main() {
    int a[A_SIZE];
    // 10 dugumlu agirlikli grafin matris temsili
    int g[G_SIZE][G_SIZE] = {                 
    { 0, 10,  3,  0,  0,  5,  0, 17,  0, 22},
    {10,  0,  5,  0,  2,  0, 13,  0,  0,  0},
    { 3,  5,  0,  2,  0,  4,  0, 21,  0, 11},
    { 0,  0,  2,  0,  7,  0,  6,  0,  0,  0},
    { 0,  2,  0,  7,  0,  6,  0,  0, 19,  0},
    { 5,  0,  4,  0,  6,  0,  9,  3,  0,  0},
    { 0, 13,  0,  6,  0,  9,  0,  4,  0,  0},
    {17,  0, 21,  0,  0,  3,  4,  0,  8,  0},
    { 0,  0,  0,  0, 19,  0,  0,  8,  0,  5},
    {22,  0, 11,  0,  0,  0,  0,  0,  5,  0}
    };
    int distance[G_SIZE][G_SIZE]; // uzaklik
    int threshold; // eşik değeri

    // Rastgele sayi uretici icin seed
    srand(time(NULL));

    // Calisma suresinin hesaplanmasi
    clock_t start, end;
    double time;

    start = clock();

    generateRandomArray(a, A_SIZE);
    printf("A:\n");
    printArray(a, A_SIZE);

    quickSort(a, 0,A_SIZE-1);
    printf("\nquickSort Sonuc:\n");
    printArray(a, A_SIZE);

    threshold = avgPositiveNumbers(a, A_SIZE);
    printf("\navgPositiveNumbers Sonuc: %d\n", threshold);

    printf("\nG:\n");
    printGraph(g, G_SIZE);

    floydWarshall(g, distance, G_SIZE);
    printf("\nfloydWarshall Sonuc:\n");
    printGraph(distance, G_SIZE);

    printf("\n%d icin sonuc:\n", threshold);
    printShortestDistances(distance, G_SIZE, threshold);

    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", time);

    return 0;
}
//max w degeri 10 oldugundan -10 ile 9 arasında rastgele bir sayi olusturur ve dizinin elemanlarina atar 
void generateRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % (2 * MAX_W) - MAX_W;
    }
}

// Elemanları yer degistirme
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hızlı sıralama algoritması
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot elemanını son eleman olarak seçme
    int i = (low - 1); // Düşük indisi başlangıçta -1 olarak ayarlama

    for (int j = low; j <= high - 1; j++) {
        // Mevcut eleman pivot'tan küçükse, i'yi artırılır ve elemanları takas edilir
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Pivot elemanı taşıma
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Diziyi bölen indeks atama
        int pi = partition(arr, low, high);

        // Parçaları ayrı ayrı sıralama
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int avgPositiveNumbers(int a[], int size) {
    int t = 0, current_sum = 0, count=0;
    for (int i = 0; i < size; i++) {
        if (current_sum + a[i] > 0) {
            current_sum = current_sum + a[i];
        }
        else {
            current_sum = 0;
        }
        if (current_sum > t) {
            t = current_sum;
            count++;
        }
    }
    return t/count;
}

void floydWarshall(int g[][G_SIZE], int d[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                d[i][j] = 0;
            }
            else if (g[i][j] != 0) {
                d[i][j] = g[i][j];
            }
            else {
                d[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (d[i][k] != INF && d[k][j] != INF &&
                    d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

void printGraph(int g[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (g[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%3d ", g[i][j]);
            }
        }
        printf("\n");
    }
}

void printShortestDistances(int d[][G_SIZE], int size, int t) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && d[i][j] < t) {
                printf("%c -> %c: %d\n", 'A' + i, 'A' + j, d[i][j]);
            }
        }
    }
}