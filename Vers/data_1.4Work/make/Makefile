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
make: hel.o functime.o battle.o Mget_variant.o Mprintmenu.o gamekey.o menu2.3.o Goblin1.1.o 
	$(CC) $(FLAGS) $(PATH_1)hel.o $(PATH_1)battle.o $(PATH_1)functime.o $(PATH_1)Mget_variant.o $(PATH_1)Mprintmenu.o $(PATH_1)gamekey.o $(PATH_1)menu2.3.o $(PATH_1)Goblin1.1.o -o $(PATH_3)GAME.exe
# статические библиотеки:
hel.o: $(PATH_2)hel.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)hel.c -o $(PATH_1)hel.o
battle.o: $(PATH_2)battle.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)battle.c -o $(PATH_1)battle.o
functime.o: $(PATH_2)functime.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)functime.c -o $(PATH_1)functime.o
Mget_variant.o: $(PATH_2)Mget_variant.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)Mget_variant.c -o $(PATH_1)Mget_variant.o
Mprintmenu.o: $(PATH_2)Mprintmenu.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)Mprintmenu.c -o $(PATH_1)Mprintmenu.o
gamekey.o: $(PATH_2)gamekey.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)gamekey.c -o $(PATH_1)gamekey.o
# компиляция основного файла меню:
menu2.3.o: $(PATH_2)menu2.3.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)menu2.3.c -o $(PATH_1)menu2.3.o
# компиляция основного файла:
Goblin1.1.o: $(PATH_2)Goblin1.1.c
	$(CC) $(FLAGS) -c $(PATH_2)Goblin1.1.c -o $(PATH_1)Goblin1.1.o
# очистка в каталогах:
clean:
	rm -rf $(PATH_1)*.o $(PATH_1)*.out $(PATH_3)*.exe *.o *.out *.exe
# очистка и компиляция заново:
rebuild: clean all



