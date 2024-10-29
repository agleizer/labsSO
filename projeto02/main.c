#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_FRAME 4096
#define TAMANHO_PAGINA 4096

typedef struct {
    int id;
    bool ocupado;
    int processo_id;
    int pagina_id;
    char *dados;
} frame;  // Frames físicos

typedef struct { //rpensar
    int id;
    bool alterado;
    int processo_id;
    int pagina_id;
    char *dados;
} pagina;  // Frames físicos

typedef struct{
    int pid;
    int *enderecos;
    int num_enderecos;
    int tamanho_processo;
} processo;

typedef struct {
    frame *end_frame;
    pagina *end_pagina;
} linhaTabelaDePaginas;

void inicializarMemoFisica(frame memoriaFisica[], int n){
    frame novoFrame;
    for(int i=0; i<n; i++){
        novoFrame.dados = (char *)malloc(TAMANHO_FRAME * sizeof(char));
        novoFrame.id = i;
        novoFrame.ocupado = false;
        novoFrame.pagina_id = -1;
        novoFrame.processo_id = -1;
        memoriaFisica[i] = novoFrame;
    }
}

void inicializarMemoVirtual(pagina memoriaVirtual[], int n) {
    pagina novaPagina;
    for(int i=0; i<n; i++){
        novaPagina.dados = (char *)malloc(TAMANHO_PAGINA * sizeof(char));
        novaPagina.id = i;
        novaPagina.alterado = false;
        novaPagina.pagina_id = -1;
        novaPagina.processo_id = -1;
        memoriaVirtual[i] = novaPagina;
    }
}

void inicializarTabela(linhaTabelaDePaginas linhas_tabela[], int n){
    linhaTabelaDePaginas novaLinha;
    for (int i = 0; i < n; i++) {
        novaLinha.end_frame = NULL;
        novaLinha.end_pagina = NULL;
        linhas_tabela[i] = novaLinha;
    }
}


void main(){
    int tam_memoriaFisica = 10*sizeof(frame);
    int tam_memoriaVirtual = 25*sizeof(pagina);
    int tam_tabelaPaginas = 100*sizeof(linhaTabelaDePaginas);
    frame memoriaFisica[tam_memoriaFisica];
    pagina memoriaVirtual[tam_memoriaVirtual];


}