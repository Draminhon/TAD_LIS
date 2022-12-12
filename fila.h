#ifndef __fila__h
#define __fila__h

typedef struct descritor Tdescritor, *Pdescritor;
typedef struct fila Tfila, *Pfila;

Pdescritor cria_descritor(void);
void fila_insere_topo(Pdescritor x, int valor);
void fila_insere(Pdescritor x, int valor, int posicao);
void fila_pop(Pdescritor x, int posicao);
Pfila lista_delete(Pdescritor x, Pfila anterior, Pfila atual);
void fila_exibe(Pdescritor x);
void lista_destroi(Pdescritor x);
void lista_destroi2(Pdescritor x);
void exibe_maior(Pdescritor x);
void exibe_ultimo(Pdescritor x, int val);
void exibe_maiores(Pdescritor x, int val);
void deleta_fila(Pdescritor x);


#endif // __fila__h
