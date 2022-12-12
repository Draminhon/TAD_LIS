#include <stdio.h>
#include <string.h>
#include "fila.h"

int main()
{
    Pdescritor descritor;
    int posicao = 0, valor = 0;
    char  lixo, escolha[5];

    descritor = cria_descritor();

    do{

        scanf(" %s", escolha);
        if(strcmp(escolha, "-a")==0)
        {
            scanf("%d", &valor);
            lixo = getc(stdin);

            if(lixo == '\n'){

                   fila_insere_topo(descritor, valor);
        }else{
            scanf("%d", &posicao);
           fila_insere(descritor,valor, posicao);
        }
        }

       if(strcmp(escolha, "-s")==0)
        {
            fila_exibe(descritor);
            break;
        }
       if(strcmp(escolha, "-r")==0)
        {

            scanf("%d", &valor);
            fila_pop(descritor, valor);
        }


        if(strcmp(escolha, "-c")==0)
        {
            lista_destroi2(descritor);
        }

        if(strcmp(escolha, "-m")==0)
        {
            exibe_maior(descritor);
        }

        if(strcmp(escolha, "-sl")==0)
        {
            int l = 1;
            exibe_ultimo(descritor, l);
            l = l-1;
        }

        if(strcmp(escolha, "-sf")==0)
        {
            int f = 2;
            exibe_ultimo(descritor, f);
            f = f-2;
        }
         if(strcmp(escolha, "-ss")==0)
        {   int qt = 3;
            exibe_ultimo(descritor, qt);
            qt = qt-3;
        }

        if(strcmp(escolha, "-sg")==0)
        {   int x;
        scanf("%d", &x);
            exibe_maiores(descritor, x);
        }





    }while(escolha!=0);

    deleta_fila(descritor);





    return 0;
}
