#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Prototipado de las funciones
void cargarPila(Pila *pilaACompletar);
Pila deUnaPilaAOtra(Pila *pilaOrigen, Pila *pilaDestino);
Pila pasarDeUnaAOtraConElMismoOrden(Pila *pilaOrigen, Pila *pilaDestino);
Pila encontrarElMenorElementoDeUnaPilaOriginal(Pila *pila4);
Pila agregarUnElemento(Pila *pilaOrigen, Pila *pilaDestino);
Pila deUnaAOtraOrdenados(Pila *pilaOrigen);
int retornarDosPrimerosDeUnaPila(Pila pilaOrigen);
int sumarTodosLosElementosDeUnaPila(Pila *pilaOrigen);
int contarTodosLosElementosDeUnaPila(Pila *pilaOrigen);
float dividir(int *dividendo, int *divisor);
float promediarElementos(Pila *pilaOrigen);
int concatenarTodaLaPila(Pila *pilaOrigen);

int main(int argc, char *argv[])
{
    Pila pila1;
    Pila pila2;
    Pila pila3;
    Pila pilaDestinoDeMenor;
    inicpila(&pila1);
    inicpila(&pila2);
    inicpila(&pila3);
    inicpila(&pilaDestinoDeMenor);
    int selected = 0;
    int sumaDeLosDosPrimeros = 0;
    int cuentaDeLosDosPrimeros = 0;
    float promedio9 = 0;
    int concatenacion = 0;

    printf("Vamos a comenzar cargando una pila:\n");
    int opcion = 1;
    while(opcion != 0){
        switch(opcion) {
            case 1:
                cargarPila(&pila1);
                break;
            case 2:
                deUnaPilaAOtra(&pila1, &pila2);
                break;
            case 3:
                pasarDeUnaAOtraConElMismoOrden(&pila1, &pila2);
                break;
            case 4:
                encontrarElMenorElementoDeUnaPilaOriginal(&pila1);
                break;
            case 5:
                pasarDeUnaPilaAOtra(&pila1);
                break;
            case 6:
                insercionDeElementos(&pila1, 3);
                break;
            case 7:
                // No hay función asignada para el ejercicio 7.
            break;
            case 8:
                retornarDosPrimerosDeUnaPila(pila1);
                break;
            case 9:
                sumarTodosLosElementosDeUnaPila(&pila1);
                break;
            default:
                printf("Opción invalida.\n");
                break;
            }
            printf("\nDeseas hacer otra operacion? Si si, marca del 1 al 9. Si no, marca 0:\n\n");
            printf("*****************\n");
            printf("1. Cargar elementos en una pila\n");
            printf("2. Pasar elementos de una pila a otra\n");
            printf("3. Pasar elementos de una pila a otra manteniendo el orden original\n");
            printf("4. Encontrar el menor elemento de una pila\n");
            printf("5. Pasar elementos de una pila a otra, pero alternando entre ellas\n");
            printf("6. Insertar un elemento en una pila de manera ordenada\n");
            printf("7. [No hay función asignada para el ejercicio 7]\n");
            printf("8. Retornar los dos primeros elementos de una pila\n");
            printf("9. Sumar todos los elementos de una pila\n");
            printf("*****************\n");
            printf("\n\nTu eleccion es: ");
            scanf("%i", &opcion);
    }
}
//EJERCICIO 1
void cargarPila(Pila *pilaACompletar)
{
    int control = 0;
    while(control == 0)
    {
        leer(pilaACompletar);
        printf("Presiona 0 para seguir, 1 para cortar.\n");
        fflush(stdin);
        scanf("%i", &control);
    }
}
//EJERCICIO 2
Pila deUnaPilaAOtra(Pila *pilaOrigen, Pila *pilaDestino)
{
    while(!pilavacia(&pilaOrigen))
    {
        apilar(&pilaDestino, desapilar(&pilaOrigen));
    }
}
//EJERCICIO 3
Pila pasarDeUnaAOtraConElMismoOrden(Pila *pilaOrden, Pila *pilaOrigen2) {
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pilaOrden)) {
        apilar(&aux, desapilar(pilaOrden));
    }

    while(!pilavacia(&aux)) {
        apilar(pilaOrigen2, desapilar(&aux));
    }

    return *pilaOrigen2;
}
//EJERCICIO 4
Pila encontrarElMenorElementoDeUnaPilaOriginal(Pila *pila4)
{
    Pila menor4, aux4;
    inicpila(&menor4);
    inicpila(&aux4);
    int resultado = 0;
    apilar(&menor4, desapilar(&pila4));

    while(!pilavacia(&pila4)){
        if(tope(&pila4) < tope(&menor4)){
            apilar(&aux4, desapilar(&menor4));
            apilar(&menor4, desapilar(&pila4));
        }
        else{
            apilar(&aux4, desapilar(&pila4));
        }
        resultado = tope(&menor4);
        while(!pilavacia(&aux4)){
            apilar(&pila4, desapilar(&aux4));
        }
        return menor4;
    }
}
// EJERCICIO 5 (grafico en https://imgur.com/a/HkpLyAo)
void pasarDeUnaPilaAOtra(Pila *pila5){
    Pila resultadoDe4, resultadoFinal, auxiliarDeNoMenores, auxiliar;

    inicpila(&resultadoDe4);
    inicpila(&resultadoFinal);
    inicpila(&auxiliarDeNoMenores);
    inicpila(&auxiliar);

    resultadoDe4 = encontrarElMenorElementoDeUnaPilaOriginal(&pila5);
    apilar(&resultadoFinal, desapilar(&resultadoDe4));

    while(!pilavacia(&pila5)){

        if(!pilavacia(&resultadoFinal)){
            apilar(&pila5, desapilar(&auxiliar));
        }

        if(tope(&pila5) > tope(&resultadoFinal)){
            apilar(&resultadoFinal, desapilar(&pila5));
        } else {
            apilar(&auxiliarDeNoMenores, desapilar(&pila5));
        }

        while(!pilavacia(&auxiliarDeNoMenores)){
            apilar(&pila5, desapilar(&auxiliarDeNoMenores));
        }
        while(!pilavacia(&resultadoFinal)){
            apilar(&auxiliar, desapilar(&resultadoFinal));
        }
    }
    *pila5 = resultadoFinal;

}

