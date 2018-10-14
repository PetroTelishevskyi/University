#include <iostream>
#include <fstream>>

using namespace std;

double **Rotations(long double** A, long double* X, long int n) {
	long double c, s, a1;
	long double det = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			c = A[i][i] / (sqrt((A[i][i] * A[i][i]) + (A[j][i] * A[j][i])));
			s = A[j][i] / (sqrt((A[i][i] * A[i][i]) + (A[j][i] * A[j][i])));
			for (int k = 0; k < n + 1; k++) {
				a1 = A[i][k];
				A[i][k] = c * a1 + s * A[j][k];
				A[j][k] = -s * a1 + c * A[j][k];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				det *= A[i][j];
			}
		}
	}
	ofstream out;
	out.open("answer.txt");
	out << "det = " << det;
	out << "\n";
	X[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
	for (int k = n - 2; k >= 0; k--){
		long double sum = 0;
		for (int j = n - 1; j > k; j--)
			sum += A[k][j] * X[j];
		X[k] = (A[k][n] - sum) / A[k][k];
	}
	for (int q = 0; q < n; q++) {
		out << "x" << q + 1 << "=" << X[q] << endl;
	}
	out.close();
	return 0;
}
int main() {
	int n;
	ifstream file;
	file.open("A.txt");
	file >> n;
	 long double **A = new long double*[n];
	 long double *X = new long double[n];

	for (int i = 0; i < n; i++) {
		A[i] = new long double[n + 1];
		for (int j = 0; j < n + 1; j++) {
			file >> A[i][j];
		}
	}
	file.close();
	Rotations(A, X, n);
	system("pause");
	return 0;
}