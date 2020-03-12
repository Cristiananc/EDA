#include <iostream>
#include <stdlib.h>  /* rand */
#include <time.h>

using namespace std;

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
    for(int i = 0; i < n ; i++){
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
    print_array(left, aux1);
    print_array(right, aux2);
    int i = 0;
    int j = 0;
    
    //cout << end << endl;
    for (int k = st; k < end + 1; k++){
        if((left[i] <= right[j] && i < aux1) || j >= aux2 ){
            cout << "left: " <<  left[i] << endl;
            a[k] = left[i];
            i = i + 1;
        }
        else{
            a[k] = right[j];
            cout << "right :" << right[i] << endl;
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
    //Create the random lists
    int a[] = {2,3,4,8,1};
    int n = 5;
    
    for (int ns = 10000; ns < 100001; ns += 10000){
        
        //Call insert_sort and calculate time
        //insert_sort(a, n);

        if (is_sorted(a, n) == false){
            cout << "ERROR!" << endl;
        }
        
        //Call merge_sort and calculate the time
        merge_sort(a, 0, n - 1);
        cout << a[0] << a[2] << endl;
        
        if (is_sorted(a, n) == false){
        cout << "ERROR!" << endl;
        }
    }
    
    int ab = 2.5; 

    int nc = 4;
    int ac[] = {2,1,4,5};
    int b = 0;
    merge_sort(ac, b, n - 1);

    print_array(ac, nc);
    return 0;
}
