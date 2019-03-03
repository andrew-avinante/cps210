#include <vector>
using namespace std; 
const int RUN = 32; 

void insertionSort(vector<int> &v, int left, int right) 
{ 
	for (int i = left + 1; i <= right; i++) 
	{ 
		int temp = v[i]; 
		int j = i - 1; 
		while (v[j] > temp && j >= left) 
		{ 
			v[j+1] = v[j]; 
			j--; 
		} 
		v[j+1] = temp; 
	} 
} 

// merge function merges the sorted runs 
void merge(vector<int> &v, int l, int m, int r) 
{ 
	int len1 = m - l + 1, len2 = r - m; 
	int left[len1], right[len2]; 
	for (int i = 0; i < len1; i++) 
		left[i] = v[l + i]; 
	for (int i = 0; i < len2; i++) 
		right[i] = v[m + 1 + i]; 
	int i = 0; 
	int j = 0; 
	int k = l; 
	while (i < len1 && j < len2) 
	{ 
		if (left[i] <= right[j]) 
		{ 
			v[k] = left[i]; 
			i++; 
		} 
		else
		{ 
			v[k] = right[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < len1) 
	{ 
		v[k] = left[i]; 
		k++; 
		i++; 
	} 
	while (j < len2) 
	{ 
		v[k] = right[j]; 
		k++; 
		j++; 
	} 
} 
void timSort(vector<int> &v, int n) 
{ 
	for (int i = 0; i < n; i+=RUN) 
		insertionSort(v, i, min((i+31), (n-1))); 
	for (int size = RUN; size < n; size = 2*size) 
	{ 

		for (int left = 0; left < n; left += 2*size) 
		{ 

			int mid = left + size - 1; 
			int right = min((left + 2*size - 1), (n-1)); 

			merge(v, left, mid, right); 
		} 
	} 
}

void printArray(vector<int> &j) 
{ 
    for (auto i : j) 
        printf("%d  ", i); 
    printf("\n"); 
} 