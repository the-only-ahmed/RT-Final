t_vec   init_vec(void)
{
    t_vec vec;

    vec.x = 0;
    vec.y = 0;
    vec.w = 0;
    return (vec);
}

t_vec set_vec(double x, double y, double z)
{
    t_vec vec;

    vec.x = x;
    vec.y = y;
    vec.w = z;
    return (vec);
}

t_vec   set_nvec(t_obj *ret, t_vec dir, t_vec o, double ret2)
{
    if (ret->axe == 'x')
        return set_vec(0, o.y + (dir.y * ret2), dir.w * ret2);
    else if (ret->axe == 'w')
        return set_vec(o.x + (dir.x * ret2), o.y + (dir.y * ret2), 0);
    return set_vec(o.x + (dir.x * ret2), 0, o.w + (dir.w * ret2));
}

int return_i(t_obj *tmp, t_vec dir, t_vec o)
{
    if (tmp->type == SPHERE)
      return hit_sphere(dir, o, tmp);
    else if (tmp->type == PLAN)
      return hit_plane(dir, o, tmp);
    else if (tmp->type == CYLINDRE)
      return hit_cyl(dir, o, tmp);
    else if (tmp->type == CONE)
      return ft_intercone(o, dir, tmp);
    return (-1);
}

t_vec   depth_inf_maxdepth(t_raytracer *ray, int depth, double r_index, int *distance, t_overview over, double refl)
{
    t_vec ret_refl;
    t_vec col2;
    t_vec ret_refl2;

    ret_refl2 = mul_vec(ray->r, EPSILON);
    ret_refl2 = add_vec(ray->pi, ray->r);
    ret_refl = raytracer(over, ray->r, ret_refl2, depth + 1, r_index, distance);
    col2 = mul_vec(ret_refl, refl);
    col2 = multi_vec(col2, ray->ret->col);
    return (add_vec(ray->color, col2));
}

t_vec   dot_positif(t_raytracer *ray)
{
    double diff;
    t_vec t;

    diff = ray->dot * ray->ret->diffuse * ray->shade;
    t = multi_vec(mul_vec(ray->ret->col, diff), ray->tmp->col);
    return add_vec(ray->color, t);
}

void    init_ray(t_raytracer *ray, t_obj *l)
{
    ray = (t_raytracer*)malloc(sizeof(t_raytracer));
    ray->color = init_vec();
    ray->ret = NULL;
    ray->i = -1;
    ray->in = -1;
    ray->ret2 = 0;
    ray->tmp = l;
}

void    first_loop(t_raytracer *ray)
{
    while (ray->tmp)
    {
        ray->i = return_i(ray->tmp, dir, o);
        if (ray->i > 0)
        {
            if (ray->ret)
            {
                if (ray->i > ray->ret2)
                {
                    ray->tmp = ray->tmp->next;
                    continue;
                }
            }
            ray->ret2 = ray->i;
            ray->ret = ray->tmp;
        }
        ray->tmp = ray->tmp->next;
    }
}

void    tmp_type_sphere(t_raytracer *ray)
{
    t_vec l2;
    t_vec o1;
    t_vec d1;
    t_obj *tmp2;
    double tdist;

    l2 = sub_vec(ray->tmp->pos, ray->pi);
    tdist = LENGTH(l2);
    l2 = mul_vec(l2, (1.0f / tdist));
    o1 = mul_vec(l2, EPSILON);
    o1 = add_vec(ray->pi, o1);
    d1 = l2;
    tmp2 = over.l;
    while (tmp2)
    {
        if (tmp2->type != PLAN && tmp2->light == FALSE)
        {
            if (tmp2->type == SPHERE && hit_sphere(d1, o1, tmp2) > 0)
            {
              ray->shade = 0;
              break ;
            }
            else if (tmp2->type == CYLINDRE && hit_cyl(d1, o1, tmp2) > 0)
            {
                ray->shade = 0;
                break ;
            }
            /*else if (tmp2->type == CONE && ft_intercone(o1, d1, tmp2) > 0)
            {
                shade = 0;
                break ;
            }*/
        }
        tmp2 = tmp2->next;
    }
}


void    shade(t_raytracer *ray, t_vec dir)
{
    if (ray->shade > 0)
    {
        ray->l = sub_vec(ray->tmp->pos, ray->pi);
        ray->l = norm(ray->l);
        if (ray->ret->diffuse > 0)
        {
            ray->dot = DOT(ray->n, ray->l);
            if (ray->dot > 0)
                ray->color = dot_positif(ray);
        }
        specular(ray, dir);
    }
}

