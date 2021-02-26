#include <bits/stdc++.h> 

using namespace std; 
struct Item 
{ 
	public:
    int value, weight; 
	Item(int value, int weight): value(value),weight(weight){}
}; 

// comparator used to sort Item according to val/weight ratio 
bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.value / (double)a.weight; 
	double r2 = (double)b.value / (double)b.weight; 
	return r1 > r2; 
} 

void fractionalKnapsack(int W, Item arr[], int n) 
{ 
	cout << "\nWeight Limit: " << W << endl << endl;
    // sorting Item on basis of ratio 
	sort(arr, arr + n, cmp); 
    
    // Printing items added to knapsack along with their weights 
	for (int i = 0; i < n; i++) 
	{ 
		cout << "Item " << i+1 <<"\tValue: " << arr[i].value << "\tWeight: " << arr[i].weight << "\tQuantity: "\
         << ((double)arr[i].value / arr[i].weight) << endl; 
	} 

	int curWeight = 0;              // Current weight in knapsack 
	double finalvalue = 0.0;        // Result (value in Knapsack) 

	// Looping through all Items 
	for (int i = 0; i < n; i++) 
	{ 
		// If adding Item won't overflow, add it completely 
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].value; 
		} 

		// If we can't add current Item, add fractional part of it 
		else
		{ 
			int remain = W - curWeight; 
			finalvalue 
				+= arr[i].value 
				* ((double)remain / (double)arr[i].weight); 
			break; 
		} 
	} 
    cout << "\nMaximum Value that can be obtained for weight " << W << " is " << finalvalue << endl;
} 

int main() 
{ 
	int W = 10; // Weight of knapsack 
	Item arr[] = { { 10,2 }, { 5,3 }, { 15,5 }, { 7,7} ,{6,1},{18,4},{3,1}}; 

	int n = sizeof(arr) / sizeof(arr[0]);
	cout <<"\n\tKnapsack Problem Implementation\n\n";
	cout <<"\t\t(Divisible Objects)\n\n"; 
    fractionalKnapsack(W, arr, n); 
	return 0; 
}
