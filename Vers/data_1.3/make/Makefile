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
make: hel.o functime.o battle.o Goblin1.1.o 
	$(CC) $(FLAGS) $(PATH_1)hel.o $(PATH_1)battle.o $(PATH_1)functime.o $(PATH_1)Goblin1.1.o -o $(PATH_3)GAME.exe
# статическая библиотека функции приветствия:
hel.o: $(PATH_2)hel.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)hel.c -o $(PATH_1)hel.o
# статическая библиотека функции боя:
battle.o: $(PATH_2)battle.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)battle.c -o $(PATH_1)battle.o
# статическая библиотека генерации случайного числа:
functime.o: $(PATH_2)functime.c $(PATH_2)global.h
	$(CC) $(FLAGS) -c $(PATH_2)functime.c -o $(PATH_1)functime.o
# компиляция основного файла:
Goblin1.1.o: $(PATH_2)Goblin1.1.c
	$(CC) $(FLAGS) -c $(PATH_2)Goblin1.1.c -o $(PATH_1)Goblin1.1.o
# очистка в каталогах:
clean:
	rm -rf $(PATH_1)*.o $(PATH_1)*.out $(PATH_3)*.exe *.o *.out *.exe
# очистка и компиляция заново:
rebuild: clean all



