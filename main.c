#include "rt.h"
#include <stdio.h> /////

void print_l(t_obj *l)
{
  printf("POS = %f %f %f \n", l->pos.x, l->pos.y, l->pos.w);
  printf("COLOR = %f %f %f \n", l->col.x, l->col.y, l->col.w);
  printf("NAME = %s\n", l->name);
  printf("DIFF = %f\n", l->diffuse);
  printf("REF = %f\n", l->reflection);
  printf("LIGHT = %d\n", l->light);
  printf("RADIUS = %f\n", l->radius);
  printf("\n\n");
}

void print_over(t_overview over)
{
  printf("CAM = %f %f %f \n", over.cam.x, over.cam.y, over.cam.w);
  while (over.l)
  {
    print_l(over.l);
    over.l = over.l->next;
  }
}

int		ft_expose_hook(t_data *e)
{
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img, 0, 0);
	return (0);
}

int		init_main(t_data *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, IMG_H, IMG_W, "RT")) \
	== NULL)
		return (-1);
	data->img = mlx_new_image(data->mlx_ptr, IMG_H, IMG_W);
	data->str = mlx_get_data_addr
		(data->img, &(data->bpp), &(data->sl), &(data->nd));
	return (0);
}

double hit_sphere(t_vec dir, t_vec o, t_obj *obj)
{
  double equation;
  t_vec ret;
  double a;
  double b;
  //printf("LES DIR = %f %f %f\n", dir.x, dir.y, dir.w);
  ret.x = (dir.x * dir.x) + (dir.y * dir.y) + (dir.w *dir.w);
	ret.y = 2 * (dir.x * (o.x - obj->pos.x)
			+ dir.y * (o.y - obj->pos.y)
			+ dir.w * (o.w - obj->pos.w));
	ret.w = ((o.x - obj->pos.x) * (o.x - obj->pos.x)
			+ (o.y - obj->pos.y) * (o.y - obj->pos.y)
			+ (o.w - obj->pos.w) * (o.w - obj->pos.w))
		- (obj->radius * obj->radius);
  equation = ((ret.y) * (ret.y)) - 4 * ret.x * ret.w;
  if (equation < 0)
    return -1;
  if (equation > 0)
  {
    a = (-(ret.y) + sqrtf(equation)) / (2 * ret.x);
    b = (-(ret.y) - sqrtf(equation)) / (2 * ret.x);
    if (a < 0 && b < 0)
      return 0;
    return (a = a < b ? a : b);
  //  printf("ALOOOOORS %d ET %d FUCK %f ET %f EQUATION = %d\n", a, b, ret.x, -ret.y, equation);
  }
  a = (-(ret.y) + sqrtf(equation)) / (2 * ret.x);
  if (a < 0)
    return 0;
  return a;
}

double hit_plane(t_vec dir, t_vec o, t_obj *obj)
{
  double d = DOT(obj->pos, dir);
  if (d != 0)
  {
    double dist = -(DOT(obj->pos, o) + obj->radius) / d;
    if (dist > 0)
    {
      return dist;
    }
  }
  return -1;
}

double hit_cylx(t_vec raydir, t_vec rayorg, t_obj *obj)
{
  double			a;
double			b;
double			c;
double			delt;
double a1;
double b1;
double ret;

a = ft_dotx(raydir, raydir);
b = ft_dotx(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir);
c = ft_dotx(obj->pos, obj->pos) + ft_dotx(rayorg, rayorg) - (2.0 * \
ft_dotx(rayorg, obj->pos)) - (obj->radius);
delt = pow(b, 2) - (4.0 * a * c);
if (delt >= 0)
{
  a1 = ((-1.0 * b) - sqrt(delt)) / (2.0 * a);
  b1 = ((-1.0 * b) + sqrt(delt)) / (2.0 * a);
  if (b1 > a1)
    ret = a1;
  else
    ret = b1;
  if (a1 <= 0 && b1 <= 0)
    return (0);
}
else
  return (0);
return (ret);
}

