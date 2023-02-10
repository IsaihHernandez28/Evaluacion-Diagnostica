#include<stdio.h>
#include<stdlib.h>

//FUNCIONES AUXILIARES PARA EL MANEJO DEL ARREGLO
int *makeArray(int size)
{
    int *array;

    array = (int *)malloc(size*sizeof(int));
    
    return array;
}

void printArray(int size, int *array)
{
    for(int index = 0; index < size; index++)
        printf("Dato[%d]: %d \n",index,*(array+index));
}

//FUNCIONES PEDIDAS POR EL PROFESOR PARA EL EXAMEN DIAGNÓSTICO

//INSERTA AL FINAL DE UN ARREGLO
void addAtTail(int data, int **array, int *size)
{
    int *newArray;

    newArray = (int *)realloc(*array, (*size + 1)*sizeof(int));

    if (newArray) 
    {
        *array = newArray;
        *(*array + *size) = data;
        *size = *size + 1;
    }
}

//INSERTA AL INICIO DEL ARREGLO
void addAtFront(int data, int **array, int *size)
{
    int *newArray;
    
    *size = *size + 1;
    newArray = (int *)realloc(*array, (*size)*sizeof(int));

    if (newArray) 
    {
        *array = newArray;
        for (int index = *size - 1; index > 0; index--) 
            *(*array + index) = *(*array + index - 1);
        *(*array) = data;
    }
}

//INDICA CUANTOS DATOS SE HAN INSERTADO
void getSize(int size)
{
    printf("Size = %d \n",size);
}

//BORRA TODOS LOS DATOS INSERTADOS EN EL ARREGLO
void removeAll(int **array, int *size)
{
    free(*array);
    *size = 0;
}

//RECIBE UN INDICE Y DEVUELVE EL VALOR EN ESA POSICIÓN SI ES VÁLIDO
int getAt(int *array, int index, int size)
{
    int newData;

    if(index > size)
    {
        printf("Posicion Invalida");
        return -1;
    }
    else
        return newData = *(array + index);
}

//MAIN DE PRUEBA PARA LAS FUNCIONES
int main()
{
    int size, data, index, aux;
    int *array;

    printf("Size: ");
    scanf("%d",&size);

    array = makeArray(size);
    
    for(int index = 0; index < size; index++)
    {
        printf("Insert[%d]: ",index);
        scanf("%d",array+index);
    }

    printArray(size, array);
    getSize(size);

    printf("Dato: ");
    scanf("%d",&data);
    addAtTail(data, &array, &size);
    printArray(size, array);
    getSize(size);

    printf("Dato: ");
    scanf("%d",&data);
    addAtFront(data, &array, &size);
    printArray(size, array);
    getSize(size);

    printf("Inserta la posición que quieres conocer: ");
    scanf("%d",&index);

    aux = getAt(array, index, size);

    printf("El dato en la posicion %d es %d \n",index,aux);

    removeAll(&array, &size);
    getSize(size);

    return 0;
}