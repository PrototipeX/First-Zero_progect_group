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
make: hel.o battle.o Goblin1.1.o
	$(CC) $(FLAGS) $(PATH_1)hel.o $(PATH_1)battle.o $(PATH_1)Goblin1.1.o -o $(PATH_3)GAME.exe
# статическая библиотека функции приветствия:
hel.o: hel.c hel.h
	$(CC) $(FLAGS) -c hel.c -o $(PATH_1)hel.o
# статическая библиотека функции боя:
battle.o: battle.c battle.h
	$(CC) $(FLAGS) -c battle.c -o $(PATH_1)battle.o
# компиляция основного файла:
Goblin1.1.o: Goblin1.1.c
	$(CC) $(FLAGS) -c Goblin1.1.c -o $(PATH_1)Goblin1.1.o
# очистка в каталогах:
clean:
	rm -rf $(PATH_1)*.o $(PATH_1)*.out $(PATH_3)*.exe *.o *.out *.exe
# очистка и компиляция заново:
rebuild: clean all



