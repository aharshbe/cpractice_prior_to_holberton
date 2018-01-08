/*
    This program generates 10
    random numbers and then
    sorts them using bubble sort
    O(n^2)
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(int argc, char **argv){

//Setting up initial variables
int ctr, inner, outer, didSwap, temp;
int nums[10];
time_t t;

//Seeing rand with random numbers
srand(time(&t));

//Adds random numbers to the array
for(ctr = 0; ctr < 10; ctr++){

    nums[ctr] = (rand() % 99) + 1;
}


puts("\nHere are the numbers before the sort: \n");

for(int i = 0; i < 10; i++){

    printf(" %d", nums[i]);
}

//Sort the numbers
for(outer = 0; outer < 9; outer++){

    didSwap = 0;

    for(inner = outer; inner < 10; inner++){

        if(nums[inner] < nums[outer]){

            temp = nums[inner];
            nums[inner] = nums[outer];
            nums[outer] = temp;
            didSwap = 1;
        }
    }

    if(didSwap == 0){

        break;
    }
}

puts("\n-----------------------------\n");

//List the sorted array
puts("Here are the numbers after the sort: \n");

for(int i = 0; i < 10; i++){

    printf(" %d", nums[i]);

}

puts("\n-----------------------------");


return 0;

}
