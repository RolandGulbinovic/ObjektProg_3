#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;

struct studentas{
	string Vardas[10];
	string Pav[10];
	int nd[10][15];
	int egz[10];
	int sk[10];
	float GP[10];
};

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
double findMedian(int a[], int n);

int main()
{
	studentas Eil; studentas Eil_mas[5];
	vector<studentas> Eiles;

	for (int i = 0; i < 10; i++) Eil.GP[i] = 0;

	int n;
	int sk;
	int l;
	cout << "Iveskite studentu skaiciu" << endl;
	cin >> l;
	for (int i = 0; i < l; i++) {

		cout << "Iveskite studenta varda ir pavarde" << endl;
		cin >> Eil.Vardas[i] >> Eil.Pav[i];
		cout << "Iveskite namu darbu skaiciu" << endl;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> Eil.nd[i][j];
			Eil.GP[i] = Eil.nd[i][j] + Eil.GP[i];
		}
		cout << "Iveskite egzamino rez." << endl;
		cin >> Eil.egz[i];

		cout << "norite medianas(1) ar GP(2)" << endl;
		cin >> sk;
		if (sk == 2)
		{
			Eil.GP[i] = Eil.GP[i] / (float)n;
			Eil.GP[i] = 0.4 * Eil.GP[i] + 0.6 * (float)Eil.egz[i]; //GP skaiciavumas
		}
		else {
			/*Eil.nd[n] = Eil.egz;

			insertionSort(Eil.nd , n+1);
			cout << Eil.Vardas << " " << Eil.Pav <<" "<< findMedian(Eil.nd, n + 1) <<endl;
			*/
		}
	}
	for (int i = 0; i < l; i++) {
		cout << Eil.Vardas[i] << " " << Eil.Pav[i] << " "; //Isvedimas
		printf("%.2f", Eil.GP[i]);
		cout << endl;
	}
}

/* Function to sort an array using insertion sort*/
/*void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position 
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
}*/
