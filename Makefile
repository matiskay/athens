all: clean
	 gcc -c binary_tree.c
	 gcc -c main.c
	 gcc -o main binary_tree.o main.o

test_binary_tree: clean
	 gcc -c binary_tree.c
	 gcc -c test_binary_tree.c
	 gcc -o test_binary_tree binary_tree.o test_binary_tree.o
	 ./test_binary_tree

test:	 test_binary_tree

clean:
	 rm *.o || exit 0

run: clean
	 gcc -c binary_tree.c
	 gcc -c main.c
	 gcc -o main binary_tree.o main.o
	 ./main
