#include <iostream>
#include <stdlib.h>  /* rand */
#include <time.h>

using namespace std;

void copy_array(int arr[], int arr1[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = arr1[i];
    }
}

void random_array(int arr[], int size){
    for(int i = 0; i < size; i++){
    arr[i] = rand() % 10000;        
    }
}

void ascending_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = i;
    }
}

void descending_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = size - i;
    }
}

void print_array(int arr[], int size){
	cout << "Array:";
	for(int i=0; i < size; i++){
		cout << arr[i] << " ";
	}
}

void insert_sort(int A[], int n){
    
    for(int i = 0; i < n; i++){
        int cur_value = A[i];
        int j = i -1;
        while(j>= 0 and A[j] > cur_value){
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = cur_value;
    }
}

bool is_sorted(int A[], int n){
    for(int i = 0; i < n - 1 ; i++){
        if (A[i + 1] < A[i]){
            return false;
        }
    }
    return true;
}

void merge(int a[], int st, int  mid, int end){
    int aux1 = mid - st + 1;
    int aux2 = end - mid;
    int * left = new int[aux1];
    int * right = new int[aux2];
    
    for(int i = 0; i < aux1; i++){
        left[i] = a[st + i];
    }
    for (int j = 0; j < aux2; j++){
        right[j] = a[mid + j + 1];
    }
    
    int i = 0;
    int j = 0;
    
    for (int k = st; k < end + 1; k++){
        if((left[i] <= right[j] && i < aux1) || j >= aux2 ){
            a[k] = left[i];
            i = i + 1;
        }
        else{
            a[k] = right[j];
            j = j + 1;
        }
    }
}

void merge_sort(int a[], int st, int end){
    if (st < end){
        int mid = ((st + end)/2);
        merge_sort(a, st, mid);
        merge_sort(a, mid + 1, end);
        merge(a, st, mid, end);
    }
    
}

int main()
{   
    cout << "Results with random arrays:" << endl;
    for (int n = 10000; n < 100001; n += 10000){
        //Create the random arrays
        int a[n];
        random_array(a, n);
        int b[n];
        copy_array(b, a, n);
        
        
        //Call insert_sort and calculate time
        clock_t start_time = clock();
        insert_sort(a, n);
        double t1 =  double (clock () - start_time) / CLOCKS_PER_SEC;
        
        //print_array(a, n);
        
        if (is_sorted(a, n) == false){
            cout << "ERROR!" << endl;
        }
        
        //Call merge_sort and calculate the time
        clock_t start_time2 = clock();
        merge_sort(b, 0, n);
        double t2 =  double (clock () - start_time2) / CLOCKS_PER_SEC;

        if (is_sorted(b, n) == false){
        cout << "ERROR!" << endl;
        }
        
        cout << "(" << n << "," << t1 << "," << t2 << ")" << endl;
    }
    
    cout << "Results with arrays in ascending order:" << endl;
    for (int n = 10000; n < 100001; n += 10000){
        //Create the ascending arrays
        int a[n];
        ascending_array(a, n);
        int b[n];
        copy_array(b, a, n);
        
        //Call insert_sort and calculate time
        clock_t start_time = clock();
        insert_sort(a, n);
        double t1 =  double (clock () - start_time) / CLOCKS_PER_SEC;
        
        if (is_sorted(a, n) == false){
            cout << "ERROR!" << endl;
        }
        
        //Call merge_sort and calculate the time
        clock_t start_time2 = clock();
        merge_sort(b, 0, n);
        double t2 =  double (clock () - start_time2) / CLOCKS_PER_SEC;

        if (is_sorted(b, n) == false){
        cout << "ERROR!" << endl;
        }
        
        cout << "(" << n << "," << t1 << "," << t2 << ")" << endl;
    }
    cout << "Results with arrays in descending order:" << endl;
    for (int n = 10000; n < 100001; n += 10000){
        //Create the descending arrays
        int a[n];
        descending_array(a, n);
        int b[n];
        copy_array(b, a, n);
        
        //Call insert_sort and calculate time
        clock_t start_time = clock();
        insert_sort(a, n);
        double t1 =  double (clock () - start_time) / CLOCKS_PER_SEC;
        
        if (is_sorted(a, n) == false){
            cout << "ERROR!" << endl;
        }
        
        //Call merge_sort and calculate the time
        clock_t start_time2 = clock();
        merge_sort(b, 0, n);
        double t2 =  double (clock () - start_time2) / CLOCKS_PER_SEC;

        if (is_sorted(b, n) == false){
        cout << "ERROR!" << endl;
        }
        
        cout << "(" << n << "," << t1 << "," << t2 << ")" << endl;
    }
    
    int nc = 11;
    int ac[] = {2,1,4,5, 3, 6, 7, 0, 9, 100, 10};
    int b = 0;
    insert_sort(ac,nc);

    print_array(ac, nc);
    
    return 0;
}