#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

list<char> subsecuencia(char* x, char* y, int n, int m) {
    int tabla[n+1][m+1];
	for (int i = 0; i <= n; ++i)
		tabla[i][0] = 0;
	for (int i = 0; i <= m; ++i)
		tabla[0][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (x[i-1] == y[j-1])
				tabla[i][j] = tabla[i-1][j-1] + 1;
			else
				tabla[i][j] = max(tabla[i-1][j], tabla[i][j-1]);
        }
    }

    // Obtener elementos
    list<char> secuencia;
    for (int i = n, j = m, k = tabla[n][m]; k > 0; --i, --j, --k) {
        while (j > 0 && tabla[i][j-1] == tabla[i][j])
            j--;
        while (i > 0 && tabla[i-1][j] == tabla[i][j])
            i--;
        if (i != 0)
            secuencia.push_front(x[i-1]);
    }
    return secuencia;
}

int main()
{
    int n, m;
    cout << "N: ";
    cin >> n;
    char* x = new char[n];
    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i+1 << ": ";
        cin >> x[i];
    }
    cout << "M: ";
    cin >> m;
    char* y = new char[m];
    for (int i = 0; i < m; ++i) {
        cout << "Elemento " << i+1 << ": ";
        cin >> y[i];
    }

    list<char> secuencia = subsecuencia(x, y, n, m);
    if (secuencia.empty())
        cout << "No hay una subsecuencia común";
    else
        cout << "Subsecuencia común máxima: ";
    for (list<char>::iterator it = secuencia.begin(); it != secuencia.end(); ++it)
        cout << *it << " ";

    delete [] x;
    delete [] y;
    return 0;
}
