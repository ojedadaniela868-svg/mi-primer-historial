
#include<stdio.h>
#include<string.h>

int main(){
    int opcion;
    do{
        printf("\n==========MENU==========\n\n");
        printf("1.- Mostrar todas la calificaciones registradas\n");
        printf("2.- Calcular el promedio del grupo.\n");
        printf("3.- Identificar la calificacion mas alta y la mas baja.\n");
        printf("4.- Indicar cuantos estudiantes aprobaron y cuantos reprobaron.\n");
        printf("5.- Salir del programa.\n");

        printf("Elija la opcion que desea consultar(1,2,3,4 o 5): ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
            mostrar_datos(estudiante, i);
            break;
            case 2:
            calcular_promedio_grupo(estudiante, i);
            break;
            case 3:
            calificacion_alta_y_baja(estudiante, i);
            break;
            case 4:
            estudiantes_aprobados_y_reprobados(estudiante, i);
            break;
        }
    }while(opcion!=5);

}
