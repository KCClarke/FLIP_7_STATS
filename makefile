CC = gcc -O3 -std=c99 -pg
FLAGS = -I.

CORE_OBJS = cards/cards.o results/pregame.o percent/percent.o points/points.o random/random.o shuffle/shuffle.o results/postgame.o player/player.o dealer/dealer.o rounds/rounds.o
DEBUG_OBJS = debug_main.o templates/template.o tests/tests.o tests/test_cards.o tests/test_percent.o tests/test_points.o tests/test_random.o tests/test_player.o tests/test_dealer.o tests/test_rounds.o

all: debug_flip_7

debug_flip_7: $(CORE_OBJS) $(DEBUG_OBJS)
	$(CC) -o $@ $(CORE_OBJS) $(DEBUG_OBJS)

debug_main.o: main.c
	$(CC) $(FLAGS) -DDEBUG=1 -c main.c -o debug_main.o

flip_7: main.o $(CORE_OBJS)
	$(CC) -o $@ main.o $(CORE_OBJS)

main.o: main.c
	$(CC) $(FLAGS) -c main.c -o main.o

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

debug:
	./debug_flip_7

run:
	time ./flip_7
	./flip_7 > results.txt

profile:
	gprof flip_7 gmon.out > profile.txt

clean:
	find . -name "*.o" -delete
	rm -f flip_7 debug_flip_7
	rm -f gmon.out
