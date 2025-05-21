// Define una estructura llamada Circulo para representar un círculo con un único miembro: 
// radio. Escribe un programa en C para calcular el área y el perímetro de dos círculos y mostrar los resultados.

#include <stdio.h>

#define PI 3.1416 // Utilizo #Define para darle un valor fijo a PI

typedef struct {
    float radio;
} Circulo;

// Genero y Defino una estructura bajo e nombre de "Circulo" y le agrego un dato de tio flotante con el valor de su radio

float calcularArea (Circulo c){
return PI * (c.radio * c.radio);
}
// Genero una Función para realizar el calculo con el que obtengo el valor del area del circulo, tambien en variable float

float calcularPerimetro (Circulo c){
    return 2 * PI * c.radio;
}

// Genero otra Función para realizar el calculo necesario para obtener el valor del perimetro de nuestro circulo, utilizando tambien una variable float

int main() {

    Circulo c1, c2;

    printf("Ingrese el Radio del Primer Circulo: ");
    scanf("%f", &c1.radio);

    printf("Ingrese el Radio del Segundo Circulo: ");
    scanf("%f", &c2.radio);

// Pedimos al Usuario que Ingrese los datos requeridos (Radio de ambos circulos) para poder proseguir con la operación

    float area1 = calcularArea(c1);
    float perimetro1 = calcularPerimetro(c1);

    float area2 = calcularArea(c2);
    float perimetro2 = calcularPerimetro(c2);

// Generamos dos variables flotantes y le asignamos como valor e resultado de las funciones que hicimos previamente, operando con los circulos correspondientes

printf("Circulo 1:\n");
printf("Area: %.2f\n", area1);
printf("Perimetro: %.2f\n", perimetro1);

printf("Circulo 2:\n");
printf("Area: %.2f\n", area2);
printf("Perimetro: %.2f\n", perimetro2);

    return 0;
}

