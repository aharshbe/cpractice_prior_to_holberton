#include<stdio.h>


void selection_sort(int arr[]);


int main(int argc, char **argv){

	int arr[] = {1, 5, 3, 4, 2, 6};

	selection_sort(arr);

}


void selection_sort(int arr[]){

	int sorted[] = {0, 0, 0, 0, 0, 0};


	int inner, outer, smallest, element, sorted_place;
	sorted_place, element, smallest, inner = outer = 0;

	int current = arr[element];
	int next = arr[element + 1];

	for(; outer < 5; outer++){

			for(; inner < 5; inner++){

				printf("\nCurrent is: %d, Next is: %d\n\n", current, next);
				puts("***************************************************");

					if(current < next){

						sorted[sorted_place] = current; //Sets the smallest current value
		
						printf("Current(%d) < Next(%d). Smallest is now: %d\n", current, next, sorted[sorted_place]);

						++element;
						++sorted_place;
						next = arr[element+1];
						current = arr[element];	

						puts("***************************************************");	

					}else{

						printf("Current(%d) > Next(%d). Moving to next... ", current, next);
					
						++element;
						current = arr[element];
						next = arr[element+1];

						printf("Next is: %d\n", next);

						puts("***************************************************");

					}

			}

	}

	//Prints results

	puts("\n\t**Results**\n");

	int i = 0;
	while(i < 6){

		printf("Unsorted: %d \t Sorted: %d \n", arr[i], sorted[i]);
		++i;
	}

	puts("");

}