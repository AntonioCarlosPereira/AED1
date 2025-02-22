Node* copiaLista(Node *head) {//4.7.3
    Node *novaLista = NULL;

    while (head != NULL) {
        push(&novaLista, head->dado); // Adiciona no final da nova lista
        head = head->prox;
    }

    return novaLista; // Retorna a nova lista copiada
}


int comp(Node *head1, Node *head2) {//4.7.4
    while (head1 != NULL && head2 != NULL) {
        if (head1->valor != head2->valor) {
            return 0; // Valores diferentes, listas não são iguais
        }
        head1 = head1->prox;
        head2 = head2->prox;
    }

    // Se as listas têm tamanhos diferentes, não são iguais
    return (head1 == NULL && head2 == NULL);
}


Node* encontraPontoMedio(Node *head) {//4.7.7
    if (head == NULL) return NULL;

    Node *rapido = head;
    Node *lento = head;

    // Avança o ponteiro rápido duas células por vez e o ponteiro lento uma célula por vez
    while (rapido != NULL && rapido->prox != NULL) {
        rapido = rapido->prox->prox;  // Avança duas células
        lento = lento->prox;          // Avança uma célula
    }

    return lento;  // O ponteiro lento estará no ponto médio
}

void inverteLista(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->prox; // Salva o próximo nó
        current->prox = prev; // Inverte o ponteiro
        prev = current;       // Avança prev
        current = next;       // Avança current
    }

    *head = prev; // Atualiza a cabeça da lista
}

void insereKEsimo(Node **head, int k, int x) {
    Node *novoNo = malloc(sizeof(Node));
    if (novoNo == NULL) return; // Se a alocação falhar
    
    novoNo->dado = x;  // Atribui o valor ao novo nó
    novoNo->prox = NULL;

    if (*head == NULL || k == 0) { // Se a lista está vazia ou inserção na cabeça
        novoNo->prox = *head;
        *head = novoNo;
        return;
    }

    Node *aux = *head;
    // Percorre até o k-ésimo nó
    for (int i = 0; aux != NULL && i < k - 1; i++) {
        aux = aux->prox;
    }

    if (aux == NULL) return; // Se k for maior que o número de elementos

    novoNo->prox = aux->prox; // O novo nó aponta para o próximo da posição k
    aux->prox = novoNo;       // O nó anterior aponta para o novo nó
}

void removeKEsima(Node **head, int k) {
    if (*head == NULL) return; // Lista vazia

    Node *aux = *head;
    
    // Se k for 0, remove o primeiro nó
    if (k == 0) {
        *head = aux->prox; // Atualiza a cabeça da lista
        free(aux); // Libera o nó removido
        return;
    }
    
    // Percorre até o k-ésimo nó
    for (int i = 0; aux != NULL && i < k - 1; i++) {
        aux = aux->prox;
    }

    // Se o nó a ser removido existe
    if (aux == NULL || aux->prox == NULL) return;

    Node *temp = aux->prox;  // Nó a ser removido
    aux->prox = aux->prox->prox; // Ajusta o ponteiro
    free(temp); // Libera o nó removido
}
