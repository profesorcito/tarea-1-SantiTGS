#include <iostream>

using namespace std;

// Función para calcular la suma de los dígitos de un número
int sumaDigitos(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10; // Extrae el último dígito y lo suma
        n /= 10;        // Elimina el último dígito
    }
    return suma;
}

// Función para calcular la tarifa de estacionamiento
double calcularTarifa(int horas, int dia) {
    // Definimos las constantes según las reglas
    const double TARIFA_PRIMERA_HORA = 6.00;
    const double TARIFA_1_A_3 = 4.00;
    const double TARIFA_3_A_5 = 3.00;
    const double TARIFA_FIJA = 22.00;
    const int LIMITE_HORAS = 24;
    const double INCREMENTO_FIN_SEMANA = 1.15;
    const double DESCUENTO_DIGITOS = 0.95;

    // Verificamos si las horas superan el límite permitido
    if (horas > LIMITE_HORAS) {
        return -1; // Código de error
    }

    double totalPagar = 0.0;

    // Aplicamos la tarifa base según el rango de horas
    if (horas == 1) {
        totalPagar = TARIFA_PRIMERA_HORA; // Primera hora fija
    } else if (horas > 1 && horas <= 3) {
        totalPagar = TARIFA_PRIMERA_HORA + (horas - 1) * TARIFA_1_A_3; // Primera hora + adicionales
    } else if (horas > 3 && horas <= 5) {
        totalPagar = TARIFA_PRIMERA_HORA + (2 * TARIFA_1_A_3) + (horas - 3) * TARIFA_3_A_5; // Primeras 3 horas + siguientes
    } else {
        totalPagar = TARIFA_FIJA; // Más de 5 horas, tarifa fija
    }

    // Aplicamos incremento del 15% si es fin de semana (sábado o domingo)
    if (dia == 6 || dia == 7) {
        totalPagar *= INCREMENTO_FIN_SEMANA;
    }

    // Aplicamos descuento si la suma de los dígitos de las horas es múltiplo de 3
    if (sumaDigitos(horas) % 3 == 0) {
        totalPagar *= DESCUENTO_DIGITOS;
    }

    return totalPagar;
}

int main() {
    int horas, dia;

    // Leer los valores de entrada
    cin >> horas >> dia;

    // Calculamos la tarifa
    double resultado = calcularTarifa(horas, dia);

    // Mostramos el resultado con dos decimales o "ERROR" si excede el límite
    if (resultado == -1) {
        cout << "ERROR" << endl;
    } else {
        printf("%.2f\n", resultado);
    }

    return 0;
}
