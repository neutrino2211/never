#include <stdio.h>
#include <string.h>
#include "libmath.h"

var_list * vars_x()
{
    var_list * vars = NULL;

    vars = var_list_new();
    var_list_add_end(vars, var_new_float(strdup("x")));

    return vars;
}

var_list * vars_x_y()
{
    var_list * vars = NULL;

    vars = var_list_new();
    var_list_add_end(vars, var_new_float(strdup("x")));
    var_list_add_end(vars, var_new_float(strdup("y")));

    return vars;
}

expr_list * params_x()
{
    expr_list * params = NULL;

    params = expr_list_new();
    expr_list_add_end(params, expr_new_id(strdup("x")));

    return params;
}

expr_list * params_x_y()
{
    expr_list * params = NULL;

    params = expr_list_new();
    expr_list_add_end(params, expr_new_id(strdup("x")));
    expr_list_add_end(params, expr_new_id(strdup("y")));

    return params;
}

func * lib_math_func_any_new(const char * name, libmath_func math_id,
                             var_list * vars, expr_list * params)
{
    char * func_id = NULL;
    var * var_ret = NULL;
    expr * func_expr = NULL;
    func_body * body =  NULL;
    func * func_value = NULL;
    
    var_ret = var_new_float(NULL);
        
    func_expr = expr_new_build_in(math_id, params);
    body = func_body_new(NULL, func_expr);
        
    func_id = strdup(name);
    func_value = func_new(func_id, vars, var_ret, body);
    
    return func_value;
}

func * libmath_func_x_new(const char * name, libmath_func math_id)
{
    return lib_math_func_any_new(name, math_id, vars_x(), params_x());
}

func * libmath_func_x_y_new(const char * name, libmath_func math_id)
{
    return lib_math_func_any_new(name, math_id, vars_x_y(), params_x_y());
}

func * libmath_func_sin_new()
{
    return libmath_func_x_new("sin", LIB_MATH_SIN);
}

func * libmath_func_cos_new()
{
    return libmath_func_x_new("cos", LIB_MATH_COS);
}

func * libmath_func_tan_new()
{
    return libmath_func_x_new("tan", LIB_MATH_TAN);
}

func * libmath_func_exp_new()
{
    return libmath_func_x_new("exp", LIB_MATH_EXP);
}

func * libmath_func_log_new()
{
    return libmath_func_x_new("log", LIB_MATH_LOG);
}

func * libmath_func_sqrt_new()
{
    return libmath_func_x_new("sqrt", LIB_MATH_SQRT);
}

func * libmath_func_pow_new()
{
    return libmath_func_x_y_new("pow", LIB_MATH_POW);
}

void libmath_add_funcs(func_list * funcs)
{
    func_list_add_end(funcs, libmath_func_sin_new());
    func_list_add_end(funcs, libmath_func_cos_new());
    func_list_add_end(funcs, libmath_func_tan_new());
    func_list_add_end(funcs, libmath_func_exp_new());
    func_list_add_end(funcs, libmath_func_log_new());
    func_list_add_end(funcs, libmath_func_sqrt_new());
    func_list_add_end(funcs, libmath_func_pow_new());
}


