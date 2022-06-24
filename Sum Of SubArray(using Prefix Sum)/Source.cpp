#include <iostream>
using namespace std;



int PrintSum(int arr[], int n) {
	int sum, largest = arr[0];
	int prefix[100];
	prefix[0] = arr[0];
	
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i-1] + arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == 0)
				sum = prefix[j];
			else
				sum = prefix[j] - prefix[i - 1];
			cout << sum << " ";
			if (sum > largest)
				largest = sum;
		}
		cout << endl;
	}
	return largest;
}

int main() {
	int arr[] = { -2,3,4,-1,5,-12,6,1,3 };
	int n = sizeof(arr) / sizeof(int);
	int largest = PrintSum(arr, n);
	cout << "the Max Sum of Subarray is " << largest << endl;

}