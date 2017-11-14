all: car point main 
	g++ Car.o Point.o main.o -o main.out

car:
	g++ -c Car.cpp -o Car.o

point:
	g++ -c Point.cpp -o Point.o

main:
	g++ -c main.cpp -o main.o

clean:
	rm -rf *.o *.out
