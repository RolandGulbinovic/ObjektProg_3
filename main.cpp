#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::cin;

struct studentas{
	string Vardas;
	string Pav;
	int nd[10];
	int egz;
	int sk;
	float GP=0;
};

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
double findMedian(int a[], int n);

int main()
{
	studentas Eil; studentas Eil_mas[5];
	int n;
	int sk;
	cout << "Iveskite studenta varda ir pavarde, namu darbu ir egzamino rezultatus" << endl;
	cin >> Eil.Vardas >> Eil.Pav;
	cout << "Iveskite namu darbu skaiciu" << endl;
	cin >> n;
	for (int i = 0; i < n ; i++)
	{
		cin >> Eil.nd[i];
		Eil.GP = Eil.nd[i]+Eil.GP;
	}
	cout << "Iveskite egzamino rez." << endl;
	cin >> Eil.egz;

	cout << "norite medianas(1) ar GP(2)" << endl;
	cin >> sk;
	if (sk == 2)
	{
		Eil.GP = Eil.GP / (float)n;
		Eil.GP = 0.4 * Eil.GP + 0.6 * Eil.egz;
		
		cout << Eil.Vardas << " " << Eil.Pav << " "; //Isvedimas
		printf("%.2f", Eil.GP); //GP skaiciavumas
	}
	else {
		Eil.nd[n] = Eil.egz;
		
		insertionSort(Eil.nd , n+1);
		cout << Eil.Vardas << " " << Eil.Pav <<" "<< findMedian(Eil.nd, n + 1) <<endl;

	}
	
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n  
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
double findMedian(int a[], int n)
{
	if (n % 2 != 0)
		return (double)a[n / 2];

	return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}
