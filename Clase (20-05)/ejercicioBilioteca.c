#include <stdio.h>
#include <string.h>

// ======= STRUCT ========
typedef struct {
    char titulo[100];
    char isbn[20];
    char autor[50];
    char editorial[50];
    int prestado;
} Libro;

// ======= PROTOTIPOS ========
void mostrarMenu();
void inicializarBiblioteca(Libro biblioteca[], int *cantidadLibros);
void crearLibro(Libro biblioteca[], int *cantidadLibros);
void listarLibros(Libro biblioteca[], int cantidadLibros);
void prestarLibro(Libro biblioteca[], int cantidadLibros);
void modificarLibro(Libro biblioteca[], int cantidadLibros);
void ordenarBibliotecaPorISBN(Libro biblioteca[], int cantidadLibros);
int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, char isbn[]);

// ======= MAIN ========
int main() {
    Libro biblioteca[100];
    int cantidadLibros = 0;
    int opcion;

    inicializarBiblioteca(biblioteca, &cantidadLibros);

    do {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch (opcion) {
            case 1:
                crearLibro(biblioteca, &cantidadLibros);
                break;

            case 2:
                listarLibros(biblioteca, cantidadLibros);
                break;

            case 3:
                prestarLibro(biblioteca, cantidadLibros);
                break;

            case 4:
                modificarLibro(biblioteca, cantidadLibros);
                break;

            case 5: {
                char isbn[20];
                printf("Ingrese el ISBN del libro: ");
                scanf("%s", isbn);

                ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
                int indice = buscarLibroBinario(biblioteca, cantidadLibros, isbn);

                if (indice != -1) {
                    printf("Libro encontrado!\n");
                    printf("Titulo: %s", biblioteca[indice].titulo);
                    printf("Autor: %s", biblioteca[indice].autor);
                    printf("Editorial: %s", biblioteca[indice].editorial);
                    printf("ISBN: %s\n", biblioteca[indice].isbn);
                    printf("Prestado: %s\n", biblioteca[indice].prestado ? "Sí" : "No");
                } else {
                    printf("Libro no encontrado.\n");
                }
                break;
            }

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}

// ======= FUNCIONES ========
void mostrarMenu() {
    printf("\n===== SISTEMA DE BIBLIOTECA =====\n");
    printf("1. Crear un libro\n");
    printf("2. Listar todos los libros\n");
    printf("3. Prestar un libro\n");
    printf("4. Modificar un libro\n");
    printf("5. Buscar un libro por ISBN\n");
    printf("6. Salir\n");
}

void inicializarBiblioteca(Libro biblioteca[], int *cantidadLibros) {
    strcpy(biblioteca[0].titulo, "Don Quijote de la Mancha\n");
    strcpy(biblioteca[0].isbn, "1234");
    strcpy(biblioteca[0].autor, "Miguel de Cervantes\n");
    strcpy(biblioteca[0].editorial, "Planeta\n");
    biblioteca[0].prestado = 0;

    strcpy(biblioteca[1].titulo, "Cien anos de soledad\n");
    strcpy(biblioteca[1].isbn, "2345");
    strcpy(biblioteca[1].autor, "Gabriel Garcia Marquez\n");
    strcpy(biblioteca[1].editorial, "Planeta\n");
    biblioteca[1].prestado = 0;

    strcpy(biblioteca[2].titulo, "El principito\n");
    strcpy(biblioteca[2].isbn, "3456");
    strcpy(biblioteca[2].autor, "Antoine de Saint-Exupéry\n");
    strcpy(biblioteca[2].editorial, "Salamandra\n");
    biblioteca[2].prestado = 0;

    *cantidadLibros = 3;
}

void crearLibro(Libro biblioteca[], int *cantidadLibros) {
    if (*cantidadLibros >= 100) {
        printf("La biblioteca esta llena.\n");
        return;
    }

    printf("Ingrese el titulo: ");
    fgets(biblioteca[*cantidadLibros].titulo, 100, stdin);

    printf("Ingrese el ISBN: ");
    fgets(biblioteca[*cantidadLibros].isbn, 20, stdin);
    biblioteca[*cantidadLibros].isbn[strcspn(biblioteca[*cantidadLibros].isbn, "\n")] = 0;

    printf("Ingrese el autor: ");
    fgets(biblioteca[*cantidadLibros].autor, 50, stdin);

    printf("Ingrese la editorial: ");
    fgets(biblioteca[*cantidadLibros].editorial, 50, stdin);

    biblioteca[*cantidadLibros].prestado = 0;
    (*cantidadLibros)++;

    printf("Libro agregado con exito.\n");
}

void listarLibros(Libro biblioteca[], int cantidadLibros) {
    for (int i = 0; i < cantidadLibros; i++) {
        printf("\nLibro %d:\n", i + 1);
        printf("Titulo: %s", biblioteca[i].titulo);
        printf("Autor: %s", biblioteca[i].autor);
        printf("Editorial: %s", biblioteca[i].editorial);
        printf("ISBN: %s\n", biblioteca[i].isbn);
        printf("Prestado: %s\n", biblioteca[i].prestado ? "Sí" : "No");
    }
}

void prestarLibro(Libro biblioteca[], int cantidadLibros) {
    char isbn[20];
    printf("Ingrese el ISBN del libro a prestar: ");
    scanf("%s", isbn);

    ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
    int indice = buscarLibroBinario(biblioteca, cantidadLibros, isbn);

    if (indice != -1 && biblioteca[indice].prestado == 0) {
        biblioteca[indice].prestado = 1;
        printf("Libro prestado con exito.\n");
    } else if (indice != -1) {
        printf("El libro ya está prestado.\n");
    } else {
        printf("Libro no encontrado.\n");
    }
}

void modificarLibro(Libro biblioteca[], int cantidadLibros) {
    char isbn[20];
    printf("Ingrese el ISBN del libro a modificar: ");
    scanf("%s", isbn);
    getchar(); // limpiar buffer

    ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
    int indice = buscarLibroBinario(biblioteca, cantidadLibros, isbn);

    if (indice != -1) {
        printf("Ingrese el nuevo titulo: ");
        fgets(biblioteca[indice].titulo, 100, stdin);

        printf("Ingrese el nuevo autor: ");
        fgets(biblioteca[indice].autor, 50, stdin);

        printf("Ingrese la nueva editorial: ");
        fgets(biblioteca[indice].editorial, 50, stdin);

        printf("Libro modificado.\n");
    } else {
        printf("Libro no encontrado.\n");
    }
}

void ordenarBibliotecaPorISBN(Libro biblioteca[], int cantidadLibros) {
    for (int i = 0; i < cantidadLibros - 1; i++) {
        for (int j = 0; j < cantidadLibros - i - 1; j++) {
            if (strcmp(biblioteca[j].isbn, biblioteca[j + 1].isbn) > 0) {
                Libro temp = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = temp;
            }
        }
    }
}

int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, char isbn[]) {
    int inicio = 0, fin = cantidadLibros - 1;
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        int cmp = strcmp(biblioteca[medio].isbn, isbn);
        if (cmp == 0)
            return medio;
        else if (cmp < 0)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}
