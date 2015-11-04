/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:21:57 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:46:33 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <time.h>

typedef	struct	s_specificateurs
{
	char	flags;
	int		largeur;
	int		precision;
	char	modif;
}				t_specs;
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putstr(char const *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isspace(int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
char			*ft_ltoa(long int n);
char			*ft_itoa(int n);
char			*convertion_base(int base, unsigned long long int nb,
		char *temp, int s);
wchar_t			*ft_wstrdup(wchar_t *s1);
size_t			ft_wstrlen(wchar_t *str);
int				ft_printf(char const *format, ...);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_wputstr(wchar_t *s);
void			ft_wputchar(wchar_t c);
wchar_t			*ft_wstrjoin(wchar_t *s1, wchar_t *s2);
wchar_t			*wtrt_opt(wchar_t *wstr, t_specs opt, char c, int z);
wchar_t			*wtreat_flag_space(wchar_t *wstr, t_specs opt);
wchar_t			*wtreat_flag_plus(wchar_t *wstr, t_specs opt);
wchar_t			*wtreat_largeur(wchar_t *wstr, t_specs opt, int z);
char			*ft_strrjoin(char *s1, char *s2, int pos);
int				verif_str(char *str, char c);
char			*ft_strminijoin(char const *s1, char c);
void			check_flags(const char *format, int *i, char *c);
void			check_modificator(const char *format, int *i, char *c);
void			check_modificator1(const char *format, int *i, char *c);
void			check_modificator2(const char *format, int *i, char *c);
t_specs			init_structure(t_specs opt);
int				check_larg(va_list ap, const char *format, int *i, char *flags);
int				check_precision(va_list ap, const char *format, int *i);
wchar_t			*ft_wstrncpy(wchar_t *dst, wchar_t *src, size_t n);
t_specs			check_options(va_list ap, const char *format, int *i);
wchar_t			*wtreat_largeur(wchar_t *wstr, t_specs opt, int z);
wchar_t			*wtreat_largeur2(wchar_t *wstr, t_specs opt, int z);
wchar_t			*wtreat_larg3(wchar_t *wstr, t_specs opt, int octal, int neg);
wchar_t			*ft_wstrnew(size_t size);
wchar_t			*ft_wstrsub(wchar_t *s, unsigned int start, size_t len);
int				*init_tab(void);
int				*asign_tab(int *tab, t_specs opt, char *str);
char			*treat_flag_plus(char *str, t_specs opt, char c);
char			*treat_largeur2(char *str, t_specs opt, char c, int *tab);
char			*treat_largeur3(char *str, t_specs opt, int *tab);
char			*treat_largeur(char *str, t_specs opt, char c, int z);
char			*treat_flag_space(char *str, t_specs opt, char c);
wchar_t			*wtreat_precision(wchar_t *wstr, t_specs opt, char c);
wchar_t			*wtrt_opt(wchar_t *wstr, t_specs opt, char c, int z);
char			*treat_precision1(char *str, t_specs opt, char c, int *tab);
char			*treat_precision2(char *str, t_specs opt, char c, int **tab);
char			*treat_precision(char *str, t_specs opt, char c);
char			*treat_options(char *str, t_specs opt, char c, int z);
char			*treat_conv_o(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_big_o(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_u(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_x(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_big_x(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_p(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_big_d(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_d(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_g(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_e(va_list ap, t_specs opt, char *c, int *i);
char			*treat_colours(char *c, int *i);
char			*treat_colours2(char *c, char *color, int *i);
int				verif_colour(char *c, int i);
void			treat_n(va_list ap, int *i, int len);
char			*treat_conv_b(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_k(va_list ap);
char			*treat_conv_q(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_t(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_big_q(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_f(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_s(va_list ap, t_specs opt, char *c, int *i);
wchar_t			*treat_conv_big_s(va_list ap, t_specs opt, char *c, int *i);
char			*treat_conv_pourcent(t_specs opt, char *c, int *i);
char			*treat_else(t_specs opt, char *c, int *i);
char			*ft_option_c(va_list ap);
int				opt2(t_specs opt, char *c, int *i, char **str);
wchar_t			*ft_option_big_c(va_list ap);
int				ft_option_big_c2(t_specs opt, char *c, int *i, wchar_t **wstr);
void			split_if(char *str, int **i);
int				split_if2(wchar_t **wstr, int *i);
char			*treat_convs(va_list ap, t_specs opt, char *c, int *i);
char			*treat_convs2(va_list ap, t_specs opt, char *c, int *i);
char			*treat_convs3(va_list ap, t_specs opt, char *c, int *i);

#endif
