
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* auxiliary subarray dimension */
#define maxN 1000000000

#define M 10

#define N 10

/* declaration of type of objects to sort*/
typedef int item;

#define key(A) (A) 
#define less(A, B) (key(A) < key(B)) 
#define exch(A, B) { item t = A; A = B; B = t; } 
#define compexch(A, B) if (less(A, B)) exch(A, B) 
#define min(A, B) (A < B) ? A : B 

/* auxiliary subtable */
item aux[maxN];
/* Insertion Sort Algorithm (Inefficient Implementation) */ //insertionsort
void insertionsort2(item * a, int n);

/* Insertion Sort Algorithm (Efficient Implementation) */ //insertionsort
void insertionsort(item * a, int n);

void mergesort(item * a, int l, int r); //mergesort

void merge(item * a, int l, int m, int r); //merge function that helps into mergesort algorithm

void quicksort(item * a, int l, int r); //quicksort

int partition(item a[], int l, int r); //partition function that helps into quicksort

void sort(item * a, int n); //improved quicksort

void renewal(item * a,item * b, int n);//renewal of the array


int main() {
  int i, j, m, n = 0; //variables declaration
  item * a;
  item * b;
  double insertionsortcounter = 0;
  double sortcounter = 0;
  double mergesortcounter = 0;
  double insertionsortavg; //variables declaration
  double sortavg;
  double mergesortavg;
  double total_insertion_sort_avg;
  double total_improved_quicksort_avg;
  double total_nonrec_mergesort_avg;
  double total_insertion_sort_counter = 0;
  double total_improved_quicksort_counter = 0;
  double total_nonrec_mergesort_counter = 0;

  clock_t start, end;
  double cpu_time_used; //clock() declaration
  srand(time(NULL));

  for (m = 0; m < N; m++) {
    n += 10000;

    /* memory allocation */
    a = (item * ) malloc(n * sizeof(item));
    if (a == NULL) {
      printf("Error while allocating memory!!!");
      return -1;
    }

    /* memory allocation */
    b = (item * ) malloc(n * sizeof(item));
    if (b == NULL) {
      printf("Error while allocating memory!!!");
      return -1;
    }

    for (j = 0; j < N; j++) {

      /* initialize the array with random integer values */
      for (i = 0; i < n; i++) {
        a[i] = rand();
        b[i] = a[i];
      }

      renewal(a, b, n);  //function to renew the array a[]
     
      start = clock();
      insertionsort(a, n); //insertionsort algorithm implementation and time measurement
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      insertionsortcounter += cpu_time_used;
      
      renewal(a, b, n);  //function to renew the array a[]
 
      start = clock();
      sort(a, n); //improved quicksort algorithm implementation and time measurement
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      sortcounter += cpu_time_used;
      
      renewal(a, b, n);   //function to renew the array a[]
 
      start = clock();
      mergesort(a, 0, n - 1); //mergesort algorithm implementation and time measurement
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      mergesortcounter += cpu_time_used;
    
    }

    insertionsortavg = insertionsortcounter / N; //insertionsort algorithm average
    printf("AVERAGE INSERTIONSORT TIME AT DIMENSION OF %d IS: %lf \n", n, insertionsortavg);
    sortavg = sortcounter / N; //improved quicksort algorithm average
    printf("AVERAGE IMPROVED_QUICKSORT TIME AT DIMENSION OF %d IS: %lf\n", n, sortavg);
    mergesortavg = mergesortcounter / N; //nonrec mergesort algorithm average
    printf("AVERAGE NONREC_MERGESORT TIME AT DIMENSION OF %d IS: %lf\n\n", n, mergesortavg);
    total_insertion_sort_counter += insertionsortavg;
    total_improved_quicksort_counter += sortavg;
    total_nonrec_mergesort_counter += mergesortavg;
    insertionsortavg = 0;
    insertionsortcounter = 0;
    sortavg = 0;
    sortcounter = 0;
    mergesortavg = 0;
    mergesortcounter = 0;
    
    free(a);
    free(b);
  }

  total_insertion_sort_avg = total_insertion_sort_counter / N;
  total_improved_quicksort_avg = total_improved_quicksort_counter / N;
  total_nonrec_mergesort_avg = total_nonrec_mergesort_counter / N;
  printf("TOTAL AVERAGE OF INSERTION_SORT ALGORITHM IS %lf \n", total_insertion_sort_avg);
  printf("TOTAL AVERAGE OF IMPROVED_QUICKSORT ALGORITHM IS %lf \n", total_improved_quicksort_avg);
  printf("TOTAL AVERAGE OF NONREC_MERGESORT ALGORITHM IS %lf \n", total_nonrec_mergesort_avg);
  

  system("PAUSE");
  return 0;

}

void renewal(item * a, item * b, int n) { //function to renew the array a[]
  int i;

  for (i = 0; i < n; i++) {
    a[i] = b[i]; //renewal of the array a[]
  }

}


void insertionsort2(item * a, int n) {  //insertionsort algorithm
  int i, j;

  for (i = 1; i < n; i++) {
    
    for (j = i; j > 0; j--) {
      compexch(a[j], a[j - 1]); 
    }
  }
}


void insertionsort(item * a, int n) {   //insertionsort algorithm
  int i, j;
  item temp;
  
  for (i = 1; i < n; i++) {
    compexch(a[i], a[0]);
  }
  
  for (i = 2; i < n; i++) {
    j = i;
    temp = a[i];
    
    while (less(temp, a[j - 1])) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = temp;
  }
}

void mergesort(item a[], int l, int r) { //mergesort algorithm
  int i, m;
  for (m = 1; m <= r - l; m = m + m)
    for (i = l; i <= r - m; i += m + m)
      merge(a, i, i + m - 1, min(i + m + m - 1, r));
}

void merge(item a[], int l, int m, int r) { //merge function that helps into mergesort algorithm
  int i, j, k;

  for (i = m + 1; i > l; i--)
    aux[i - 1] = a[i - 1];

  for (j = m; j < r; j++)
    aux[r + m - j] = a[j + 1];

  for (k = l; k <= r; k++)
    if (less(aux[j], aux[i]))
      a[k] = aux[j--];
    else a[k] = aux[i++];
}

void quicksort(item a[], int l, int r) { // quicksort algorithm
  int i;

  if (r - l <= M)
    return;
  /* median-of-three  */
  exch(a[(l + r) / 2], a[r - 1]);
  compexch(a[l], a[r - 1]);
  compexch(a[l], a[r]);
  compexch(a[r - 1], a[r]);

  i = partition(a, l + 1, r - 1);

  quicksort(a, l, i - 1);

  quicksort(a, i + 1, r);
}

int partition(item a[], int l, int r) { //partition function
  int i = l, j = r - 1;
  item v = a[r];
  while (1) {

    while (less(a[i], v)) i++;

    while (less(v, a[j])) {
      j--;
      if (j == l)
        break;
    }

    if (i >= j)
      break;

    exch(a[i], a[j]);

    i++;
    j--;
  }

  exch(a[i], a[r]);
  return i;
}

void sort(item * a, int n) { //improved quicksort algorithm
  quicksort(a, 0, n - 1);
  insertionsort(a, n);
}