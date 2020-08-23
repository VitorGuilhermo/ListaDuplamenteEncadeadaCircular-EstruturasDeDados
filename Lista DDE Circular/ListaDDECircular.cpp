#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "TADListaDDECircular.h"

int main(){
    TpListaDDECircular *head = NULL;

    head = inserir(head, 'A');
    head = inserir(head, 'B');
    head = inserir(head, 'C');
    head = inserir(head, 'D');

    //printf("%c", head->ant->elemento);

    head = retirar(head, 'A');

    exibir(head);
}