void    set_nray(t_raytracer *ray)
{
    ray->shade = 1.0f;
    if (ray->tmp->type == SPHERE)
        tmp_type_sphere(ray);
    if (ray->ret->type == SPHERE)
    {
        ray->n = sub_vec(ray->pi, ray->ret->pos);
        ray->n = mul_vec(ray->n, 1.0f / ray->ret->radius);
    }
    else if (ray->ret->type == PLAN)
        ray->n = ray->ret->pos;
    else
        ray->n = set_nvec(ray->ret);
}

void    specular(t_raytracer *ray, t_vec dir)
{
    double r_spect;
    double dot_spec;
    double spect_diff;
    t_vec v_spec;
    t_vec r_spec;
    t_vec ret_spec;

    if (ray->ret->specular > 0)
    {
        r_spect = 2.0f * DOT(ray->l, ray->n);
        r_spec = mul_vec(ray->n, r_spect);
        r_spec = sub_vec(ray->l, r_spec);
        dot_spec = DOT(dir, r_spec);
        if (dot_spec > 0)
        {
            spect_diff = powf(dot_spec, 20) * ray->ret->specular * ray->shade;
            ret_spec = mul_vec(ray->tmp->col, spect_diff);
            ray->color = add_vec(ray->color, ret_spec);
        }
    }
}

void    reflexion(t_raytracer *ray, t_vec dir, t_overview over, int depth)
{
    double ret_dot;
    double refl;

    refl = ray->ret->reflection;
    if (refl > 0.0f)
    {
        ray->n = sub_vec(ray->pi, ray->ret->pos);
        ray->n = mul_vec(ray->n, 1.0f / ray->ret->radius);
        ret_dot = DOT(dir, ray->n) * 2.0f;
        ray->r = mul_vec(ray->n, ret_dot);
        ray->r = sub_vec(dir, ray->r);
        if (depth < MAX_DEPTH)
            ray->color = depth_inf_maxdepth(ray, depth, r_index, distance, over, refl);
    }
}

void    refraction(t_raytracer *ray, t_overview over, t_vec dir, int depth, int *distance, double r_index)
{
    double n_r;
    double cosI;
    double cosT2;
    double t_ref2
    t_vec t_ref;
    t_vec t_ref3;
    t_vec col_ref;
    t_vec n_ref;

    if (ray->ret->refraction > 0 && depth < MAX_DEPTH)
    {
        n_r = r_index / ray->ret->index_refraction;
        n_ref = sub_vec(ray->pi, ray->ret->pos);
        n_ref = mul_vec(n_ref, 1.0f/ ray->ret->radius);
        cosI = -DOT(n_ref, dir);
        cosT2 = 1.0f - n_r * n_r * (1.0f - cosI * cosI);
        if (cosT2 > 0.0f)
        {
            t_ref = mul_vec(dir, n_r);
            t_ref2 = n_r * cosI - sqrtf(cosT2);
            n_ref = mul_vec(n_ref, t_ref2);
            t_ref = add_vec(t_ref, n_ref);
            t_ref3 = mul_vec(t_ref, EPSILON);
            t_ref3 = add_vec(ray->pi, t_ref3);
            col_ref = raytracer(over, t_ref, t_ref3, depth + 1, ray->ret->index_refraction, distance);

            ray->color = add_vec(ray->color, col_ref);
        }
    }
}

t_vec   raytracer(t_overview over, t_vec dir, t_vec o, int depth, double r_index, int *distance)
{
    t_raytracer *ray;

    init_ray(ray);
    first_loop(ray);
    if (!ray->ret)
        return (ray->color);
    *distance = ray->ret2;
    if (ray->ret->light == TRUE)
        return (set_vec(1, 1, 1));
    ray->pi = add_vec(o, mul_vec(dir, ray->ret2));
    ray->tmp = over.l;
    while (ray->tmp)
    {
        if (ray->tmp->light == TRUE)
        {
            set_nray(ray);
            shade(ray, dir);
        }
        ray->tmp = ray->tmp->next;
    }
    reflexion(ray, dir, over, depth);
    refraction(ray, over, dir, depth, distance, r_index);
    return ray->color;
}
