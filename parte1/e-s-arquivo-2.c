#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *pf;
    float pi = 3.1415;
    float pilido;
    if ((pf = fopen("arquivo.txt", "wb")) == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    if (fwrite(&pi, sizeof(float), 1, pf) != 1) /* Escreve a variável pi */
        printf("Erro na escrita do arquivo");
    fclose(pf);                                    /* Fecha o arquivo */
    if ((pf = fopen("arquivo.bin", "rb")) == NULL) /* Abre o arquivo novamente para leitura */
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    if (fread(&pilido, sizeof(float), 1, pf) != 1) /* Le em pilido o valor da variável armazenada anteriormente */
        printf("Erro na leitura do arquivo");
    printf("\nO valor de PI, lido do arquivo e': %f", pilido);
    fclose(pf);
    return 0;
}