// EJERCICIO 6
void insercionDeElementos(Pila *origen, int elemento){
    Pila auxiliar;
    inicpila(&auxiliar);
    int flag = 0;

    while(!pilavacia(&origen) && flag == 0){
        if(tope(&origen) < elemento){
            apilar(&origen, elemento);
            flag = 1;
        }
        else{
            apilar(&auxiliar, desapilar(&origen));
        }
    }

    if(flag == 1 && !pilavacia(&auxiliar)){
        apilar(&origen, desapilar(&auxiliar));
    }
}
// EJERCICIO 7
void generarPilaOrdenada(Pila *origen){
    Pila destino;
    inicpila(&destino);

    while(!pilavacia(&origen)){
        int elemento = tope(&origen);
        insercionDeElementos(&destino, &elemento);
    }
}

// EJERCICIO 8
int retornarDosPrimerosDeUnaPila(Pila pilaOrigen){
    Pila pilaAuxiliar;
    inicpila(&pilaAuxiliar);

    int primerValor = 0;
    int segundoValor = 0;
    int totalDeLaSuma = 0;

    pilaAuxiliar = pilaOrigen;

    primerValor = tope(&pilaOrigen);
    desapilar(&pilaOrigen);

    segundoValor = tope(&pilaOrigen);

    totalDeLaSuma = primerValor + segundoValor;
    return totalDeLaSuma;
}
// EJERCICIO 9
int sumarTodosLosElementosDeUnaPila(Pila *pilaOrigen){
    Pila auxiliar;
    inicpila(&auxiliar);
    int acumuladorDeTopes = 0;

    auxiliar = *pilaOrigen;

    while(!pilavacia(&auxiliar)){
        acumuladorDeTopes += tope(&auxiliar);
        desapilar(&auxiliar);
    }
}

int contarTodosLosElementosDeUnaPila(Pila *pilaOr){
    Pila auxiliar;
    inicpila(&auxiliar);
    int cantidad = 0;

    auxiliar = *pilaOr;

    while(!pilavacia(&auxiliar)){
        cantidad++;
        desapilar(&auxiliar);
    }
}

float dividir(int *dividendo, int *divisor){
    float producto = *dividendo/ *divisor;
}

float promediarElementos(Pila *pilaOrigen){
    return dividir(sumarTodosLosElementosDeUnaPila(pilaOrigen), contarTodosLosElementosDeUnaPila(pilaOrigen));
}

// Ejercicio 10
int concatenarTodaLaPila(Pila *pilaOrigen){
    Pila auxiliar;
    inicpila(&auxiliar);
    char strConcatenacion[50]; // Cadena de caracteres para concatenar valores
    strConcatenacion[0] = '\0'; // Inicializar la cadena vacía

    // Copiar los elementos de la pila de origen a la pila auxiliar
    while (!pilavacia(&pilaOrigen)) {
        apilar(&auxiliar, tope(&pilaOrigen));
        desapilar(&pilaOrigen);
    }

    // Concatenar los valores de la pila auxiliar en la cadena de caracteres
    while (!pilavacia(&auxiliar)) {
        char strValor[10];
        sprintf(strValor, "%d", tope(&auxiliar));
        strcat(strConcatenacion, strValor);
        // en strConcatenacion += strValor;
        desapilar(&auxiliar);
    }

    // atoi para str to int
    return atoi(strConcatenacion);
}







