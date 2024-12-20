//  Program for Tower of Hanoi using recursion.

#include<stdio.h>
int step=0;
// C recursive function to solve tower of hanoi puzzle 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    step++;
    if (n == 1) 
    { 
        printf("\nStep-%d: Move disk 1 from rod %c to rod %c", step,from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\nStep-%d: Move disk %d from rod %c to rod %c", step,n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 
  




int main() 
{ 
    int n; // Number of disks 
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods 
    return 0; 
} 

