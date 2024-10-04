/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HappyBirthday.c                              :+:      :+:    :+:   */
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

int     ft_counter_letter(char *str, char secret_letter);
void    ft_hidden_letter(int *correct_letter);
void    ft_hidden_number(int *correct_number);

int ft_counter_letter(char *str, char secret_letter)
{
    int i;
    int counter = 0;

    for (i = 0; i < strlen(str); i++) 
    {
        if (str[i] == secret_letter) 
        {
            counter++;
        }
    }
    return counter;
}

void ft_hidden_letter(int *correct_letter)
{
    char    secret_letter = 'r';
    char    guessed_letter;
    char    *word1;
    char    *word2;
    char    *word3;
    int     i;

    int counter = 0;
    word1 = malloc(100 * sizeof(char));
    word2 = malloc(100 * sizeof(char));
    word3 = malloc(100 * sizeof(char));

    system("clear");

    if (word1 == NULL || word2 == NULL || word3 == NULL) 
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
        scanf("%s", word1);
        i = 0;
        while (word1[i])
        {
            if (isalpha(word1[i]))
                i++;
            else
            {
                word1[0] = 0;
                printf("Tonto polla, solo letras.\n");
                break;
            }     
        }
    }
    while (strlen(word1) < 2 || strlen(word1) > 5);
    do 
    {
        printf("Ingresa la segunda palabra (2-5 letras): ");
        scanf("%s", word2);
        i = 0;
        while (word2[i])
        {
            if (isalpha(word2[i]))
                i++;
            else
            {
                word2[0] = 0; 
                printf("Tonto polla, solo letras.\n");
                break;
            }
        }
    } 
    while (strlen(word2) < 2 || strlen(word2) > 5);
    do 
    {
        printf("Ingresa la tercera palabra (2-5 letras): ");
        scanf("%s", word3);
        i = 0;
        while (word3[i])
        {
            if (isalpha(word3[i]))
                i++;
            else
            {
                word3[0] = 0;
                printf("Tonto polla, solo letras.\n");
                break;
            }   
        }
    } 
    while (strlen(word3) < 2 || strlen(word3) > 5);

    system("clear");

    counter += ft_counter_letter(word1, secret_letter);
    counter += ft_counter_letter(word2, secret_letter);
    counter += ft_counter_letter(word3, secret_letter);

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
    scanf(" %c", &guessed_letter);

    if (guessed_letter == secret_letter)
    {
        printf("¡Correcto! Has adivinado la letra secreta.\n");
        *correct_letter = 1;
    }
    else
        printf("Lo siento, no has adivinado la letra secreta, sigue intentándolo.\n");
    write(1, "\n", 1);
    
    free(word1);
    free(word2);
    free(word3);
}

void ft_hidden_number(int *correct_number)
{
    int     secret_number;
    int     attempt;
    int     max_attempts;
    int     i;
    int     index;
    char    placeholder[100];

    secret_number = 17;
    max_attempts = 5;

    system("clear");

    printf("¡Bienvenido al juego del Número Secreto!\n");
    printf("Debes adivinar un numero entre 1 y 50.\n");
    printf("Tienes %d attempts para adivinarlo, mucha suerte.\n", max_attempts);

    for (i = 1; i <= max_attempts; i++)
    {
        do 
        {
            printf("attempt %d: Ingresa tu adivinanza: ", i);
        
            scanf("%s", placeholder);
            index = 0;
            while (placeholder[index])
            {
                if (isdigit(placeholder[index]))
                    index++;
                else
                {
                    attempt = 0;
                    printf("A ver tontito, ¿qué parte de numero positivo no entendiste?\n");
                    break;
                }
                if (!placeholder[index])
                    attempt = atoi(placeholder);
            }
        }
        while (attempt <= 0);
        if (attempt > 50)
        {
            printf("Tiene que ser menor de 50 cara culo.\n");
        } 
            else if (attempt < secret_number) 
        {
            printf("El número secreto es mayor que %d.\n", attempt);
        } 
        else if (attempt > secret_number) 
        {
            printf("El número secreto es menor que %d.\n", attempt);
        } 
        else 
        {
            printf("¡Felicidades! Has adivinado el número secreto: %d.\n\n", secret_number);
            *correct_number = 1;
            return;
        }
    }
    printf("Lo siento, no has adivinado el número secreto.\n");
    write (1, "\n", 1);
}
int main()
{
    int option;
    int correct_letter;
    int correct_number;

    correct_letter = 0;
    correct_number = 0;

    printf("¡Feliz cumpleaños!\n");
    printf("Para poder averiguar el código del candado\n");
    printf("tendrás que superar dos juegos y utilizar la información\n");
    printf("que consigas a tu favor. ¡Espero que lo disfrutes mucho!\n");
    write (1, "\n", 1);

    while (1)
    {
        if (correct_number && correct_letter)
        {
            printf("Has desbloqueado el mensaje oculto, con los datos obtenidos\n");
            printf("debes desbloquear el candado. ¡A darle al coco!\n\n0. El mensaje oculto.\n");
        }
        printf("1. Juego de la letra oculta\n");
        printf("2. Juego del número secreto\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &option);

        switch (option)
        {
            case 0:
                if (correct_number && correct_letter)
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
                ft_hidden_letter(&correct_letter);
                break;
            case 2:
                ft_hidden_number(&correct_number);
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
