#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MIN 1
#define MAX 100000 + MIN

#define Item char

struct Stack
{
  size_t topo;
  size_t size;
  Item * arr;
};

#define Pilha struct Stack

Pilha * create_stack (size_t size)
{
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  if (!p) return NULL;

  p->arr = (Item *) malloc(sizeof(Item) * size);
  if (!p->arr) return NULL;

  p->size = 1;
  p->topo = 0;

  return p;
}

bool stack_isfull (Pilha *p)
{
  return p->size == p->topo;
}

bool stack_add (Pilha *p, Item e)
{
  if (stack_isfull(p)) return false;
  p->size++;
  p->arr[p->topo++] = e;
  return true;
}

Item stack_remove (Pilha *p)
{
  p->size--;
  return p->arr[p->topo-- - 1];
}

Item stack_spy (Pilha *p)
{
  return p->arr[p->topo - 1];
}

bool stack_isempty (Pilha *p)
{
  return p->topo == 0;
}

bool bem_formada (char *string)
{
  Pilha *p = create_stack(strlen(string));
  while (*string)
  {
    switch (*string)
    {
      case '(': case '[': case '{':
        stack_add(p, *string);
      break;
      case ')':
        if (stack_remove(p) != '(')
          return false;
      break;
      case ']':
        if (stack_remove(p) != '[')
          return false;
      break;
      case '}':
        if (stack_remove(p) != '{')
          return false;
      break;
    }
    string++;
  }

  if (!stack_isempty(p))
    return false;

  return true;
}

int main (void)
{
  size_t N;
  scanf("%lu", &N);

  char string[MAX];
  while (N--)
  {
    scanf(" %s", string);
    printf("%c\n", bem_formada(string) ? 'S' : 'N');
  }
}
