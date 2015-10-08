#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float cost(string* palabras, int sum, int tam, float l, float b, bool lastLine) {
    float b2 = l - sum;
    if (tam == 0) {
        if (lastLine)
            return 0;
        return b2;
    }
    else {
        if (b2 < 0)
            return -1;
        b2 /= tam;
        if (lastLine && b2 > b)
            return 0;
        return tam * abs(b2 - b);
    }
}

int* justificar(string* palabras, int n, float l, float b) {
    float min[n+1];
    int* parent = new int[n];
    min[n] = 0;
    for (int i = n-1; i >= 0; --i) {
        int sum = 0;
        for (int j = i+1, tam = 0; j <= n; ++j, ++tam) {
            sum += palabras[j-1].length();
            bool lastLine = (j == n);
            float costo = cost(palabras, sum, tam, l, b, lastLine);
            if (costo == -1)
                continue;
            costo += min[j];
            if (j == i+1 || costo < min[i]) {
                min[i] = costo;
                parent[i] = j;
            }
        }
    }
    return parent;
}

int main()
{
    int n;
    float l,b;
    cout << "Introduce el número de palabras: ";
    cin >> n;
    cout << "Introduce el tamaño de línea: ";
    cin >> l;
    cout << "Introduce el tamaño de los espacios: ";
    cin >> b;
    string* palabras = new string[n];
    cout << "Introduce " << n << " palabras separadas por espacios: ";
    for (int i = 0; i < n; ++i)
        cin >> palabras[i];

    int* parent = justificar(palabras, n, l, b);
    int i = 0, j = 0, k = 1;
    do {
        i = parent[i];
        cout << "Fila " << k++ << ": ";
        while (i != j)
            cout << palabras[j++] << " ";
        cout << endl;
    } while (i != n);

    delete [] palabras;
    delete [] parent;
    return 0;
}
