#include <iostream>

using namespace std;

void camionero(float* distancias, float max, int n) {
    float kilometros = distancias[0];
    for (int i = 1; i <= n; ++i) {
        kilometros += distancias[i];
        if (kilometros > max) {
            cout << i << " ";
            kilometros = distancias[i];
        }
    }
}

int main()
{
    int n;
    float max;
    cout << "Número de gasolineras: ";
    cin >> n;
    cout << "Kilómetros por tanque: ";
    cin >> max;
    float* distancias = new float[n+1];

    for (int i = 0; i <= n; ++i) {
        if (i == 0)
            cout << "Distancia entre origen y gasolinera 1: ";
        else if (i == n)
            cout << "Distancia entre gasolinera " << n << " y destino: ";
        else
            cout << "Distancia entre gasolinera " << i << " y " << i+1 << ": ";
        cin >> distancias[i];
    }

    cout << "Parar en las gasolineras: ";
    camionero(distancias, max, n);
    delete [] distancias;
    return 0;
}
