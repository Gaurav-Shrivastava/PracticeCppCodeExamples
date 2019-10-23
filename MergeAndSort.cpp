#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> intvec;

// This method returns the merge of two sorted
// arrays, after removing duplicate elements

intvec result_vec;

void MergeAndSort(int arr1[], int arr1_len, int arr2[], int arr2_len)
{
	set<int> intset; //This will hold all the elements in sorted order and doesn't allows duplicates

	for(int i=0; i < arr1_len; i++)
	{
		intset.insert(arr1[i]);
	}
	
	for(int k=0; k < arr2_len; k++)
	{
		intset.insert(arr2[k]);
	}

	for_each(intset.begin(), intset.end(), [](int i)
	{
		result_vec.push_back(i);	
	});

	//for(set<int>::iterator it = intset.begin(); it != intset.end(); it++)
	//{
	//	//cout << *it << endl;
	//	result_vec.push_back(*it);
	//}
}

int main()
{
	int arr1[6] = { 100, 55, 87, 87, 55, 20 };  

	int arr2[8] = { 3, 94, 35, 55, 77, 89, 31, 43 };

	MergeAndSort(arr1, 6, arr2, 8);

	for_each(result_vec.begin(), result_vec.end(), [](int i) 
    { 
        std::cout << i << " "; 
    }); 
    cout << endl;

	//for(intvec::iterator it = result_vec.begin(); it != result_vec.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	return 0;
}
