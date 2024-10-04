/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   felizcumpleañosputo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:09:27 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/04 10:15:51 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int     ft_letra_oculta(char *str, char letra_secreta);
void    ft_juego_letra_oculta(int *letra_hecha);
void    ft_juego_numero_secreto(int *numero_hecho);

int ft_letra_oculta(char *str, char letra_secreta)
{
    int i;
    int counter = 0;

    for (i = 0; i < strlen(str); i++) 
    {
        if (str[i] == letra_secreta) 
        {
            counter++;
        }
    }
    return counter;
}

void ft_juego_letra_oculta(int *letra_hecha)
{
    char    letra_secreta = 'r';
    char    letra_adivinada;
    char    *palabra1 = malloc(100 * sizeof(char));
    char    *palabra2 = malloc(100 * sizeof(char));
    char    *palabra3 = malloc(100 * sizeof(char));
    int     i;

    int counter = 0;
    system("clear");

    if (palabra1 == NULL || palabra2 == NULL || palabra3 == NULL) 
    {
        printf("Error al asignar memoria.\n");
        return;
    }
    
    printf("¡Bienvenido al juego de la letra oculta!\n");
    printf("Tienes que poner tres palabras para averiguar la letra.\n");
    printf("No puede ser un solo caracter, ni mayor de 5.\n");
    printf("Una vez habiéndolas elegido se revelará el número de veces que se repite.\n");
    printf("Mucha suerte, juega bien tus cartas.\n");
    do 
    {
        printf("Ingresa la primera palabra (2-5 letras): ");
        scanf("%s", palabra1);
        i = 0;
        while (palabra1[i])
        {
            if (isalpha(palabra1[i]))
                i++;
            else
            {
                palabra1[0] = 0;
                printf("Tonto polla, solo letras.\n");
                break;
            }     
        }
    }
    while (strlen(palabra1) < 2 || strlen(palabra1) > 5);
    do 
    {
        printf("Ingresa la segunda palabra (2-5 letras): ");
        scanf("%s", palabra2);
        i = 0;
        while (palabra2[i])
        {
            if (isalpha(palabra2[i]))
                i++;
            else
            {
                palabra2[0] = 0; 
                printf("Tonto polla, solo letras.\n");
                break;
            }
        }
    } 
    while (strlen(palabra2) < 2 || strlen(palabra2) > 5);
    do 
    {
        printf("Ingresa la tercera palabra (2-5 letras): ");
        scanf("%s", palabra3);
        i = 0;
        while (palabra3[i])
        {
            if (isalpha(palabra3[i]))
                i++;
            else
            {
                palabra3[0] = 0;
                printf("Tonto polla, solo letras.\n");
                break;
            }   
        }
    } 
    while (strlen(palabra3) < 2 || strlen(palabra3) > 5);

    system("clear");

    counter += ft_letra_oculta(palabra1, letra_secreta);
    counter += ft_letra_oculta(palabra2, letra_secreta);
    counter += ft_letra_oculta(palabra3, letra_secreta);

    if (counter == 1)
    {
        printf("La letra secreta aparece %d vez en las palabras ingresadas.\n", counter);
        write(1, "\n", 1);
    }
    else
    {
        printf("La letra secreta aparece %d veces en las palabras ingresadas.\n", counter);
        write(1, "\n", 1);
    }
    printf("Ingresa la letra que crees que es la letra secreta: ");
    scanf(" %c", &letra_adivinada);

    if (letra_adivinada == letra_secreta)
    {
        printf("¡Correcto! Has adivinado la letra secreta.\n");
        *letra_hecha = 1;
    }
    else
        printf("Lo siento, no has adivinado la letra secreta, sigue intentándolo.\n");
    write(1, "\n", 1);
    
    free(palabra1);
    free(palabra2);
    free(palabra3);
}

void ft_juego_numero_secreto(int *numero_hecho)
{
    int     numeroSecreto = 17;
    int     intento;
    int     maxIntentos = 5;
    int     i;
    int     index;
    char    *placeholder = malloc(100);

    system("clear");

    printf("¡Bienvenido al juego del Número Secreto!\n");
    printf("Debes adivinar un numero entre 1 y 50.\n");
    printf("Tienes %d intentos para adivinarlo, mucha suerte.\n", maxIntentos);

    for (i = 1; i <= maxIntentos; i++)
    {
        do 
        {
            printf("Intento %d: Ingresa tu adivinanza: ", i);
        
            scanf("%s", placeholder);
            index = 0;
            while (placeholder[index])
            {
                if (isdigit(placeholder[index]))
                    index++;
                else
                {
                    intento = 0;
                    printf("A ver tontito, ¿qué parte de numero positivo no entendiste?\n");
                    break;
                }
                if (!placeholder[index])
                    intento = atoi(placeholder);
            }
        }
        while (intento <= 0);
        if (intento > 50)
        {
            printf("Tiene que ser menor de 50 cara culo.\n");
        } 
            else if (intento < numeroSecreto) 
        {
            printf("El número secreto es mayor que %d.\n", intento);
        } 
        else if (intento > numeroSecreto) 
        {
            printf("El número secreto es menor que %d.\n", intento);
        } 
        else 
        {
            printf("¡Felicidades! Has adivinado el número secreto: %d.\n\n", numeroSecreto);
            *numero_hecho = 1;
            return;
        }
    }
    printf("Lo siento, no has adivinado el número secreto.\n");
    write (1, "\n", 1);
}
int main()
{
    int opcion;
    int letra_hecha = 0;
    int numero_hecho = 0;
    printf("¡Feliz cumpleaños!\n");
    printf("Para poder averiguar el código del candado\n");
    printf("tendrás que superar dos juegos y utilizar la información\n");
    printf("que consigas a tu favor. ¡Espero que lo disfrutes mucho!\n");
    write (1, "\n", 1);

    while (1)
    {
        if (numero_hecho && letra_hecha)
        {
            printf("Has desbloqueado el mensaje oculto, con los datos obtenidos\n");
            printf("debes desbloquear el candado. ¡A darle al coco!\n\n0. El mensaje oculto.\n");
        }
        printf("1. Juego de la letra oculta\n");
        printf("2. Juego del número secreto\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 0:
                if (numero_hecho && letra_hecha)
                {
                    printf("Lo que una el código que no lo separe nadie.\n");
                    printf("Espero que te haya gustado, y hayas pasado un buen rato.\n");
                    printf("Gracias por ser como eres y aportar lo que aportas,\n");
                    printf("eres de esas pocas personas, como te dije un día de nuestras \n");
                    printf("charlas eternas, que merece la pena tener a tu lado, y te hace \n");
                    printf("valorar el sentido de las relaciones sociales puras y sanas. \n");
                    printf("Gracias por escucharme durante horas, y ayudarme durante tantos días.\n");
                    printf("Muchísimas felicidades.\n");
                    exit(0);
                }
                break;
            case 1:
                ft_juego_letra_oculta(&letra_hecha);
                break;
            case 2:
                ft_juego_numero_secreto(&numero_hecho);
                break;
            case 3:
                printf("Gracias por jugar. ¡Hasta luego!\n");
                exit(0);
            
            default:
                printf("Opción inválida. Intenta de nuevo.\n");
        }
    }

    return (0);
}
