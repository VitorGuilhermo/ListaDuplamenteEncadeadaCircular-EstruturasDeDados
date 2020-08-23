struct TpListaDDECircular{
    char elemento;
    TpListaDDECircular *ant, *prox;
};

TpListaDDECircular *novaCaixa(char elemento){
    TpListaDDECircular *caixa = new TpListaDDECircular;

    caixa->elemento = elemento;
    caixa->prox = NULL;
    caixa->ant = NULL;
    return caixa;
}

TpListaDDECircular *inserir(TpListaDDECircular *head, char elemento){
    TpListaDDECircular *nc, *aux;

    nc = novaCaixa(elemento);

    if(head == NULL){
        head = nc;
    }

    else{
        aux = head;
        while(aux->prox != NULL && aux->prox != head)
            aux = aux->prox;

        nc->ant = aux;
        nc->prox = head;
        aux->prox = nc;

        head->ant = aux->prox;
    }
    return head;
}

TpListaDDECircular *retirar(TpListaDDECircular *head, char elemento){
    TpListaDDECircular *aux1, *aux2;

    if(head != NULL){

        if(head->elemento == elemento){ //elemento ta no comeco
            //faz o ultimo apontar pra nova head
            aux1 = head;
            while(aux1->prox != NULL && aux1->prox != head)
                aux1 = aux1->prox;
            aux1->prox = head->prox;

            aux2 = head;
            head = head->prox;
            head->ant = aux1;
            delete(aux2);
        }
        else if(head->ant->elemento == elemento){   //elemento ta no fim
            aux1 = head;
            while(aux1->prox != NULL && aux1->prox != head)
                aux1 = aux1->prox;

            aux1->ant->prox = head;
            head->ant = aux1->ant;

            delete(aux1);
        }
        else{   //elemento ta no meio
            aux1 = head;
            while(aux1->prox != NULL && aux1->prox != head && elemento != aux1->elemento)
                aux1 = aux1->prox;

            if(aux1->elemento == elemento){
                aux1->ant->prox = aux1->prox;
                aux1->prox->ant = aux1->ant;
                delete(aux1);
            }
        }
    }
    return head;
}

void exibir(TpListaDDECircular *head){
    TpListaDDECircular *aux;

    aux = head;
    while(aux->prox != NULL && aux->prox != head){
        printf("\t %c", aux->elemento);
        aux = aux->prox;
    }
    printf("\t %c", aux->elemento);
}
