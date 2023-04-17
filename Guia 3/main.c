#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Prototipado de las funciones
Pila ingresoElementosAPila(pila1);
Pila pasarPilaAOtraPila (Pila, Pila);
Pila encontrarMenorElementoYRetornarEnOtraPila (Pila pila4, Pila aux4, Pila menor4);
Pila insertarUnElementoEnUnaPilaOrdenada (Pila pila6, Pila aux6, Pila pedido6);
int quitarDosPrimerosElementosDeUnaPilaYSumarlos (Pila pila8);
float divisionElementosDeUnaPila (float suma9, float contador9);
float contarElementosDeUnaPila (Pila pila9);
float sumarElementosDeUnaPila (Pila pila9);
float promedioElementosDeUnaPila (float promedio9);
int convertir_pila_a_decimal (Pila pila);



int main(int argc, char *argv[])
{
    int selected;
    Pila pila1;
    Pila pila2, pilaFinal;
    Pila pila3, pilaFinal3;
    Pila pila4, menor4, aux4;
    Pila pila6, aux6, pedido6;
    Pila pila8;
    Pila pila9;
    Pila pila10;

    inicpila(&pila1);
    inicpila(&pila2);
    inicpila(&pilaFinal);
    inicpila(&pilaFinal3);
    inicpila(&pila3);
    inicpila(&pila4);
    inicpila(&menor4);
    inicpila(&aux4);
    inicpila(&pila6);
    inicpila(&aux6);
    inicpila(&pedido6);
    inicpila(&pila8);
    inicpila(&pila9);
    inicpila(&pila10);

    int sumaDosNumeros;
    int suma8;
    int numero;
    float promedio9;
    float suma9;
    float contador9;
    float division9;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            pila1 = ingresoElementosAPila(pila1);
            mostrar(&pila1);
            system("PAUSE");
            break;
        case 2:
            pila2 = ingresoElementosAPila(pila2, pilaFinal);
            mostrar(&pila2);
            pilaFinal = pasarPilaAOtraPila(pila2, pilaFinal);
            mostrar(&pilaFinal);
            system("PAUSE");
            break;
        case 3:
            pila3 = ingresoElementosAPila(pila3, pilaFinal3);
            mostrar(&pila3);
            pilaFinal3 = pasarPilaAOtraPila(pilaFinal3, pila3);
            mostrar(&pilaFinal3);
            system("PAUSE");
            break;
        case 4:
            pila4 = ingresoElementosAPila(pila4);
            pila4 = encontrarMenorElementoYRetornarEnOtraPila (pila4, menor4, aux4);
            mostrar(&pila4);
            system("PAUSE");
            break;
        case 5:
            funcion_x();
            break;
        case 6:
            pila6 = insertarUnElementoEnUnaPilaOrdenada (pila6, aux6, pedido6);
            mostrar(&pila6);
            system("PAUSE");
            break;
        case 7:
            funcion_x();
            break;
        case 8:
            pila8 = ingresoElementosAPila(pila8);
            suma8 = quitarDosPrimerosElementosDeUnaPilaYSumarlos(pila8);
            printf("Suma: %i\n", suma8);
            mostrar(&pila8);
            system("PAUSE");
            break;
        case 9:
            pila9 = ingresoElementosAPila(pila9);
            suma9 = sumarElementosDeUnaPila(pila9);
            contador9 = contarElementosDeUnaPila(pila9);
            division9 = divisionElementosDeUnaPila(suma9, contador9);
            promedio9 = promedioElementosDeUnaPila(division9);
            printf("El promedio es: %g\n", promedio9);
            system("PAUSE");
            break;

        case 10:
            pila10 = ingresoElementosAPila(pila10);
            numero = convertir_pila_a_decimal(pila10);
            printf("El numero decimal es: %i\n", numero);
            system("PAUSE");
            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");


        }

    }
    while(selected!=0);

    system("PAUSE");
    return 0;
}
int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Agrega elementos a Pila");
    printf("\n2-Pasa elemento de una pila a otra");
    printf("\n3-Pasa elementos de una pila a otra (conserva el orden)");
    printf("\n4-Retorna el menor elemento de una lista");
    printf("\n5-Pasa elementos de una pila a otra y genera una nueva pila ordenada");
    printf("\n6-Inserta un elemento en una pila ordenada (conserva el orden)");
    printf("\n7-Pasa los elementos de una pila a otra, genera una ordenada (usa funcion 6)");
    printf("\n8-Suma y retorna primeros 2 elementos de una pila,sin alterar su contenido");
    printf("\n9-Calcula promedio de una pila (usa funcion de suma, division y cuenta)");
    printf("\n10-Recibe pila con numeros de un digito y los transforma en un numero decimal");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}

