# Используемый компилятор
CC = gcc
# Флаги компиляции, могут быть отличны в разных комп. и сист.
FLAGS = -Wall -Werror -Wextra
# Пути компиляции для библиотек и файлов
PATH_1 = ../libs/
PATH_2 = ../data/
PATH_3 = ../build/
# Явное указание игнорировать файлы с указанными именами в папке
.PHONY: all clean rebuild uninstall
# Общая сборка по умолчанию
all: make
# Сборка по зависимостям, позволяет собрать новый общий файл 
# при изменении любой библиотеки, не компилируя всё (экон. времени)
make: hel.o seedrand.o print_hero.o gamekey.o gameover.o compaund.o goblin_battle.o play.o battle.o get_variant.o printmenu.o  menu2.3.o intro.o slee.o main11.o
	$(CC) $(FLAGS) $(PATH_1)hel.o $(PATH_1)seedrand.o $(PATH_1)print_hero.o $(PATH_1)gamekey.o $(PATH_1)gameover.o $(PATH_1)compaund.o $(PATH_1)goblin_battle.o (PATH_1)play.o $(PATH_1)battle.o $(PATH_1)get_variant.o $(PATH_1)printmenu.o $(PATH_1)menu2.3.o $(PATH_1)intro.o $(PATH_1)slee.o $(PATH_1)main11.o -o $(PATH_3)GAME.exe
# статические библиотеки:
hel.o: $(PATH_2)hel.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)hel.c -o $(PATH_1)hel.o
seedrand.o: $(PATH_2)seedrand.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)seedrand.c -o $(PATH_1)seedrand.o
print_hero.o: $(PATH_2)print_hero.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)print_hero.c -o $(PATH_1)print_hero.o
gamekey.o: $(PATH_2)gamekey.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)gamekey.c -o $(PATH_1)gamekey.o
gameover.o: $(PATH_2)gameover.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)gameover.c -o $(PATH_1)gameover.o
compaund.o: $(PATH_2)compaund.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)compaund.c -o $(PATH_1)compaund.o
goblin_battle.o: $(PATH_2)goblin_battle.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)goblin_battle.c -o $(PATH_1)goblin_battle.o
play.o: $(PATH_2)play.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)play.c -o $(PATH_1)play.o
battle.o: $(PATH_2)battle.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)battle.c -o $(PATH_1)battle.o
get_variant.o: $(PATH_2)get_variant.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)get_variant.c -o $(PATH_1)get_variant.o
menu2.3.o: $(PATH_2)menu2.3.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)menu2.3.c -o $(PATH_1)menu2.3.o
printmenu.o: $(PATH_2)printmenu.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)printmenu.c -o $(PATH_1)printmenu.o
intro.o: $(PATH_2)intro.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)intro.c -o $(PATH_1)intro.o
slee.o: $(PATH_2)slee.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)slee.c -o $(PATH_1)slee.o
main11.o: $(PATH_2)main11.c
	$(CC) $(FLAGS) -c $(PATH_2)main11.c -o $(PATH_1)main11.o -lncurses
clean:
	rm -rf $(PATH_1)*.o $(PATH_1)*.out $(PATH_3)*.exe *.o *.out *.exe
# очистка и компиляция заново:
rebuild: clean all


