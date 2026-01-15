#include<stdio.h> 

void main() { 
int i, num; i=2; 
printf("Enter the number"); 
scanf("%d",&num); 

while(i<=num-1) { 
if(num%i==0) { 
printf("Not a prime number"); 
break; 
} i++; 
} printf("number is prime"); 
return 0;
} 
