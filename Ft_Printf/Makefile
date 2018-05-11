# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpitic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 15:59:19 by bpitic            #+#    #+#              #
#    Updated: 2018/03/29 15:59:33 by bpitic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = cases1.c cases2.c cases3.c cases4.c cases5.c cases6.c flags_bigs.c \
	   flags_bigx.c flags_c.c flags_d_i.c flags_h_d_i.c flags_h_o.c \
	   flags_h_u.c flags_h_x.c flags_hh_d_i.c flags_hh_o.c flags_hh_x.c \
	   flags_j_d.c flags_j_o.c flags_j_u.c flags_j_x.c flags_ll_d_i.c \
	   flags_ll_o.c flags_ll_u.c flags_ll_x.c flags_o.c flags_p.c \
	   flags_s.c flags_u.c flags_x.c ft_printf.c noflags.c noflags2.c \
	   noflags3.c noflags4.c noflags5.c noflags6.c params.c utilities.c \
	   utilities2.c utilities3.c utilities4.c utilities5.c

FLAGS = -Wall -Werror -Wextra

OBJ = cases1.o cases2.o cases3.o cases4.o cases5.o cases6.o flags_bigs.o \
	  flags_bigx.o flags_c.o flags_d_i.o flags_h_d_i.o flags_h_o.o \
	  flags_h_u.o flags_h_x.o flags_hh_d_i.o flags_hh_o.o flags_hh_x.o \
	  flags_j_d.o flags_j_o.o flags_j_u.o flags_j_x.o flags_ll_d_i.o \
	  flags_ll_o.o flags_ll_u.o flags_ll_x.o flags_o.o flags_p.o \
	  flags_s.o flags_u.o flags_x.o ft_printf.o noflags.o noflags2.o \
	  noflags3.o noflags4.o noflags5.o noflags6.o params.o utilities.o \
	  utilities2.o utilities3.o utilities4.o utilities5.o


INC = ft_printf.h

all : $(NAME)

$(NAME) :
	make -C libft
	cp libft/libft.a $(NAME)
	gcc $(FLAGS) -I $(INC) -c $(SRCS)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	/bin/rm -f libft.a

re: fclean all
