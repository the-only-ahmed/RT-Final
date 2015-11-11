#include "rt.h"

int count_tab(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    i++;
  return i;
}

void fill_obj(int fd, t_overview *over)
{
  t_obj *obj;
  char *trim;
  char *str;

  obj = (t_obj*)malloc(sizeof(t_obj));
  obj->next = NULL;
  obj->specular = 0;
  while (get_next_line(fd, &str))
  {
    trim = ft_strtrim(str);
    if (!ft_strncmp("name:", trim, 4))
      fill_name(trim, obj);
    else if (!ft_strncmp("diff:", trim, 5))
      fill_diff(trim, obj);
    else if (!ft_strncmp("ref:", trim, 4))
      fill_reflection(trim, obj);
    else if (!ft_strncmp("color:", trim, 6))
      fill_color(trim, obj);
    else if (!ft_strncmp("refraction:", trim, 11))
      fill_refra(trim, obj);
    else if (!ft_strncmp("specular:", trim, 9))
      fill_specular(trim, obj);
    else if (!ft_strncmp("light:", trim, 6))
      fill_light(trim, obj);
    else if (!ft_strncmp("pos:", trim, 4))
      fill_pos(trim, obj);
    else if (!ft_strncmp("axe:", trim, 4))
      fill_axe(trim, obj);
    else if (!ft_strncmp("}", trim, 1))
      break ;
  }
  if (obj->specular)
    obj->specular = 1.0f - obj->diffuse;
  over->l = add_obj(over->l, obj);
}

void fill_cam(t_overview *over, char *trim)
{
  char **tab;

  tab = ft_strsplit(trim, ' ');
  if (count_tab(tab) < 7)
  {
    ft_putendl("Error cam parsing");
    exit(0);
  }
  over->cam.x = ft_atof(tab[1]);
  over->cam.y = ft_atof(tab[2]);
  over->cam.w = ft_atof(tab[3]);
  over->dir.x = ft_atof(tab[4]);
  over->dir.y = ft_atof(tab[5]);
  over->dir.w = ft_atof(tab[6]);
}

void parsing(int fd, t_overview *over)
{
  char *str;
  char *trim;
  while (get_next_line(fd, &str))
  {
    trim = ft_strtrim(str);
    if (!ft_strncmp("}", trim, 1))
      return ;
    if (!ft_strncmp("cam:", trim, 4))
      fill_cam(over, trim);
    else if (!ft_strncmp("obj:", trim, 4))
      fill_obj(fd, over);
  }
}

t_overview ft_parser(char *path)
{
  int fd;
  char *str;
  char *trim;
  t_overview over;

  over.l = NULL;
  fd = open(path, O_RDONLY);
  if (fd == -1)
  {
    ft_putendl("Cannot open file");
    exit(0);
  }
  while (get_next_line(fd, &str))
  {
    trim = ft_strtrim(str);
    if (!ft_strncmp("{", trim, 1))
      parsing(fd, &over);
  }
  return over;
}
