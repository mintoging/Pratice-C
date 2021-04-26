#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int bucket[45];
	
	for (int i = 0; i < 45; ++i) { 
		bucket[i] = i + 1;
	}
	
	//shuffle
	srand(time(NULL));
	for (int i = 1; i < 10000; ++i) {
		int left = rand() % 45;
		int right = rand() % 45;
		
		int tmp = bucket[left];
		bucket[left] = bucket[right];
		bucket[right] = tmp;
	}
	
	for (int i = 0; i < 7; ++i) {
		printf("%d ", bucket[i]);
	}
	printf("\n");

	return 0;
	}t bu
