// Recebe uma árvore de busca r e
// um número k. Devolve um nó
// cuja chave é k; se tal nó não existe,
// devolve NULL.

noh *
busca (arvore r, int k) {
    if (r == NULL || r->chave == k)
       return r;
    if (r->chave > k)
       return busca (r->esq, k);
    else
       return busca (r->dir, k);
}
