#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct descritor
{
    Pfila inicio;
    int quantidade_elementos;
    Pfila fim;
};

struct fila
{
    Pfila proximo;
    int valor;
};


Pdescritor cria_descritor(void)
{
    Pdescritor x;
    x = (Pdescritor)malloc(sizeof(Tdescritor));

    if(x!=NULL)
    {
        x->fim = NULL;
        x->inicio = NULL;
        x->quantidade_elementos = 0;
    }
    return x;
}

void fila_insere(Pdescritor x, int valor, int posicao)
{

   Pfila novo = (Pfila)malloc(sizeof(Tfila));
   novo->valor = valor;
   int guarda = 0;

   if(x->quantidade_elementos==0)
   {
       x->inicio = novo;
       x->fim = novo;
       novo->proximo = NULL;
       x->quantidade_elementos++;
   }else if(x->quantidade_elementos>0)
   {
        int ps;
       Pfila auxiliar = x->inicio;
       int a = x->quantidade_elementos;
       ps = a-posicao;

       for(int i = 1; i<=ps; i++)
       {
        auxiliar = auxiliar->proximo;
       }


       novo->proximo = auxiliar->proximo;
       auxiliar->proximo = novo;
       Pfila aux = x->inicio;
       for(aux; aux!=NULL; aux=aux->proximo){
       x->fim = aux;
       }

       x->quantidade_elementos++;
   }

     if(posicao>=x->quantidade_elementos){
            guarda = x->inicio->valor;
          x->inicio->proximo->valor = guarda;
            x->inicio->valor = valor;

        }



}

void fila_insere_topo(Pdescritor x, int valor)
{
     Pfila novo = (Pfila)malloc(sizeof(Tfila));
     novo->valor = valor;

     if(x->quantidade_elementos == 0)
     {
         x->inicio = novo;
         x->fim = novo;
         novo->proximo = NULL;
         x->quantidade_elementos++;
     }else{
         x->fim->proximo = novo;
        x->fim = novo;
        x->quantidade_elementos++;
        novo->proximo = NULL;
     }
}



void fila_pop(Pdescritor x, int val)
{
    Pfila anterior = x->inicio;
    Pfila atual = x->inicio;

    while(atual!=NULL)
    {
        if(atual->valor == val)
        {
            atual = lista_delete(x, anterior, atual);
            if(anterior==NULL)
            {
                anterior = atual;
            }
        }else{
            anterior = atual;
            atual = atual->proximo;
        }
    }


}

Pfila lista_delete(Pdescritor x, Pfila anterior, Pfila atual)
{
    if(anterior == atual)
    {
        atual = atual->proximo;
        x->inicio = atual;
        free(anterior);
        anterior = NULL;
        x->quantidade_elementos--;
        if(x->quantidade_elementos == 0)
        {
            x->fim = NULL;
        }
        return atual;

    }else if(atual->proximo == NULL)
    {
        x->fim = anterior;
    }

    anterior->proximo = atual->proximo;
    free(atual);
    x->quantidade_elementos--;
    return anterior->proximo;
}

void fila_exibe(Pdescritor x)
{
    Pfila aux = x->inicio;
    int vetor[x->quantidade_elementos], i, j = 0;

    if(x->inicio == NULL)
    {
        printf("Lista vazia");
    }

    for(i = 0; i<x->quantidade_elementos; i++)
    {
        vetor[i] = aux->valor;
        aux = aux->proximo;

    }

    for(j = x->quantidade_elementos; j>0; j--)
    {

        printf("%d ", vetor[j-1]);
    }

}
void lista_destroi(Pdescritor x)
{

if(x->quantidade_elementos == 1)
{
    free(x->fim);
    x->fim = NULL;
    x->inicio = NULL;
    x->quantidade_elementos--;
}else if(x->quantidade_elementos>1)
{
    Pfila auxiliar = x->inicio;
    while(auxiliar->proximo!= x->fim)
    {
        auxiliar = auxiliar->proximo;
    }

    free(x->fim);
    x->fim = auxiliar;
    x->quantidade_elementos--;
}
}

void lista_destroi2(Pdescritor x)
{
    int num;
    num = x->quantidade_elementos;
    for(int i = 0; i<=num; i++)
    {
        lista_destroi(x);
    }
}

void exibe_maior(Pdescritor x)
{
    int a = 0, c = 0;
    Pfila aux;
    for(aux = x->inicio; aux!=NULL; aux=aux->proximo)
    {
        if(c == 0)
        {
            a = aux->valor;
        }
        if(aux->valor>a)
        {
            a = aux->valor;
        }
       c++;
    }
      printf("%d\n", a);

}

void exibe_ultimo(Pdescritor x, int val)
{
    if(val == 1){
    printf("%d\n", x->inicio->valor);
    }
    if(val == 2){
    printf("%d\n", x->fim->valor);
    }
    if(val == 3)
    {
        printf("%d\n", x->quantidade_elementos);
    }
}

void exibe_maiores(Pdescritor x, int val)
{
    Pfila aux;
    int i =0;
    for(aux = x->inicio; aux!=NULL; aux=aux->proximo)
    {
        if(aux->valor>val)
        {
            i++;
        }
    }
    printf("%d\n", i);
}

void deleta_fila(Pdescritor x)
{
    Pfila aux = x->inicio;
    while(aux!=NULL)
    {
        Pfila aux2 = aux->proximo;
        free(aux);
        aux = aux2;
    }
    free(x);
}




