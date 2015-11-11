#include "rt.h"
t_obj *add_obj(t_obj *l, t_obj *to_add)
{
  t_obj *tmp;

  tmp = l;
  if (!tmp)
    return to_add;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = to_add;
  return l;
}
