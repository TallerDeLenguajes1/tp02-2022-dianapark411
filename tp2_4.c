#include <stdio.h>
#include <stdlib.h>

struct compu{
    int velocidad;
    int anio;
    int cantidad;
}; 

void cargarDatos(struct compu *punt, int n);
void mostrarPCs(struct compu *punt, int n);
void mostrarUnaPC(struct compu *punt);
void presentarPcVieja(struct compu *punt, int n);
void presentarPcRapida(struct compu *punt, int n);

int main(){

    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int n = 2;
    struct compu *PC;

    PC = malloc(n*sizeof(struct compu));

    //INGRESO LOS DATOS
    cargarDatos(PC,n);
    //Muestro las computadoras

    printf("\n---LISTADO DE LAS PC INGRESADAS---");
    mostrarPCs(PC,n);
    
    presentarPcVieja(PC,n);

    presentarPcRapida(PC,n);

    free(PC);

    return 0;
}


void cargarDatos(struct compu *punt, int n){
    for (int i = 0; i < n; i++)
    {
        do{
            printf("Ingrese la velocidad de procesamiento(entre 1 y 3 Gherz): ");
            scanf("%i", &punt->velocidad);
        } while (punt->velocidad < 1 || punt->velocidad >3);

        do{
            printf("Ingrese el anio de fabricacion(entre 2015 y 2022): ");
            scanf("%i", &punt->anio);
        } while (punt->anio < 2015 || punt->anio > 2022);

        do{
            printf("Ingrese la cantidad de nucleos(entre 1 y 8): ");
            scanf("%i", &punt->cantidad);
        } while (punt->cantidad < 1 || punt->cantidad > 8);

        punt ++;
    }
}


void mostrarUnaPC(struct compu *punt){
    printf("\nVelocidad de procesamiento de la PC: %i", punt->velocidad);
    printf("\nAnio de fabricacion de la PC: %i", punt->anio);
    printf("\nCantidad de nucleos de la PC: %i", punt->cantidad);
}

void mostrarPCs(struct compu *punt, int n){

    for (int i = 0; i < n; i++)
    {
        printf("\n------------------ PC [ %d ] ------------------", i+1);

        mostrarUnaPC(punt);
        punt ++;
    }
}

void presentarPcVieja(struct compu *punt, int n){
    int vieja, indice = 0;
    vieja = punt->anio; 
    for (int i = 0; i < n; i++){        
        if (punt->velocidad < vieja){
            vieja = punt->anio; 
            indice = i;
        }
        punt ++;
    }
 

    printf("\n\nLa PC mas vieja es la: %i. Del anio: %i", indice, vieja);
    
}


void presentarPcRapida(struct compu *punt, int n){

    int mayor, indice=0;
    mayor = punt->velocidad; 
    
    for (int i = 0; i < n; i++){       
        if (punt->velocidad > mayor){
            mayor = punt->velocidad; 
            indice = i;
        }
        punt ++;
    }

    printf("\nLa PC mas rapida es la: %i. Tiene una velocidad de %i Gherz", indice, mayor);

}

