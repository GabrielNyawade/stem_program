#include <stdio.h>
int num_array[8] = {1,2,3,4,5,6,7,8};
void print_numbers();
int mean_numbers();


int main(){
    print_numbers();
    int average;
    average = mean_numbers();
    printf("The average of the numbers is %d \n", average);

    return 0;
}

/*
We need to have a function checking the array for odd and even numbers.
Probably I'll need a loop;
and to check if the number is odd, I can check for the modulus of the number;
if the modulus is not equal to 0, it is odd
*/

void print_numbers(){
    int i;
    int mod;
    
    for(i = 0; i < 8; i++){
        mod = num_array[i] % 2;
        if(mod != 0) printf("%d is an odd number\n", num_array[i]);
        else printf("%d is an even number\n", num_array[i]);
    }
    
}

int mean_numbers(){
    int j;
    int total = 0;
    int mean;
    for(j = 0; j <8; j++){
        total += num_array[j];
    }
    mean = total / 8;
    return mean;

}
