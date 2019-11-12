#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forca.c"

void forca(int argc,char  *argv[]){
    NoSecreto * lstSecreta = inicializaListaSecreta();
    char fNameArq[255];
    NoSecreto * sorteada;
    int posSorteada=0;
    int tamanhoLista=0;
    int aux;

    strcpy(fNameArq,"palavras.dat");

    if(argc>1){
      strcpy(fNameArq,argv[1]);
    }

    printf("Arquivo de dados: %s\n\n\n",fNameArq);

    lstSecreta = carregaListaArquivo(lstSecreta,fNameArq);
    imprimeListaSecreta(lstSecreta);
    tamanhoLista = tamanhoListaSecreta(lstSecreta);

    do{
        system("cls");
        sorteada= sorteiaPalavra(lstSecreta);
        if(aux!=NULL){
            int perdeu;
            int tentativas = 0;
            char letra;
            int tamPlv = strlen(sorteada->palavra);
            char pSorteio[31] = " ";
            char viewPlv[tamPlv-1];
            for(int i = 0; i <= tamPlv; i++){
                viewPlv[i] = '_';
            }

            while((strcmp(sorteada->palavra, pSorteio) != 0)){
                system("cls");
                for(int i=0; i < tamPlv; i++){
                    printf("%c", viewPlv[i]);
                }
                printf(" \nA dica e: %s", sorteada->assunto);
                printf("\nDigite uma letra:\n");
                scanf("%c", &letra);
                for(int i=0; i <=tamPlv; i++){
                    if(letra == sorteada->palavra[i]){
                        pSorteio[i] = letra;
                        viewPlv[i] = letra;
                    }
                }

                tentativas++;
                if(tentativas/2 >= tamPlv*3){
                    strcpy(pSorteio, sorteada->palavra);
                    perdeu = 1;
                }else{
                    perdeu = 0;
                }
            }
            system("cls");
            if(perdeu == 1){
                printf("Infelizmente voce perdeu!!! Numero de tentativas: %d\n", tentativas/2);
            }else{
                printf("Parabens voce acertou a palavra!!! Numero de tentativas: %d \n", tentativas/2);
            }

            system("pause");
            aux = NULL;
        }else{
            printf("Fim de jogo! \nPressione a tecla f para poder  sair\n\n");
        }
    }while(getchar()!='f');
}

char config(char nome[]){
    printf("Digite seu nome jogador: \n");
    scanf("%s", nome);

    return nome;

}

void msg(char nome[]){
    system("cls");
    printf("Ate breve, %s \n", nome);
}


int main(int argc, char *argv[])
{
    char nome[25] = "Anonimo";
    int aux=0;
    int escolha;
    do{
        system("cls");
        printf("1.Configuracao\n----------\n2.Jogar\n----------\n0.Sair\n\n");
        scanf("%d", &escolha);
            switch(escolha){
            case 1:
                printf("Digite seu nome jogador: ");
                scanf("%s", nome);
                printf("Nome gravado com sucesso, %s!\n", nome);
                system("pause");
            break;

            case 2:
               forca(argc, argv);
            break;

            case 0:
               msg(nome);
               aux = 1;
            break;

            default:
                printf("Tecla invalida, digite outra!\n");
                system("pause");
            }
    }while(aux==0);
    return 0;
}

