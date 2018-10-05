#include <iostream>
#include <cmath>
#include <fstream>
#define eps 1e-4
using namespace std;
double **Gaussa(double **A,  int n) {
	double max;
	int k = 0;
	int index;
	double temp;
	double m;
	int p;
	p = 0;
	double *X = new double[n];
	while (k < n - 1) {
		max = abs(A[k][k]);
		for (int i = k; i < n; i++) {
			if (abs(A[i][k]) > max) {
				max = abs(A[i][k]);
				index = i;
				p++;
			}
		}
		if (max <= eps) {
			ofstream in;
			in.open("answer.txt");
		    in << "There is no unequivocal solution, because det = 0";
		    cout << "There is no unequivocal solution, beccuase det  = 0" << "\n";
	
			return 0;
		}
		if (max != abs(A[k][k])) {
			for (int j = 0; j < n + 1; j++) {
				temp = A[k][j];
				A[k][j] = A[index][j];
				A[index][j] = temp;
			}
		}
		for (int i = k + 1; i < n; i++) {
			m = A[i][k] / A[k][k];
			for (int j = k; j < n + 1; j++) {
				A[i][j] = A[i][j] - (m * A[k][j]);
			}
		}
		k++;

	}
	double det = 1;
	for (int i = 0; i < n; i++) {
		det *= A[i][i];
	}
	if (det == 0) {
		cout << "There is no unequivocal solution, because det = 0" << "\n";
		ofstream in;
		in.open("answer.txt");
		in << "There is no unequivocal solution, because det = 0";
		return 0;
	}
	det = pow(-1, p)*det;
	ofstream out;
	out.open("answer.txt");
	out << "det = " << det << endl;
	X[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
	for (int k = n - 2; k >= 0; k--)
	{
		double sum = 0;
		for (int j = n - 1; j > k; j--)
			sum += A[k][j] * X[j];
		X[k] = (A[k][n] - sum) / A[k][k];
	}
	for (int i = 0; i < n; i++) {
		out << "x" << i + 1 << "=" << X[i] << endl;
	}
	out.close();
}
int main() {
	int n, size;
	ifstream file;
	file.open("A.txt");
	file >> n;
	double **A = new double*[n];


	for (int i = 0; i < n; i++) {
		A[i] = new double[n + 1];
		for (int j = 0; j < n + 1; j++) {
			file >> A[i][j];
		}
	}
	file.close();

	Gaussa(A, n);
	system("pause");
	return 0;
}