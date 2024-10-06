#include <stdio.h>
#include <string.h>

#define STUDENTS 5
#define SUBJECTS 3

int main() {
    char est[5][26];
    char mat[3][26];
    float notas[3], promes[5] = {0}, promt[3] = {0}, max[3] = {0}, min[3] = {10,10,10};
    int rep[3] = {0}, apro[3] = {0};

    // ingreso de materias
    for (int r = 0; r < 3; r++) {
        printf("¿Cuál es la %d materia? ", r + 1);
        fgets(mat[r], 26, stdin);
        mat[r][strcspn(mat[r], "\n")] = 0;  // eliminar las lineas de los caracteres
    }
    // ingreso de los nombres de los estudiantes y las notas
    for (int i = 0; i < 5; i++) {
        printf("¿Cuál es el nombre del estudiante? \n");
        fgets(est[i], 26, stdin);
        est[i][strcspn(est[i], "\n")] = 0;  // elimina la nueva linea de caracteres

        for (int j = 0; j < 3; j++) {
            do {
                printf("¿Cuál es la nota en la materia %s? ", mat[j]);
                scanf("%f", &notas[j]);
                if (notas[j] < 0  ||notas[j] > 10 ) {
                    printf("Entrada inválida. Por favor, ingrese un número.\n");
                    while (getchar() != '\n');  // limpia el invalido inngreso de datos
                }
            } while (notas[j] < 0 || notas[j] > 10);

            // Climpia la entrada del buffer
            while (getchar() != '\n');

            // se colola las notas maximas y minimas
            if (notas[j] > max[j]) {
                max[j] = notas[j];
            }
            if (notas[j] < min[j]) {
                min[j] = notas[j];
            }

            // calcula la suma de los promedios
            promt[j] += notas[j];
            promes[i] += notas[j];

            // cuenta de los que pasan y de los que se quedan 
            if (notas[j] >= 6) {
                apro[j]++;
            } else {
                rep[j]++;
            }
        }
    }

    // calcula el promedio por cada materia
    for (int p = 0; p < 3; p++) {
        promt[p] /= 5;  // division por el numero de estudiants
    }

    // calcula el promedio de cada uno de los estudiantes
    for (int u = 0; u < 5; u++) {
        promes[u] /= 3;  // divide por el numero de materias
    }

    // imprime los resultados
    for (int o = 0; o < 5; o++) {
        printf("----------------------------------RESULTADO--------------------------------------\n");
        printf("El promedio de las notas del estudiante %s es de: %.2f\n", est[o], promes[o]);
        printf("------------------------------------------------------------------------------\n");
    }

    for (int l = 0; l < 3; l++) {
        printf("El promedio de la materia %s es de: %.2f\n", mat[l], promt[l]);
        printf("La cantidad de reprobados de la materia %s es de: %d\n", mat[l], rep[l]);
        printf("La cantidad de aprobados de la materia %s es de: %d\n", mat[l], apro[l]);
        printf("La calificación más alta de la materia %s es de: %.2f\n", mat[l], max[l]);
        printf("La calificación más baja de la materia %s es de: %.2f\n", mat[l], min[l]);
        printf("------------------------------------------------------------------------------\n");
    }

    return 0;  // se regresa el valor de cero para la correcta ejecuciom del problema
}
