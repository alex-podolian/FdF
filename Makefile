# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opodolia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 13:55:22 by opodolia          #+#    #+#              #
#    Updated: 2017/03/17 19:20:25 by opodolia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAMEBASE = libftprintf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(OBJ1) $(OBJ2)

OBJ1 = libft/ft_atoi.o libft/ft_bzero.o libft/ft_isalnum.o libft/ft_isalpha.o \
	   libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o \
	   libft/ft_itoa.o libft/ft_lstadd.o libft/ft_lstdel.o \
	   libft/ft_lstdelone.o libft/ft_lstiter.o libft/ft_lstmap.o \
	   libft/ft_lstnew.o libft/ft_sqrt.o libft/ft_lstsize.o \
	   libft/ft_memalloc.o libft/ft_memccpy.o libft/ft_memchr.o \
	   libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memdel.o \
	   libft/ft_memmove.o libft/ft_memset.o libft/ft_putchar.o \
	   libft/ft_putchar_fd.o libft/ft_putendl.o libft/ft_putendl_fd.o \
	   libft/ft_putnbr.o libft/ft_putnbr_fd.o libft/ft_putstr.o \
	   libft/ft_putstr_fd.o libft/ft_quicksort.o libft/ft_strcat.o \
	   libft/ft_strchr.o libft/ft_strclr.o libft/ft_strcmp.o \
	   libft/ft_strcpy.o libft/ft_strdel.o libft/ft_strdup.o \
	   libft/ft_strequ.o libft/ft_striter.o libft/ft_striteri.o \
	   libft/ft_strjoin.o libft/ft_strlcat.o libft/ft_strlen.o \
	   libft/ft_strmap.o libft/ft_strmapi.o libft/ft_strncat.o \
	   libft/ft_strncmp.o libft/ft_strncpy.o libft/ft_strnequ.o \
	   libft/ft_strnew.o libft/ft_strnstr.o libft/ft_strrchr.o \
	   libft/ft_strsplit.o libft/ft_strstr.o libft/ft_strsub.o \
	   libft/ft_strtrim.o libft/ft_swap.o libft/ft_tolower.o \
	   libft/ft_toupper.o libft/ft_uitoa_base.o libft/ft_strnlen.o \
	   libft/ft_wclen.o libft/ft_wcslen.o libft/ft_wcstombs.o \
	   libft/ft_wctomb.o libft/ft_ld_intpower.o libft/ft_strjoin_free.o \
	   libft/ft_ftoa_base.o libft/ft_strrev.o libft/get_next_line.o \
	   libft/ft_words_count.o libft/ft_lstcount.o libft/ft_lstrev.o

OBJ2 = src_printf/ft_printf.o src_printf/ft_char.o src_printf/ft_convert.o \
	   src_printf/ft_str.o src_printf/ft_is_mb.o src_printf/ft_flags.o \
	   src_printf/ft_length.o src_printf/ft_numb.o src_printf/ft_no_qual.o \
	   src_printf/ft_precision.o src_printf/ft_qualifier.o \
	   src_printf/ft_push.o src_printf/ft_size.o src_printf/ft_width.o \
	   src_printf/ft_float.o src_printf/ft_ftoa_handler.o \
	   src_printf/ft_get_mantissa.o src_printf/ft_put.o \
	   src_printf/ft_unprint.o src_printf/ft_quote_mark.o

.SILENT:

all : $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME) : $(OBJECTS)
	printf "\r\033[38;5;11m⌛  MAKE $(NAMEBASE) please wait ...\033[0m\033[K"
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	echo -en "\r\033[38;5;22m☑️  MAKE $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat author | sed s/^/\ \ \ \ /g`\033[0m\033[K"

