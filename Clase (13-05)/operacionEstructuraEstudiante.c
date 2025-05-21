// Ejercicio Estructuras 
// Crea una estructura llamada Estudiante con los miembros: nombre, edad y legajo. Declara e inicializa dos estudiantes y muestra su información por pantalla. 

#include <stdio.h> 
#include <string.h>

// Incluyo a biblioteca "stdio.h" para poder utilizar printf e imprimir datos en pantalla
// Incluyo la bibliteca "string.h" para poder realizar cadenas de caracteres (que no estan incluidas por defecto en C)

struct Estudiante
{
    char nombre[30];
    int edad;
    int legajo;
};

// Generamos una Estructura con el nombre Estudiante y le asignamos 3 tipos de datos en relacion al enunciado

int main() // Iniciamos la funcion Main para dar punto de inicio a nuestro codigo
{
    struct Estudiante a1 = {"Valentino", 20, 46186090};
    struct Estudiante a2 = {"Juan", 27, 37123876};

    // Convocamos a la estructura previamente generada y le asignamos los valores a cada tipo de dato segun corresponda

    printf("Estudiante N1: \n Nombre: %s\n Edad: %d\n Legajo: %d\n",a1.nombre, a1.edad, a1.legajo);

    printf("Estudiante N2: \n Nombre: %s\n Edad: %d\n Legajo: %d\n", a2.nombre, a2.edad, a2.legajo);

    // Utilizamos printf para mostrar en pantalla la informacion añadida a la estructura generada

    return 0;

    // return 0 par corroborar que nuestro codigo se ejecuto sin errores
}

