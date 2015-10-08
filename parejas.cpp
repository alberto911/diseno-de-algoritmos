#include <iostream>
#include <vector>

#define N 3

using namespace std;

bool valid(int hombre, int mujer, const int (&h)[N][N], const int (&m)[N][N], int n, vector<int> parejasH, vector<int> parejasM) {
    for (int i = 0; m[hombre][i] != mujer; ++i) {
        int indiceMujer = m[hombre][i];
        for (int j = n-1; h[indiceMujer][j] != hombre; --j) {
            if (parejasH.size() > indiceMujer && h[indiceMujer][j] == parejasH[indiceMujer])
                return false;
        }
    }
    for (int i = 0; h[mujer][i] != hombre; ++i) {
        int indiceHombre = h[mujer][i];
        for (int j = n-1; m[indiceHombre][j] != mujer; --j) {
            if (m[indiceHombre][j] == parejasM[indiceHombre])
                return false;
        }
    }
    return true;
}

vector<int> parejasEstables(const int (&h)[N][N], const int (&m)[N][N], int n, vector<int> parejasH, vector<int> parejasM, vector<int> remaining, int pos) {
    if (pos == n)
        return parejasH;
    for (int i = 0; i < remaining.size(); ++i) {
        int hombre = remaining[i];
        if (valid(hombre, pos, h, m, n, parejasH, parejasM)) {
            parejasM[hombre] = pos;
            parejasH[pos] = hombre;
            remaining.erase(remaining.begin()+i);
            vector <int> sol = parejasEstables(h, m, n, parejasH, parejasM, remaining, pos+1);
            if (!sol.empty())
                return sol;
            parejasM[hombre] = -1;
            remaining.insert(remaining.begin()+i, hombre);
        }
    }
    vector<int> e;
    return e;
}

int main()
{
    int h[N][N];
    int m[N][N];
    cout << "Introduce " << N << " números entre 0 y " << N-1 << " separados por espacios\n";
    for (int i = 0; i < N; ++i) {
        cout << "Preferencias de la mujer " << i << ": ";
        for (int j = 0; j < N; ++j)
            cin >> h[i][j];
    }
    for (int i = 0; i < N; ++i) {
        cout << "Preferencias del hombre " << i << ": ";
        for (int j = 0; j < N; ++j)
            cin >> m[i][j];
    }

    vector<int> parejasH (N), parejasM (N);
    vector<int> remaining;
    for (int i = 0; i < N; ++i) {
        parejasM[i] = -1;
        remaining.push_back(i);
    }

    vector<int> sol = parejasEstables(h, m, N, parejasH, parejasM, remaining, 0);

    if (sol.empty())
        cout << "No hay un emparejamiento ideal" << endl;
    else {
        cout << "Emparejamiento:\n";
        for (unsigned int i = 0; i < sol.size(); ++i)
            cout << "Mujer " << i << " con hombre " << sol[i] << endl;
    }
    return 0;
}
