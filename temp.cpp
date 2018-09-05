#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout << "numbers:" ;
	cin >> n;
	if (n <= 0)
		return 0;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "enter" << i+1 << "number:";
		cin >> a[i];
		cout << endl;
	}

	int number = a[0];
	for (int i = 1; i < n; ++i)
	{
		number = __gcd(number, a[i]);
	}
	cout << "result:"<< number << endl; 
}
