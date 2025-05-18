SRC = main.c \
	  clients.c \
	  Reservation.c \
	  Voiture.c

CC = gcc

OBJS = $(SRC:.c=.o)

HEADERS = Gestion_Reservation_voiture.h \

CFLAGS = -Wall -Wextra -g

all: $(OBJS)
	$(CC) -o reservation $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

