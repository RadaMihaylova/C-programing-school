/*Направете заглавен файл “mystrings.h”, който да декларира 3 функции, които да работят със символни низове. 
Първата функция (strlength) трябва да намира дължината на символен низ, втората (strconcat) да слива два символни низа в първия подаден като аргумент на функцията, 
третата функция (strcompare) трябва да сравнява лексикално два символни низа (да връща -1 ако първия стринг се намира лексикално преди втория, 
0 - ако двата символни низа за еднакви и 1 ако първия символен низ се намира след втория). Пример за strlength: Вход: “Ivan” => Изход: 4. Пример за strconcat: 
Вход: str1=Hello, str2=World => strconcat(str1, str2) => Изход: str1=HelloWorld, str2=World. Пример за strcompare: Вход: “Alex”, “Alan” => Изход: 1, вход: “Alex”, “Alex” => 
Изход: 0, вход “Alex”, “Boyan” => Изход: -1. Направете сорс файл mystrings.c, който да вмъква заглавния файл “mystrings.h” и да дефинира функциите (да ги имплементира). 
Добавете в Makefile-a от първа задача цел, която се казва mystrings.o която да компилира модула до обектен файл. 
Променете clean целта така че да изчиства и обектните файлове.*/


CC = gcc
CFLAGS = -Wall -g

TARGETS = strlength.out strconcat.out strcompare.out

OBJECTS = mystrings.o strlength.o strconcat.o strcompare.o

all: $(TARGETS)

strlength.out: strlength.o mystrings.o
	$(CC) -o strlength.out strlength.o mystrings.o

strconcat.out: strconcat.o mystrings.o
	$(CC) -o strconcat.out strconcat.o mystrings.o

strcompare.out: strcompare.o mystrings.o
	$(CC) -o strcompare.out strcompare.o mystrings.o

mystrings.o: mystrings.c mystrings.h
	$(CC) $(CFLAGS) -c mystrings.c

strlength.o: strlength.c mystrings.h
	$(CC) $(CFLAGS) -c strlength.c

strconcat.o: strconcat.c mystrings.h
	$(CC) $(CFLAGS) -c strconcat.c

strcompare.o: strcompare.c mystrings.h
	$(CC) $(CFLAGS) -c strcompare.c

clean:
	rm -f $(TARGETS) $(OBJECTS)
