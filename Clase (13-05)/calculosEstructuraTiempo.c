// Define una estructura llamada Tiempo con los miembros: horas, minutos y segundos. 
// Escribe un programa en C que permita ingresar dos tiempos, los sume y muestre el resultado en formato de hora correcta

#include <stdio.h>

typedef struct{
    int horas;
    int minutos;
    int segundos;
}Tiempo;

// Genero y Defino una estructura con el nombre Tiempo y le agrego los datos "horas", "minutos" y "segundos" con su respectivo tipo de dato

Tiempo sumarTiempos(Tiempo t1, Tiempo t2){
    Tiempo resultado;

    int totalSegundos = (t1.horas * 3600 + t1.minutos *60 + t1.segundos) + (t2.horas * 3600 + t2.minutos * 60 + t2.segundos);

    resultado.horas = (totalSegundos / 3600) % 24;
    resultado.minutos = (totalSegundos / 60) % 60;
    resultado.segundos = totalSegundos % 60; 

    return resultado;
}

// Función para sumar ambos tiempos tomando como referencia el valor total de cada uno en segundos, luego normalizando con el operador "%"

void mostrarTiempo(Tiempo t){
    printf("%02d:%02d:%02d\n", t.horas, t.minutos, t.segundos);
}

// Función Void para mostrar el total de ambos tiempos en pantalla 

int main(){

    Tiempo t1, t2, resultado;

    printf("Ingrese las Horas del Primer Tiempo: \n");
    scanf("%d", &t1.horas);
    printf("Ingrese los Minutos del Primer tiempo: \n");
    scanf("%d", &t1.minutos);
    printf("Ingrese los Segundos del Primer Tiempo: \n");
    scanf("%d", &t1.segundos);

    // Pedimos al usuario que ingrese los datos de nuestro Primer Tiempo en Horas/Minutos/Segundos y le asignamos el valor de memoria de la variable

    printf("Ingrese las Horas del Segundo Tiempo: \n");
    scanf("%d", &t2.horas);
    printf("Ingrese los Minutos del Segundo tiempo: \n");
    scanf("%d", &t2.minutos);
    printf("Ingrese los Segundos del Segundo Tiempo: \n");
    scanf("%d", &t2.segundos);

    // Pedimos al usuario que ingrese los datos de nuestro Segundo Tiempo, tambien en Horas/Minutos/Segundos y le asignamos el valor de memoria de la variable

    resultado = sumarTiempos(t1,t2);

    // Llamamos a la función previamente creada para sumar ambos tiempos y le asignamos los datos con los que va a operar

    printf("El resultado de la Suma de Ambos Tiempos es: ");
    mostrarTiempo(resultado);

    // Imprimimos en Pantala el resultado de nuestra operacion y llamamos a la funcion void que hicimos para mostrar el tiempo de manera ordenada asignandole los datos a mostrar

    return 0;
}