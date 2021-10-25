/*
 ============================================================================
 Name        : AgnoliParcialProgr.c
 Author      : Agnoli Luca Nahuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct{
	int id;
	char procesador[21];
	char marca[21];
	float precio;
}typedef eNotebook;;

float descuento(float precio);
int contarCaracteres(char cadenaIngresada[],char x);
int ordenarMarcaxPrecio(eNotebook notebook[],int tamNotebook,int criterio);

#define TAM_S 20
#define TAM_N 5

int main(void)
{
	setbuf(stdout,NULL);
	float precio;
	float precioAgarrar;
	char cadena[20];
	int contadorLetra;
	char letra;
	int criterio;

	eNotebook auxNotebook[TAM_N]={
			{1,"5 3500X","AMD",150.5},
			{2,"i5 9600K","Intel",170.5},
			{3,"7 5700G","AMD",200},
			{4,"i7 9700F","Intel",250},
			{5,"a2700","CML",120},
		};
// FUNCION 1
	printf("Ingrese un precio(se le aplicara un 5%% de descuento): \n");
	scanf("%f",&precio);
	printf("Precio original: %.2f\n",precio);
	precioAgarrar=descuento(precio);
	printf("Precio con descuento del 5%% = %.2f\n",precioAgarrar);




// FUNCION 2
	printf("Ingrese una una palabra o frase:  \n");
	fflush(stdin);
	gets(cadena);
	printf("Ingrese la letra que desea buscar en la frase: \n");
	fflush(stdin);
	scanf("%c",&letra);
	while(strlen(cadena)>TAM_S-1)
	{
		printf("Error, pasa el tamaño maximo permitido.Por favor, reingreselo: \n");
		fflush(stdin);
		gets(cadena);
	}
	contadorLetra=contarCaracteres(cadena, letra);
	printf("La cantidad de veces que aparece la letra s es de : %d\n",contadorLetra);


// FUNCION 3
	printf("\nIngrese un criterio de ordenamiento --> 1(ascendente) / 0(descendente) : \n");
	scanf("%d",&criterio);
	system("cls");
	printf(" *** Listado de notebook ***\n");
	printf("ID  procesador         marca    precio \n");
	printf("------------------------------------------\n");
	ordenarMarcaxPrecio(auxNotebook, TAM_N, criterio);
	for(int i=0;i<TAM_N;i++)
	{
		printf("%-5d %-15s %-10s  %.2f\n",
		auxNotebook[i].id,
		auxNotebook[i].procesador,
		auxNotebook[i].marca,
		auxNotebook[i].precio
					);
	}

	return EXIT_SUCCESS;
}


float descuento(float precio)
{
	if(precio>=0)
	{
		precio=precio*0.95;
	}
	return precio;
}

int contarCaracteres(char cadenaIngresada[],char x)
{
	int contador=-1;
	int tamVector;
	if(cadenaIngresada!=NULL)
	{
		contador=0;
		tamVector=strlen(cadenaIngresada);
		for(int i=0;i<tamVector;i++)
		{
			if(cadenaIngresada[i]==x)
			{
				contador++;
			}
		}
	}
	return contador;
}

int ordenarMarcaxPrecio(eNotebook notebook[],int tamNotebook,int criterio)
{
	int todoOk=0;
	eNotebook auxNote;
	if(notebook!=NULL && tamNotebook>0 && criterio>=0 && criterio<=1)
	{
			for(int i=0;i<tamNotebook-1;i++)
			{
				for(int j=i+1;j<tamNotebook;j++)
				{
					if(criterio==1)
					{

						if( (strcmp(notebook[i].marca, notebook[j].marca)>0) ||
									(strcmp(notebook[i].marca, notebook[j].marca)==0 && notebook[i].precio>notebook[j].precio ) )
						{
							auxNote=notebook[i];
							notebook[i]=notebook[j];
							notebook[j]=auxNote;
						}

					}else if(criterio==0)
					{

						if( (strcmp(notebook[i].marca, notebook[j].marca)<0) ||
									(strcmp(notebook[i].marca, notebook[j].marca)==0 && notebook[i].precio<notebook[j].precio ) )
						{
							auxNote=notebook[i];
							notebook[i]=notebook[j];
							notebook[j]=auxNote;
						}
					}

				}
			}
			todoOk=1;
	}

	return todoOk;
}
