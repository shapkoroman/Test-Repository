#include <iostream>
#include <fstream>

using namespace std;

void checkValidInput()
{
	if (cin.fail()) throw "Incorrect input";
}

void checkValidParams(double a, double b, double h, int n)
{
	if (a > b) throw "Input correct data for a, b";
	if (h <= 0) throw "Input correct data for h";
	if (n < 2) throw "Input correct data for n";
}

double calculate(double x, int n)
{
	double totalSum, sum;
	if (x < 0)
	{
		totalSum = 0;
		sum = 0;
		for (int i = 1; i <= (n - 1); i++)
		{
			for (int j = 1; j <= n; j++)
			{
				sum += (x - i + j);
			}
			totalSum += sum;
			sum = 0;
		}
	}
	else
	{
		totalSum = 0;
		for (int i = 1; i <= (n - 1); i++)
		{
			totalSum += (x / i);
		}
	}
	return totalSum;
}

int main()
{
	double a, b, h, x;
	int n;
	string saveToFile;
	try
	{
		cout << "Enter a, b: ";
		cin >> a >> b;
		checkValidInput();

		cout << "Enter h: ";
		cin >> h;
		checkValidInput();

		cout << "Enter n (n >= 2): ";
		cin >> n;
		checkValidInput();

		checkValidParams(a, b, h, n);

		cout << "Do you want save result to file? (yes/no): ";
		cin >> saveToFile;
		checkValidInput();
	}
	catch (const char* ex)
	{
		cout << ex << endl;
		return -1;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
		return -2;
	}

	ofstream fout("result.txt");
	for (x = a; x <= b; x += h)
	{
		if (saveToFile == "yes") fout << "x = " << x << ", y = " << calculate(x, n) << endl;
		cout << "x = " << x << ", y = " << calculate(x, n) << endl;
	}
	return 0;
}