clean :
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(OBJECTS)
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAMEBASE) is done\033[0m\033[K"

fclean : clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(NAME)
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAMEBASE) is done\033[0m\033[K"

re : fclean all

.PHONY: fclean clean re

libft/ft_atoi.o : libft/ft_atoi.c
	$(CC) $(CFLAGS) -c libft/ft_atoi.c -o libft/ft_atoi.o

libft/ft_bzero.o : libft/ft_bzero.c
	$(CC) $(CFLAGS) -c libft/ft_bzero.c -o libft/ft_bzero.o

libft/ft_isalnum.o : libft/ft_isalnum.c
	$(CC) $(CFLAGS) -c libft/ft_isalnum.c -o libft/ft_isalnum.o

libft/ft_isalpha.o : libft/ft_isalpha.c
	$(CC) $(CFLAGS) -c libft/ft_isalpha.c -o libft/ft_isalpha.o

libft/ft_isascii.o : libft/ft_isascii.c
	$(CC) $(CFLAGS) -c libft/ft_isascii.c -o libft/ft_isascii.o

libft/ft_isdigit.o : libft/ft_isdigit.c
	$(CC) $(CFLAGS) -c libft/ft_isdigit.c -o libft/ft_isdigit.o

libft/ft_isprint.o : libft/ft_isprint.c
	$(CC) $(CFLAGS) -c libft/ft_isprint.c -o libft/ft_isprint.o

libft/ft_itoa.o : libft/ft_itoa.c
	$(CC) $(CFLAGS) -c libft/ft_itoa.c -o libft/ft_itoa.o

libft/ft_uitoa_base.o : libft/ft_uitoa_base.c
	$(CC) $(CFLAGS) -c libft/ft_uitoa_base.c -o libft/ft_uitoa_base.o

libft/ft_lstadd.o : libft/ft_lstadd.c
	$(CC) $(CFLAGS) -c libft/ft_lstadd.c -o libft/ft_lstadd.o

libft/ft_lstdel.o : libft/ft_lstdel.c
	$(CC) $(CFLAGS) -c libft/ft_lstdel.c -o libft/ft_lstdel.o

libft/ft_lstdelone.o : libft/ft_lstdelone.c
	$(CC) $(CFLAGS) -c libft/ft_lstdelone.c -o libft/ft_lstdelone.o

libft/ft_lstiter.o : libft/ft_lstiter.c
	$(CC) $(CFLAGS) -c libft/ft_lstiter.c -o libft/ft_lstiter.o

libft/ft_lstmap.o : libft/ft_lstmap.c
	$(CC) $(CFLAGS) -c libft/ft_lstmap.c -o libft/ft_lstmap.o

libft/ft_lstnew.o : libft/ft_lstnew.c
	$(CC) $(CFLAGS) -c libft/ft_lstnew.c -o libft/ft_lstnew.o

libft/ft_sqrt.o : libft/ft_sqrt.c
	$(CC) $(CFLAGS) -c libft/ft_sqrt.c -o libft/ft_sqrt.o

libft/ft_lstsize.o : libft/ft_lstsize.c
	$(CC) $(CFLAGS) -c libft/ft_lstsize.c -o libft/ft_lstsize.o

libft/ft_memalloc.o : libft/ft_memalloc.c
	$(CC) $(CFLAGS) -c libft/ft_memalloc.c -o libft/ft_memalloc.o

libft/ft_memccpy.o : libft/ft_memccpy.c
	$(CC) $(CFLAGS) -c libft/ft_memccpy.c -o libft/ft_memccpy.o

libft/ft_memchr.o : libft/ft_memchr.c
	$(CC) $(CFLAGS) -c libft/ft_memchr.c -o libft/ft_memchr.o

libft/ft_memcmp.o : libft/ft_memcmp.c
	$(CC) $(CFLAGS) -c libft/ft_memcmp.c -o libft/ft_memcmp.o

libft/ft_memcpy.o : libft/ft_memcpy.c
	$(CC) $(CFLAGS) -c libft/ft_memcpy.c -o libft/ft_memcpy.o

libft/ft_memdel.o : libft/ft_memdel.c
	$(CC) $(CFLAGS) -c libft/ft_memdel.c -o libft/ft_memdel.o

libft/ft_memmove.o : libft/ft_memmove.c
	$(CC) $(CFLAGS) -c libft/ft_memmove.c -o libft/ft_memmove.o

libft/ft_memset.o : libft/ft_memset.c
	$(CC) $(CFLAGS) -c libft/ft_memset.c -o libft/ft_memset.o

libft/ft_putchar.o : libft/ft_putchar.c
	$(CC) $(CFLAGS) -c libft/ft_putchar.c -o libft/ft_putchar.o

libft/ft_putchar_fd.o : libft/ft_putchar_fd.c
	$(CC) $(CFLAGS) -c libft/ft_putchar_fd.c -o libft/ft_putchar_fd.o

libft/ft_putendl.o : libft/ft_putendl.c
	$(CC) $(CFLAGS) -c libft/ft_putendl.c -o libft/ft_putendl.o

libft/ft_putendl_fd.o : libft/ft_putendl_fd.c
	$(CC) $(CFLAGS) -c libft/ft_putendl_fd.c -o libft/ft_putendl_fd.o

libft/ft_putnbr.o : libft/ft_putnbr.c
	$(CC) $(CFLAGS) -c libft/ft_putnbr.c -o libft/ft_putnbr.o

libft/ft_putnbr_fd.o : libft/ft_putnbr_fd.c
	$(CC) $(CFLAGS) -c libft/ft_putnbr_fd.c -o libft/ft_putnbr_fd.o

libft/ft_putstr.o : libft/ft_putstr.c
	$(CC) $(CFLAGS) -c libft/ft_putstr.c -o libft/ft_putstr.o

libft/ft_putstr_fd.o : libft/ft_putstr_fd.c
	$(CC) $(CFLAGS) -c libft/ft_putstr_fd.c -o libft/ft_putstr_fd.o

libft/ft_quicksort.o : libft/ft_quicksort.c
	$(CC) $(CFLAGS) -c libft/ft_quicksort.c -o libft/ft_quicksort.o

libft/ft_strcat.o : libft/ft_strcat.c
	$(CC) $(CFLAGS) -c libft/ft_strcat.c -o libft/ft_strcat.o

libft/ft_strchr.o : libft/ft_strchr.c
	$(CC) $(CFLAGS) -c libft/ft_strchr.c -o libft/ft_strchr.o

libft/ft_strclr.o : libft/ft_strclr.c
	$(CC) $(CFLAGS) -c libft/ft_strclr.c -o libft/ft_strclr.o

libft/ft_strcmp.o : libft/ft_strcmp.c
	$(CC) $(CFLAGS) -c libft/ft_strcmp.c -o libft/ft_strcmp.o

libft/ft_strcpy.o : libft/ft_strcpy.c
	$(CC) $(CFLAGS) -c libft/ft_strcpy.c -o libft/ft_strcpy.o

libft/ft_strdel.o : libft/ft_strdel.c
	$(CC) $(CFLAGS) -c libft/ft_strdel.c -o libft/ft_strdel.o

libft/ft_strdup.o : libft/ft_strdup.c
	$(CC) $(CFLAGS) -c libft/ft_strdup.c -o libft/ft_strdup.o

libft/ft_strequ.o : libft/ft_strequ.c
	$(CC) $(CFLAGS) -c libft/ft_strequ.c -o libft/ft_strequ.o

libft/ft_striter.o : libft/ft_striter.c
	$(CC) $(CFLAGS) -c libft/ft_striter.c -o libft/ft_striter.o

libft/ft_striteri.o : libft/ft_striteri.c
	$(CC) $(CFLAGS) -c libft/ft_striteri.c -o libft/ft_striteri.o

libft/ft_strjoin.o : libft/ft_strjoin.c
	$(CC) $(CFLAGS) -c libft/ft_strjoin.c -o libft/ft_strjoin.o

libft/ft_strlcat.o : libft/ft_strlcat.c
	$(CC) $(CFLAGS) -c libft/ft_strlcat.c -o libft/ft_strlcat.o

libft/ft_strlen.o : libft/ft_strlen.c
	$(CC) $(CFLAGS) -c libft/ft_strlen.c -o libft/ft_strlen.o

libft/ft_strnlen.o : libft/ft_strnlen.c
	$(CC) $(CFLAGS) -c libft/ft_strnlen.c -o libft/ft_strnlen.o

libft/ft_strmap.o : libft/ft_strmap.c
	$(CC) $(CFLAGS) -c libft/ft_strmap.c -o libft/ft_strmap.o

libft/ft_strmapi.o : libft/ft_strmapi.c
	$(CC) $(CFLAGS) -c libft/ft_strmapi.c -o libft/ft_strmapi.o

libft/ft_strncat.o : libft/ft_strncat.c
	$(CC) $(CFLAGS) -c libft/ft_strncat.c -o libft/ft_strncat.o

libft/ft_strncmp.o : libft/ft_strncmp.c
	$(CC) $(CFLAGS) -c libft/ft_strncmp.c -o libft/ft_strncmp.o

libft/ft_strncpy.o : libft/ft_strncpy.c
	$(CC) $(CFLAGS) -c libft/ft_strncpy.c -o libft/ft_strncpy.o

libft/ft_strnequ.o : libft/ft_strnequ.c
	$(CC) $(CFLAGS) -c libft/ft_strnequ.c -o libft/ft_strnequ.o

libft/ft_strnew.o : libft/ft_strnew.c
	$(CC) $(CFLAGS) -c libft/ft_strnew.c -o libft/ft_strnew.o

libft/ft_strnstr.o : libft/ft_strnstr.c
	$(CC) $(CFLAGS) -c libft/ft_strnstr.c -o libft/ft_strnstr.o

libft/ft_strrchr.o : libft/ft_strrchr.c
	$(CC) $(CFLAGS) -c libft/ft_strrchr.c -o libft/ft_strrchr.o

libft/ft_strsplit.o : libft/ft_strsplit.c
	$(CC) $(CFLAGS) -c libft/ft_strsplit.c -o libft/ft_strsplit.o

libft/ft_strstr.o : libft/ft_strstr.c
	$(CC) $(CFLAGS) -c libft/ft_strstr.c -o libft/ft_strstr.o

libft/ft_strsub.o : libft/ft_strsub.c
	$(CC) $(CFLAGS) -c libft/ft_strsub.c -o libft/ft_strsub.o

libft/ft_strtrim.o : libft/ft_strtrim.c
	$(CC) $(CFLAGS) -c libft/ft_strtrim.c -o libft/ft_strtrim.o

libft/ft_swap.o : libft/ft_swap.c
	$(CC) $(CFLAGS) -c libft/ft_swap.c -o libft/ft_swap.o

libft/ft_tolower.o : libft/ft_tolower.c
	$(CC) $(CFLAGS) -c libft/ft_tolower.c -o libft/ft_tolower.o

libft/ft_toupper.o : libft/ft_toupper.c
	$(CC) $(CFLAGS) -c libft/ft_toupper.c -o libft/ft_toupper.o

libft/ft_wclen.o : libft/ft_wclen.c
	$(CC) $(CFLAGS) -c libft/ft_wclen.c -o libft/ft_wclen.o

libft/ft_wcslen.o : libft/ft_wcslen.c
	$(CC) $(CFLAGS) -c libft/ft_wcslen.c -o libft/ft_wcslen.o

libft/ft_wctomb.o : libft/ft_wctomb.c
	$(CC) $(CFLAGS) -c libft/ft_wctomb.c -o libft/ft_wctomb.o

libft/ft_wcstombs.o : libft/ft_wcstombs.c
	$(CC) $(CFLAGS) -c libft/ft_wcstombs.c -o libft/ft_wcstombs.o

libft/ft_ld_intpower.o : libft/ft_ld_intpower.c
	$(CC) $(CFLAGS) -c libft/ft_ld_intpower.c -o libft/ft_ld_intpower.o

libft/ft_strjoin_free.o : libft/ft_strjoin_free.c
	$(CC) $(CFLAGS) -c libft/ft_strjoin_free.c -o libft/ft_strjoin_free.o

libft/ft_ftoa_base.o : libft/ft_ftoa_base.c
	$(CC) $(CFLAGS) -c libft/ft_ftoa_base.c -o libft/ft_ftoa_base.o

libft/ft_strrev.o : libft/ft_strrev.c
	$(CC) $(CFLAGS) -c libft/ft_strrev.c -o libft/ft_strrev.o
	
libft/get_next_line.o : libft/get_next_line.c
	$(CC) $(CFLAGS) -c libft/get_next_line.c -o libft/get_next_line.o

libft/ft_words_count.o : libft/ft_words_count.c
	$(CC) $(CFLAGS) -c libft/ft_words_count.c -o libft/ft_words_count.o

libft/ft_lstcount.o : libft/ft_lstcount.c
	$(CC) $(CFLAGS) -c libft/ft_lstcount.c -o libft/ft_lstcount.o

libft/ft_lstrev.o : libft/ft_lstrev.c
	$(CC) $(CFLAGS) -c libft/ft_lstrev.c -o libft/ft_lstrev.o

src_printf/ft_printf.o : src_printf/ft_printf.c
	$(CC) $(CFLAGS) -c src_printf/ft_printf.c -o src_printf/ft_printf.o

src_printf/ft_convert.o : src_printf/ft_convert.c
	$(CC) $(CFLAGS) -c src_printf/ft_convert.c -o src_printf/ft_convert.o

src_printf/ft_char.o : src_printf/ft_char.c
	$(CC) $(CFLAGS) -c src_printf/ft_char.c -o src_printf/ft_char.o

src_printf/ft_str.o : src_printf/ft_str.c
	$(CC) $(CFLAGS) -c src_printf/ft_str.c -o src_printf/ft_str.o

src_printf/ft_flags.o : src_printf/ft_flags.c
	$(CC) $(CFLAGS) -c src_printf/ft_flags.c -o src_printf/ft_flags.o

src_printf/ft_is_mb.o : src_printf/ft_is_mb.c
	$(CC) $(CFLAGS) -c src_printf/ft_is_mb.c -o src_printf/ft_is_mb.o

src_printf/ft_length.o : src_printf/ft_length.c
	$(CC) $(CFLAGS) -c src_printf/ft_length.c -o src_printf/ft_length.o

src_printf/ft_no_qual.o : src_printf/ft_no_qual.c
	$(CC) $(CFLAGS) -c src_printf/ft_no_qual.c -o src_printf/ft_no_qual.o

src_printf/ft_numb.o : src_printf/ft_numb.c
	$(CC) $(CFLAGS) -c src_printf/ft_numb.c -o src_printf/ft_numb.o

src_printf/ft_precision.o : src_printf/ft_precision.c
	$(CC) $(CFLAGS) -c src_printf/ft_precision.c -o src_printf/ft_precision.o

src_printf/ft_push.o : src_printf/ft_push.c
	$(CC) $(CFLAGS) -c src_printf/ft_push.c -o src_printf/ft_push.o

src_printf/ft_qualifier.o : src_printf/ft_qualifier.c
	$(CC) $(CFLAGS) -c src_printf/ft_qualifier.c -o src_printf/ft_qualifier.o

src_printf/ft_size.o : src_printf/ft_size.c
	$(CC) $(CFLAGS) -c src_printf/ft_size.c -o src_printf/ft_size.o

src_printf/ft_width.o : src_printf/ft_width.c
	$(CC) $(CFLAGS) -c src_printf/ft_width.c -o src_printf/ft_width.o

src_printf/ft_float.o : src_printf/ft_float.c
	$(CC) $(CFLAGS) -c src_printf/ft_float.c -o src_printf/ft_float.o

src_printf/ft_ftoa_handler.o : src_printf/ft_ftoa_handler.c
	$(CC) $(CFLAGS) -c src_printf/ft_ftoa_handler.c -o src_printf/ft_ftoa_handler.o

src_printf/ft_get_mantissa.o : src_printf/ft_get_mantissa.c
	$(CC) $(CFLAGS) -c src_printf/ft_get_mantissa.c -o src_printf/ft_get_mantissa.o

src_printf/ft_put.o : src_printf/ft_put.c
	$(CC) $(CFLAGS) -c src_printf/ft_put.c -o src_printf/ft_put.o

src_printf/ft_unprint.o : src_printf/ft_unprint.c
	$(CC) $(CFLAGS) -c src_printf/ft_unprint.c -o src_printf/ft_unprint.o

src_printf/ft_quote_mark.o : src_printf/ft_quote_mark.c
	$(CC) $(CFLAGS) -c src_printf/ft_quote_mark.c -o src_printf/ft_quote_mark.o
