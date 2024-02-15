#include <stdio.h>
#include <stdlib.h>

#define Item size_t
#define Lista struct Node
#define Fila struct Queue

Lista
{
  Item dado;
  Lista *prox;
};

Fila
{
  Lista *ini;
  Lista *fim;
};


Fila *inicializa (void)
{
  Fila *f = (Fila*) malloc(sizeof(Fila));

  f->ini = NULL;
  f->fim = NULL;

  return f;
}

void enfileira (Fila *p, Item e)
{
  Lista *novo = (Lista *) malloc(sizeof(Lista));

  novo->dado = e;
  novo->prox = NULL;

  if (!p->ini)
    p->ini = p->fim = novo;
  else
    p->fim = p->fim->prox = novo;
}

Item desenfileira (Fila *p)
{
  Lista *l = p->ini;
  Item temp = l->dado;

  p->ini = l->prox;

  if (!p->ini) p->fim = NULL;

  free(l);
  return temp;
}

int main (void)
{
  size_t n;
  Fila *f;

  f = inicializa();

  scanf("%lu", &n);

  for (size_t i = 1; i <= n; i++)
    enfileira(f, i);

  printf("Cartas descartadas:");

  while (n != 1)
  {
    printf(" %lu", desenfileira(f));
    enfileira(f, desenfileira(f));

    if (n != 2) putchar(',');

    n--;
  }

  if (f->ini)
    printf("\nCarta restante: %lu\n", desenfileira(f));
}

