#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;

int menu(int *ptrchoisemenu)
{
	cout << "MENU" << endl;
	cout << "1. Show any array" << endl;
	cout << "2. Rand array" << endl;
	cout << "3. Change array" << endl;
	cout << "4. Revers array" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
	cout << "Enter action : ";
	cin >> *ptrchoisemenu;
	return *ptrchoisemenu;
}
template <typename myType>
void showArray(myType array[], const int *ptrsize)
{

	for (int i = 0; i < *ptrsize; i++)
	{
		cout << array[i] << endl;
	}
}
void randArray(int array[], const int *ptrsize)
{
	for (int i = 0; i < *ptrsize; i++)
	{
		array[i] = rand () % 50 + 1;
		cout << array[i] << endl;
	}
}
void changeArray(int array[], const int* ptrsize)
{
	for (int i = 0; i < *ptrsize; i++)
	{
		cout << "Enter " << i + 1 << " element: ";
		cin >> array[i];
	}
	cout << "Previous array" << endl;
	for (int i = 0; i < *ptrsize; i++)
	{
		cout << array[i] << endl;
	}
	cout << endl;
	cout << "New array" << endl;
	for (int i = 0; i < *ptrsize; i++)
	{
		if (array[i] < 0)
		{
			array[i] = 0;
		}
		cout << array[i] << endl;
	}
}
int reversArray(int array[], const int* ptrsize)
{
	for (int i = 0; i < *ptrsize; i++)
	{
		cout << "Enter " << i + 1 << " element: ";
		cin >> array[i];
	}
	int temp;
	for (int i = 0; i < *ptrsize / 2; i++)
	{
		temp = array[i];
		array[i] = array[*ptrsize - i - 1];
		array[*ptrsize - i - 1] = temp;
	}
	for (int i = 0; i < *ptrsize; i++)
	{
		cout << array[i] << endl;
	}
	return array[*ptrsize];
}
int main()
{
	const int size = 5;
	const int* ptrsize = &size;
	string array1[size];
	float array2[size];
	int array3[size];
	int choiseArray;
	int randarray[size];
	int changearray[size];
	int reversarray[size];

	int choiseMenu; 
	int* ptrchoisemenu = &choiseMenu;
	do
	{
		choiseMenu = menu(&choiseMenu);
		switch (choiseMenu)
		{
			case 1:

					cout << "1. Int" << endl;
					cout << "2. Float" << endl;
					cout << "3. String" << endl;
					cout << "Enter type of array to show: ";
					cin >> choiseArray;
					switch (choiseArray)
					{
					case 1:
						for (int i = 0; i < size; i++)
						{
							cout << "Enter " << i + 1 << " element: ";
							cin >> array3[i];
						}
						showArray(array3, &size);
						break;
					case 2:
						for (int i = 0; i < size; i++)
						{
							cout << "Enter " << i + 1 << " element: ";
							cin >> array2[i];
						}
						showArray(array2, &size);
						break;
					case 3:
						for (int i = 0; i < size; i++)
						{
							cout << "Enter " << i + 1 << " element: ";
							cin >> array1[i];
						}
						showArray(array1, &size);
						break;
					default:
						break;
					}
				break;
			case 2:
				randArray(randarray, &size);
				break;
			case 3:
				changeArray(changearray, &size);
				break;
			case 4: 
				reversarray[size] = reversArray(reversarray, &size);
					break;
			case 5:
				cout << "Goodbye!" << endl;
				break;
		}
	} while (choiseMenu != 5);

	return 0;
}