#ifndef RT_H
# define RT_H

# include "libft.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# define TRUE 1
# define FALSE 0
# define IMG_H 1600
# define IMG_W 1400
typedef int BOOL;
# define PI			3.14159265359
# define FOV			(double)30
# define FOV2			FOV / 2
# define SCR_DIST		(p->window.w / 2) / tan(FOV2)
# define DEGTORAD(A)	((A) / 180.0 * PI)
#define DOT(A,B)		(A.x*B.x+A.y*B.y+A.w*B.w)
# define NORMAL(VA) {float l=1/sqrtf(A.x*A.x+A.y*A.y+A.w*A.w);A.x*=l;A.y*=l;A.w*=l;}
# define MAG(VA) ((sqrt(VA.x * VA.x + VA.y * VA.y + VA.w * VA.w)))
# define SPHERE 0
# define PLAN 1
# define CYLINDRE 2
# define CONE 3
# define EPSILON 0.0001f
# define MAX_DEPTH 6
#define LENGTH(A)		(sqrtf(A.x*A.x+A.y*A.y+A.w*A.w))

typedef struct s_vec
{
  double x;
  double y;
  double w;
}     t_vec;

typedef t_vec color;

typedef struct s_obj
{
  char *name;
  t_vec pos;
  BOOL light;
  double diffuse;
  double specular;
  double reflection;
  color col;
  double radius;
  int type;
  char axe;
  struct s_obj *next;
  double refraction;
  double index_refraction;
}     t_obj;

typedef struct s_overview
{
  t_obj *l;
  t_vec cam;
  t_vec dir;
}             t_overview;

typedef struct s_data
{
  void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*str;
	int				bpp;
	int				sl;
	int				nd;
}               t_data;

typedef struct s_plane
{
  int w;
  int h;
  t_vec upleft;
  double incx;
  double incy;
}             t_plane;

typedef struct  s_raytracer
{
    t_obj       *tmp;
    t_obj       *ret;
    t_vec       l;
    t_vec       n;
    t_vec       r;
    t_vec       pi;
    t_vec       color;
    double      i;
    double      mag;
    double      ret2;
    double      dot;
    double      shade;
    int         result;
    int         result2;
    int         hit;
    int         hit2;
    int         in;
}               t_raytracer;

t_overview ft_parser(char *path);
double ft_atof(char *str);
void fill_name(char *s, t_obj *o);
void fill_diff(char *s, t_obj *o);
void fill_reflection(char *s, t_obj *o);
void fill_color(char *s, t_obj *o);
void fill_pos(char *s, t_obj *o);
void fill_light(char *s, t_obj *o);
int count_tab(char **tab);
t_obj *add_obj(t_obj *l, t_obj *to_add);
double ft_pow(double x, double y);
t_vec sub_vec(t_vec a, t_vec b);
t_vec mul_vec(t_vec a, double b);
t_vec add_vec(t_vec a, t_vec b);
t_vec multi_vec(t_vec a, t_vec b);
t_vec norm(t_vec a);
t_vec sub_value(t_vec a, double b);
t_vec add_value(t_vec a, double b);
unsigned long		creatergb(int r, int g, int b);
void				image_pixel_put(t_data *e, int x, int y, int color);
void fill_spe(char *s, t_obj *obj);
void fill_refra(char *s, t_obj *obj);
double		ft_dotw(t_vec v1, t_vec v2);
double		ft_doty(t_vec v1, t_vec v2);
double		ft_dotx(t_vec v1, t_vec v2);
void fill_axe(char *s, t_obj *obj);
void fill_specular(char *s, t_obj *obj);
#endif