double hit_cylw(t_vec raydir, t_vec rayorg, t_obj *obj)
{
  double			a;
	double			b;
	double			c;
	double			delt;
  double a1;
  double b1;
  double ret;

	a = ft_dotw(raydir, raydir);
	b = ft_dotw(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir);
	c = ft_dotw(obj->pos, obj->pos) + ft_dotw(rayorg, rayorg) - (2.0 * \
	ft_dotw(rayorg, obj->pos)) - obj->radius;
	delt = pow(b, 2) - (4.0 * a * c);
	if (delt >= 0)
	{
    a1 = ((-1.0 * b) - sqrt(delt)) / (2.0 * a);
    b1 = ((-1.0 * b) + sqrt(delt)) / (2.0 * a);
    if (b1 > a1)
      ret = a1;
    else
      ret = b1;
    if (a1 <= 0 && b1 <= 0)
      return (0);
	}
  else
    return (0);
  return (ret);
}

double hit_cyly(t_vec raydir, t_vec rayorg, t_obj *obj)
{
  double			a;
	double			b;
	double			c;
	double			delt;
  double a1;
  double b1;
  double ret;

	a = ft_doty(raydir, raydir);
	b = ft_doty(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir);
	c = ft_doty(obj->pos, obj->pos) + ft_doty(rayorg, rayorg) - (2.0 * \
	ft_doty(rayorg, obj->pos)) - obj->radius;
	delt = pow(b, 2) - (4.0 * a * c);
	if (delt >= 0)
	{
    a1 = ((-1.0 * b) - sqrt(delt)) / (2.0 * a);
    b1 = ((-1.0 * b) + sqrt(delt)) / (2.0 * a);
    if (b1 > a1)
      ret = a1;
    else
      ret = b1;
    if (a1 <= 0 && b1 <= 0)
      return (0);
	}
  else
    return (0);
  return (ret);
}

double hit_cyl(t_vec dir, t_vec o, t_obj *obj)
{
  if (obj->axe == 'x')
    return hit_cylx(dir, o, obj);
  else if (obj->axe == 'y')
    return hit_cyly(dir, o, obj);
  else
    return hit_cylw(dir, o, obj);
  return -1;
}

int		ft_interconex(t_vec rayorg, t_vec raydir, t_obj *obj)
{
  double		a;
	double		b;
	double		c;
	double		delt;
  double a1;
  double b1;
  double ret;

	a = ft_dotx(raydir, raydir) - obj->radius * (raydir.x * raydir.x);
	b = ft_dotx(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir) \
									- obj->radius * (raydir.x * raydir.x);
	c = ft_dotx(obj->pos, obj->pos) + ft_dotx(rayorg, rayorg) - (2.0 * \
			ft_dotx(rayorg, obj->pos)) - obj->radius * (raydir.x * raydir.x);
	delt = pow(b, 2) - (4.0 * a * c);
	if (delt >= 0)
	{
		a1 = ((-1.0 * b) - sqrt(delt)) / (2.0 * a);
		b1 = ((-1.0 * b) + sqrt(delt)) / (2.0 * a);
    if (b1 > a1)
      ret = a1;
    else
      ret = b1;
    if (a1 <= 0 && b1 <= 0)
      return (0);
	}
  else
    return (0);
  return (ret);
}

int		ft_interconey(t_vec rayorg, t_vec raydir, t_obj *obj)
{
  double		a;
	double		b;
	double		c;
	double		delt;
  double a1;
  double b1;
  double ret;

	a = ft_doty(raydir, raydir) - obj->radius * (raydir.y * raydir.y);
	b = ft_doty(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir) \
									- obj->radius * (raydir.y * raydir.y);
	c = ft_doty(obj->pos, obj->pos) + ft_doty(rayorg, rayorg) - (2.0 * \
			ft_doty(rayorg, obj->pos)) - obj->radius * (raydir.y * raydir.y);
	delt = pow(b, 2) - (4.0 * a * c);
	if (delt >= 0)
	{
		a1 = ((-1.0 * b) - sqrt(delt)) / (2.0 * a);
		b1 = ((-1.0 * b) + sqrt(delt)) / (2.0 * a);
    if (b1 > a1)
      ret = a1;
    else
      ret = b1;
    if (a1 <= 0 && b1 <= 0)
      return (0);
	}
  else
    return (0);
  return (ret);
}

