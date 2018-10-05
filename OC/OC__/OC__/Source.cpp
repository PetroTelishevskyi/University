
#include <iostream>
#include <cmath>

using namespace std;
long double fact(int N)
{
	if (N < 0) 
		return 0; 
	if (N == 0) 
		return 1; 
	else 
		return N * fact(N - 1);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double x = -1;
	while (x <= 1)
	{
		double epsilon = 0.0001;
		double s = 0;
		double an;
		int n;
		n = 1; 
		an = 1;
		while (abs(an) > epsilon)
			
		{
			s += an; 
			n++; 
			an *=( (pow(-1,n)*(fact(2*n))/((1-2*n)*pow(fact(n),2)*pow(4,n))*pow(x, (n)))); 
		}
		cout << "При x = " << x << " Cума:" << s << endl; 
		x += 0.2;
		
	}
	cin.get(); cin.get();
	return 0;
}