CFLAGS = -g -O2

all: knapsack knapsackDP2

knapsack: knapsack.o

knapsackDP: knapsackDP.o

knapsackDP2: knapsackDP2.o

subsetsum: subsetsum.o

clean:
		rm -f *.o *~ knapsack knapsackDP knapsackDP2 subsetsum
