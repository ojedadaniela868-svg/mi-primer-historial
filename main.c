
#include<stdio.h>
#include<string.h>
#define size_arreglo 20

struct datos_alumnos{
    char nombre[30];
    char apellido_paterno[15];
    char apellido_materno[15];
    int registro;
    int semestre;
    char carrera[100];
    float calificacion;
    char materias_reprobadas[50];
    int num_sanciones;
};

void quitar_salto_linea(char *cadena);
void capturar_datos_estudiantes(struct datos_alumnos estudiante[], int *i);
void mostrar_datos(struct datos_alumnos estudiante[], int total_alumnos);
void calcular_promedio_grupo(struct datos_alumnos estudiante[], int total_alumnos);
void calificacion_alta_y_baja(struct datos_alumnos estudiante[], int total_alumnos);
void estudiantes_aprobados_y_reprobados(struct datos_alumnos estudiante[], int total_alumnos);

int main(){
    int i=0;
    int seguir,opcion;
    struct datos_alumnos estudiante[size_arreglo];

    do{
        capturar_datos_estudiantes(estudiante, &i);
        do{
            printf("Desea capturar los datos de otro estudiante?(max. de 20 estudiantes), (1 para SI, 0  para N0): ");
            scanf("%d",&seguir);
        }while(seguir<0 || seguir>1);

        getchar();

    }while(seguir==1 && i<size_arreglo);

    printf("\n==========Registro de datos finalizado==========\n");

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



//FUNCIONES

void quitar_salto_linea(char *cadena) {
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}

void capturar_datos_estudiantes(struct datos_alumnos estudiante[], int *i){

printf("\n==========Registro de estudiante %d==========\n\n",(*i)+1);
        printf("Nombre(s) de alumno: ");
        fgets(estudiante[*i].nombre, sizeof(estudiante[*i].nombre), stdin);
        quitar_salto_linea(estudiante[*i].nombre);
        
        printf("Apellido paterno: ");
        fgets(estudiante[*i].apellido_paterno, sizeof(estudiante[*i].apellido_paterno), stdin);
        quitar_salto_linea(estudiante[*i].apellido_paterno);

        printf("Apellido materno: ");
        fgets(estudiante[*i].apellido_materno, sizeof(estudiante[*i].apellido_materno),stdin);
        quitar_salto_linea(estudiante[*i].apellido_materno);

        printf("Registro: ");
        scanf("%d",&estudiante[*i].registro);

        do{
            printf("Semestre (Ingrese numero de semestre): ");
            scanf("%d",&estudiante[*i].semestre);
        }while(estudiante[*i].semestre<1 || estudiante[*i].semestre>6);
        
        getchar();

        printf("Carrera: ");
        fgets(estudiante[*i].carrera, sizeof(estudiante[*i].carrera),stdin);
        quitar_salto_linea(estudiante[*i].carrera);

        do{
        printf("Calificacion(0-100): ");
        scanf("%f",&estudiante[*i].calificacion);
        }while(estudiante[*i].calificacion<0 || estudiante[*i].calificacion>100);
        getchar();

        printf("Nombres de materias reprobadas: ");
        fgets(estudiante[*i].materias_reprobadas, sizeof(estudiante[*i].materias_reprobadas),stdin);
        quitar_salto_linea(estudiante[*i].materias_reprobadas);

        printf("Numero de sanciones: ");
        scanf("%d",&estudiante[*i].num_sanciones);

        (*i)++;
}


void mostrar_datos(struct datos_alumnos estudiante[], int total_alumnos){

    for(int k=0;k<total_alumnos;k++){
        printf("\nAlumno %d: %s %s %s. Registro: %d\n",k+1,estudiante[k].nombre, estudiante[k].apellido_paterno,estudiante[k].apellido_materno,estudiante[k].registro);
        printf("Carrera %s. ||  Semestre: %d.   ||  Calificacion: %.2f.\n",estudiante[k].carrera,estudiante[k].semestre,estudiante[k].calificacion);
        printf("Materias reprobadas: %s. ||  Sanciones: %d.\n",estudiante[k].materias_reprobadas,estudiante[k].num_sanciones);
    }
}

void calcular_promedio_grupo(struct datos_alumnos estudiante[], int total_alumnos){
    int k=0,suma=0;
    while(k<total_alumnos){
        suma+=estudiante[k].calificacion;
        k++;
    }
    float promedio_grupal=(float)suma/k;
    printf("\nPromedio grupal: %.f",promedio_grupal);
}

void calificacion_alta_y_baja(struct datos_alumnos estudiante[], int total_alumnos){
    float calificacion_menor=estudiante[0].calificacion;
    float calificacion_mayor=estudiante[0].calificacion;

    for(int k=0;k<total_alumnos;k++){    
            if(estudiante[k].calificacion>calificacion_mayor){
                calificacion_mayor=estudiante[k].calificacion;
            }
            else if(estudiante[k].calificacion<calificacion_menor){
                calificacion_menor=estudiante[k].calificacion;
            }
    }
    printf("\nCalificacion mayor: %.2f\n",calificacion_mayor);
    printf("Calificacion menor: %.2f\n",calificacion_menor);

}

void estudiantes_aprobados_y_reprobados(struct datos_alumnos estudiante[], int total_alumnos){
    int estudiantes_aprobados=0;
    int estudiantes_reprobados=0;

    for(int k=0;k<total_alumnos;k++){    
            if(estudiante[k].calificacion>=60){
                estudiantes_aprobados++;
            }
            else{
                estudiantes_reprobados++;
            }
    }
    printf("\nEstudiantes aprobados: %d\n",estudiantes_aprobados);
    printf("Estudiantes reprobados: %d\n",estudiantes_reprobados);

}