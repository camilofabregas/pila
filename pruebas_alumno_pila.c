#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#define TAM_VECTOR 40


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


void pruebas_pila_vacia() {
	printf("\nINICIO DE PRUEBAS PARA PILA VACÍA\n");

	/* Declaro las variables a utilizar */
    pila_t* pila1 = pila_crear();

    /* Inicio de pruebas */
    print_test("Pila inicializada correctamente", pila1 != NULL);
    print_test("Pila esta vacia es verdadero", pila_esta_vacia(pila1));
    print_test("Desapilar ultimo valor es NULL", !pila_desapilar(pila1)); // Caso borde
    print_test("Ver tope de pila es NULL", !pila_ver_tope(pila1)); // Caso borde

    /* Destruyo la pila*/
    pila_destruir(pila1);
    print_test("Pila destruida", true);
}


void pruebas_pila_algunos_elementos() {
    printf("\nINICIO DE PRUEBAS PARA PILA CON ALGUNOS ELEMENTOS\n");

    /* Declaro las variables a utilizar */
    pila_t* pila2 = pila_crear();
    int num1 = 5;
    int num2 = 8;
    int num3 = 2;

    /* Chequeo pila, apilo algunos elementos y chequeo topes */
    print_test("Pila inicializada correctamente", pila2 != NULL);
    print_test("Apilar numero 5", pila_apilar(pila2, &num1));
    print_test("Tope es igual a 5", pila_ver_tope(pila2) == &num1);
    print_test("Apilar numero 8", pila_apilar(pila2, &num2));
    print_test("Tope es igual a 8", pila_ver_tope(pila2) == &num2);
    print_test("Apilar numero 2", pila_apilar(pila2, &num3));
    print_test("Tope es igual a 2", pila_ver_tope(pila2) == &num3);

    /* Desapilo cada elemento y chequeo topes */
    print_test("Pila esta vacia es falso", !pila_esta_vacia(pila2));
    print_test("Desapilar numero 2", pila_desapilar(pila2) == &num3);
    print_test("Tope es igual a 8", pila_ver_tope(pila2) == &num2);
    print_test("Desapilar numero 8", pila_desapilar(pila2) == &num2);
    print_test("Tope es igual a 5", pila_ver_tope(pila2) == &num1);
    print_test("Desapilar numero 5", pila_desapilar(pila2) == &num1);
    print_test("Pila esta vacia es verdadero", pila_esta_vacia(pila2)); // Caso borde
    print_test("Desapilar ultimo valor es NULL", !pila_desapilar(pila2)); // Caso borde
    print_test("Ver tope de pila es NULL", !pila_ver_tope(pila2)); // Caso borde


    /* Destruyo el vector*/
    pila_destruir(pila2);
    print_test("Pila destruida", true);
}


void pruebas_pila_elemento_null() {
    printf("\nINICIO DE PRUEBAS PARA PILA CON ELEMENTO NULL\n");

    /* Declaro las variables a utilizar */
    pila_t* pila3 = pila_crear();
    int num = 5;
    void* elem1_null = NULL;
    void* elem2_null = NULL;

    /* Inicio de pruebas */
    print_test("Pila inicializada es verdadero", pila3 != NULL);
    print_test("Apilar elemento NULL", pila_apilar(pila3, elem1_null));
    print_test("Tope es igual a NULL", pila_ver_tope(pila3) == NULL);
    print_test("Apilar numero 5", pila_apilar(pila3, &num));
    print_test("Tope es igual a 5", pila_ver_tope(pila3) == &num);
    print_test("Apilar elemento NULL", pila_apilar(pila3, elem2_null));
    print_test("Tope es igual a NULL", pila_ver_tope(pila3) == NULL);
    print_test("Desapilar elemento NULL", pila_desapilar(pila3) == NULL);
    print_test("Desapilar numero 5", pila_desapilar(pila3) == &num);
    print_test("Pila esta vacia es falso", !pila_esta_vacia(pila3));
    print_test("Desapilar elemento NULL", pila_desapilar(pila3) == NULL);
    print_test("Pila esta vacia es verdadero", pila_esta_vacia(pila3));


    /* Destruyo el vector*/
    pila_destruir(pila3);
    print_test("Pila destruida", true);
}


void pruebas_pila_volumen() {
    printf("\nINICIO DE PRUEBA DE VOLUMEN PARA PILA\n");

    /* Declaro las variables a utilizar */
    pila_t* pila4 = pila_crear();
    int vec[TAM_VECTOR];

    /* Inicio de pruebas */
    print_test("Pila inicializada", pila4 != NULL);
    for (int i = 0; i < TAM_VECTOR; i++) {
    	vec[i] = i+1;
    	print_test("Apilar elemento es true", pila_apilar(pila4, &vec[i]) == true);
    	print_test("Tope es igual al valor apilado", pila_ver_tope(pila4) == &vec[i]);
    }
    for (int i = TAM_VECTOR - 1; i >= 0; i--) {
    	print_test("Nuevo tope es igual al valor apilado", pila_ver_tope(pila4) == &vec[i]);
    	int* desapilado = pila_desapilar(pila4);
    	print_test("El elemento desapilado es correcto", desapilado ==  &vec[i]);
    	print_test("Valor correcto recibido", *desapilado == i+1);
	}
	print_test("Pila esta vacia es verdadero", pila_esta_vacia(pila4));
	print_test("Desapilar ultimo valor es NULL", !pila_desapilar(pila4));

    /* Destruyo el vector*/
    pila_destruir(pila4);
    print_test("Pila destruida", true);
}


void pruebas_pila_alumno() {
	pruebas_pila_vacia();
	pruebas_pila_algunos_elementos();
	pruebas_pila_elemento_null();
	pruebas_pila_volumen();
}


