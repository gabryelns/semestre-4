#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Person
{
  size_t id;
  size_t state;
  bool in_game;
};

#define Item struct Person
#define Item_NULL (struct Person) {0, false, false}

struct Queue
{
  size_t left;
  size_t size;
  size_t capacity;
  Item *arr;
};

#define Fila struct Queue

Fila *create_queue (size_t capacity)
{
  Fila *f = (Fila*) malloc(sizeof(Fila));
  if (!f) return NULL;

  f->left     = 0;
  f->size     = 0;
  f->capacity = capacity;

  f->arr      = (Item *) malloc(sizeof(Item) * capacity);
  if (!f->arr) return NULL;

  return f;
}

bool queue_isfull (Fila *f)
{
  return f->size == f->capacity;
}

bool queue_isempty (Fila *f)
{
  return f->size == f->left;
}

bool queue_add (Fila *f, Item e)
{
  if (queue_isfull(f)) return false;
  f->arr[f->size++] = e;
  return true;
}

Item queue_take (Fila *f)
{
  if (queue_isempty(f)) return Item_NULL;
  f->size--;
  return f->arr[f->left++];
}

int main (void)
{
  size_t P, R, tests = 0;
  scanf("%lu %lu", &P, &R);
  do
  {
    Fila * f = create_queue(P);
    {
      Item temp = {0, 0, 0};
      while (P--)
      {
        scanf("%lu", &temp.id);
        queue_add(f, temp);
      }
    }

    Item win = {0, 0, false};
    for (size_t i = 0; i < R; i++)
    {
      size_t n, ordem, k = 0;
      scanf("%lu %lu", &n, &ordem);
      while (n--)
      {
        while (f->arr[k].in_game) k++;
        scanf("%lu", &f->arr[k].state);

        if (f->arr[k].state != ordem)
          f->arr[k].in_game = 1;

        else if (i == R - 1)
          win = f->arr[k];

        k++;
      }
    }
    printf("Teste %lu\n%lu\n", ++tests, win.id);

    scanf("%lu %lu", &P, &R);
  } while (R && P);
}