/// Funciones

funcion_x()
{
    system("cls");
    system("color 1E");
    printf("\n\naca deberia estar la funcion pedida en cada ejercicio de la practica\n");
    system("PAUSE");
}

//Funcion 1
Pila ingresoElementosAPila (Pila pila1) {
    int conf = 0;
    while(conf == 0) {
    leer(&pila1);
    printf("Escriba 0 para seguir, 1 para parar de agregar numeros\n");
    fflush(stdin);
    scanf("%i", &conf);
}
    return pila1;
}

// Funcion 2 y 3
Pila pasarPilaAOtraPila (Pila pila2, Pila pilaFinal) {
    while(!pilavacia(&pila2)) {
        apilar(&pilaFinal, desapilar(&pila2));
}
    return pilaFinal;
}

// Funcion 4
Pila encontrarMenorElementoYRetornarEnOtraPila (Pila pila4, Pila aux4, Pila menor4) {
    apilar(&menor4, desapilar(&pila4));

    while(!pilavacia(&pila4)){
        if(tope(&pila4) < tope(&menor4)){
            apilar(&aux4, desapilar(&menor4));
            apilar(&menor4, desapilar(&pila4));
        }
        else{
            apilar(&aux4, desapilar(&pila4));
        }
    }
return aux4;
}

// Funcion 5



// Funcion 6
Pila insertarUnElementoEnUnaPilaOrdenada (Pila pila6, Pila aux6, Pila pedido6) {


    printf("Inserte un numero para ingresarlo en la pila.\n");
    leer(&pedido6);

    for(int i = 20; i >= 2; i = i - 2){
        apilar(&pila6, i);
    }

    while(!pilavacia(&pila6) && !pilavacia(&pedido6)){
        if(tope(&pedido6) <= tope(&pila6)){
            apilar(&pila6, desapilar(&pedido6));
        }
        else{
            apilar(&aux6, desapilar(&pila6));
        }
        if(pilavacia(&pila6)){
            apilar(&pila6, desapilar(&pedido6));
        }
    }

    while(!pilavacia(&aux6)){
        apilar(&pila6, desapilar(&aux6));
    }
return pila6;
}

// Funcion 8
int quitarDosPrimerosElementosDeUnaPilaYSumarlos (Pila pila8) {
    Pila aux8;
    inicpila(&aux8);
    aux8 = pila8;
    int num1;
    int num2;
    int suma;
    num1 = tope(&aux8);
    desapilar(&aux8);
    num2 = tope(&aux8);
    suma = num1 + num2;

return suma;
}

// Funcion 9
float contarElementosDeUnaPila (Pila pila9) {
    float contador9 = 0;
    Pila aux9;
    inicpila(&aux9);
    while(!pilavacia(&pila9)){
        contador9++;
        apilar(&aux9, desapilar(&pila9));
    }

return contador9;
}

float sumarElementosDeUnaPila (Pila pila9) {
    float suma9 = 0;
    Pila aux9;
    inicpila(&aux9);
    while(!pilavacia(&pila9)){
        suma9 += tope(&pila9);
        apilar(&aux9, desapilar(&pila9));
    }
return suma9;
}

float divisionElementosDeUnaPila (float suma9, float contador9) {
    float promedio9 = 0;

    promedio9 =  suma9 / contador9;
return promedio9;
}

float promedioElementosDeUnaPila (float promedio9) {
    float total = promedio9;

return total;
}

// Funcion 10

int convertir_pila_a_decimal(Pila pila) {
    int decimal = 0;
    int potencia = 1;

    while (!pilavacia(&pila)) {
        int digito = tope(&pila);
        desapilar(&pila);
        decimal += digito * potencia;
        potencia *= 10;
    }

    return decimal;
}








