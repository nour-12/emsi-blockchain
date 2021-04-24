c_compiler = gcc
c_flags = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3 -c

source = sha256.c ec_create.c ec_to_pub.c ec_from_pub.c ec_save.c ec_load.c ec_sign.c ec_verify.c
object= $(source:.c=.o)
name = libhblk_crypto.a

.phony: clean oclean flcean libhblk_crypto.a

clean:
	$(RM) *~ $(name)

oclean:
	$(RM) $(object)

fclean: clean oclean

libhblk_crypto.a: hblk_crypto.h $(object)
	ar rcs $(name) $(object)
