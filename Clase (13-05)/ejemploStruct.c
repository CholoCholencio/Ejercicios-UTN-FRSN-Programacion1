#include <stdio.h>
#include <string.h>

struct Alumno
{
    char nombre[50];
    int edad;
    int legajo;
};

int sonIguales(struct Alumno al1, struct Alumno al2)
{
    return (al1.edad == al2.edad && al1.legajo == al2.legajo && strcmp(al1.nombre, al2.nombre) == 0);
}

void cumplirAnios(struct Alumno *a)
{
    a->edad += 1;
}

int main()
{

    struct Alumno a1;
    struct Alumno a2 = {"Matias", 24, 654321};
    strcpy(a1.nombre, "Guido");
    a1.edad = 24;
    a1.legajo = 123456;

    printf("Nombre: %s\n", a1.nombre);
    printf("Edad: %d\n", a1.edad);
    printf("Legajo: %d\n", a1.legajo);

    cumplirAnios(&a1);

    printf("Nombre: %s\n", a1.nombre);
    printf("Edad: %d\n", a1.edad);
    printf("Legajo: %d\n", a1.legajo);

    if (sonIguales(a1, a2))
    {
        printf("Son iguales!!!");
    }
    else
    {
        printf("Son diferentes!!");
    }

    return 0;
}