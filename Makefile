NAME = Gestion_Reservation_voiture

SRC = main.c \
	  clients.c \
	  Reservation.c \
	  Voiture.c

OBJS = $(SRC:.c=.o)

HEADERS = Gestion_Reservation_voiture.h

CFLAGS = -Wall -Wextra -Werror 

CC = cc

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