int		ft_interconew(t_vec rayorg, t_vec raydir, t_obj *obj)
{
	double		a;
	double		b;
	double		c;
	double		delt;
  double a1;
  double b1;
  double ret;

	a = ft_dotw(raydir, raydir) - obj->radius * (raydir.w * raydir.w);
	b = ft_dotw(mul_vec(sub_vec(rayorg, obj->pos), 2.0), raydir) \
									- obj->radius * (raydir.w * raydir.w);
	c = ft_dotw(obj->pos, obj->pos) + ft_dotw(rayorg, rayorg) - (2.0 * \
			ft_dotw(rayorg, obj->pos)) - obj->radius * (raydir.w * raydir.w);
	delt = pow(b, 2) - (4.0 * a * c);
	if (delt >= 0)
	{
		a1 = ((-1.0 * b) - sqrt(delt)) / (2.0 * a);
		b1 = ((-1.0 * b) + sqrt(delt)) / (2.0 * a);
    if (b1 > a1)
      ret = a1;
    else
      ret = b1;
    if (a1 <= 0 && b1 <= 0)
      return (0);
	}
  else
    return (0);
  return (ret);
}

int		ft_intercone(t_vec rayorg, t_vec raydir, t_obj *obj)
{
	if (obj->axe == 'w')
		return (ft_interconew(rayorg, raydir, obj));
	if (obj->axe == 'x')
		return (ft_interconex(rayorg, raydir, obj));
	if (obj->axe == 'y')
		return (ft_interconey(rayorg, raydir, obj));
	return (0);
}

t_vec                  rt_rayvec(int x, int y)
{
        t_vec         vec;
        double          dist;

        dist = sqrt(vec.x * vec.x + vec.y * vec.y + vec.w * vec.w);
        vec.x = vec.x / dist;
        vec.y = vec.y / dist;
        vec.w = vec.w / dist;
        return (vec);
}

void setparams(t_rayparams *params, t_overview over, t_vec dir, t_vec o, int *d)
{
  params->over = over;
  params->dir = dir;
  params->o = o;
  params->depth = 1;
  params->r_index = 1.0f;
  params->distance = d;
}

void render(t_data *data, t_overview over)
{
  double m_WX1 = -4, m_WX2 = 4, m_WY1 = 3, m_WY2 = -3;
  double m_SY = 3;
  double m_DX = (m_WX2 - m_WX1) / IMG_H;
  double m_DY = (m_WY2 - m_WY1) / IMG_W;
  double m_SX;
  t_vec o;
  t_vec dir;
  int x = 0;
  int y = 0;
  o.x = over.cam.x;
  o.y = over.cam.y;
  o.w = over.cam.w;
  t_vec viewplane;
  int d;
  int r;
  int g;
  int b;
  t_vec col;

  t_rayparams *params = (t_rayparams*)malloc(sizeof(t_rayparams));

  while (y < IMG_W)
  {
    m_SX = m_WX1;
    x = 0;
    while (x < IMG_H)
    {
      dir.x = m_SX;
      dir.y = m_SY;
      dir.w = 0;
      dir = sub_vec(dir, o);
      dir = norm(dir);
      setparams(params, over, dir, o, &d);
      col = raytracer(params);
      r = (int)(col.x * 256);
      g = (int)(col.y * 256);
      b = (int)(col.w * 256);
      if (r > 255) r = 255;
      if (g > 255) g = 255;
      if (b > 255) b = 255;
      image_pixel_put(data, x, y, creatergb(r, g, b));
      x++;
      m_SX += m_DX;
    }
    m_SY += m_DY;

    y++;
  }
  ft_putendl("FIN");
}

void test(t_data *data)
{
  int i = 0;
  while (i < IMG_W)
  {
    image_pixel_put(data, i, 0, creatergb(156, 88, 88));
    i++;
  }
}

int main(int ac, char **av)
{
  t_data data;
  t_overview over;
  (void)ac;
  init_main(&data);
  over = ft_parser(av[1]);
  print_over(over);
  render(&data, over);
//  test(&data);
  mlx_expose_hook(data.mlx_win, ft_expose_hook, &data);
  mlx_loop(data.mlx_ptr);
  return 0;
}
