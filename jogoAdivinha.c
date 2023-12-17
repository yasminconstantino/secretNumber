#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int gerarNumeroAleatorio(int min, int max);

int validarPalpite(int palpite, int numeroSecreto);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    int numeroSecreto = gerarNumeroAleatorio(1, 100);
    int tentativas = 0;
    int palpite, resultado;

    printf("Bem-vindo ao Jogo de Adivinha��o! Tente adivinhar o n�mero entre 1 e 100 em no m�ximo 10 tentativas.\n");

    do
    {
        printf("Tentativa %d: Digite seu palpite: ", tentativas + 1);
        scanf("%d", &palpite);

        // Verifica se o palpite est� dentro da faixa permitida
        if (palpite < 0 || palpite > 100)
        {
            printf("Invalido, o numero deve estar entre 0 e 100. Tente novamente.\n");
            continue; // Volta para o in�cio do loop sem contar como tentativa
        }

        resultado = validarPalpite(palpite, numeroSecreto);

        if (resultado == -1)
        {
            printf("Seu palpite est� muito baixo. Tente novamente.\n");
        }
        else if (resultado == 1)
        {
            printf("Seu palpite est� muito alto. Tente novamente.\n");
        }

        tentativas++;

        // Verifica se o jogador atingiu o limite de 10 tentativas
        if (tentativas == 10)
        {
            printf("\N�o foi dessa vez. O n�mero secreto era: %d\n", numeroSecreto);
            return 0;
        }

    } while (resultado != 0);

    printf("\nParab�ns! Voc� acertou o n�mero %d em %d tentativas.\n", numeroSecreto, tentativas);

    return 0;
}

// Fun��o para gerar um n�mero aleat�rio entre min e max
int gerarNumeroAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Fun��o para validar o palpite do jogador
int validarPalpite(int palpite, int numeroSecreto)
{
    if (palpite < numeroSecreto)
    {
        return -1; // Palpite muito baixo
    }
    else if (palpite > numeroSecreto)
    {
        return 1; // Palpite muito alto
    }
    else
    {
        return 0; // Palpite correto
    }
}
