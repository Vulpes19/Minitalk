SERVER = server 
CLIENT = client 
HEADER = minitalk.h ft_printf/ft_printf.h 
PRINTF = ft_printf
LIBPRINTF = ft_printf/libftprintf.a
SRMAIN = server.c
SRVSRC = server.c
CLMAIN = client.c
CLSRC = conversion.c
SRVOBJS = $(SRVSRC:.c=.o)
CLOBJS = $(CLSRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
DEL = rm -f

all: $(SERVER) $(CLIENT)

%.o: %.c
	cc -c $(CFLAGS) -o $@ $< -g

$(SERVER): $(LIBPRINTF) $(HEADER)
	cc $(CFLAGS) $(LIBPRINTF) $(SRVSRC) -o $(SERVER)

$(CLIENT): $(LIBPRINTF) $(CLOBJS) $(HEADER)
	cc $(CFLAGS) $(LIBPRINTF) $(CLOBJS) $(CLMAIN) -o $(CLIENT)

$(LIBPRINTF):
	$(MAKE) -C $(PRINTF)

clean:
	$(DEL) $(OBJS)
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	$(DEL) $(NAME)
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re