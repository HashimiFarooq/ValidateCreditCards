/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>


int main(void)
{
long card_number;
long card_copy;

int total_sum = 0;
int position = 0;
int total_length = 0;

//get valid card number
do{
    printf("Number: ");
    scanf("%ld", &card_number);
    card_copy = card_number;
    
 while(card_number != 0){

    if(position % 2 != 0){
    //Multiply every other digit by 2
    int temp = (card_number % 10) * 2;

    if(temp > 9){
        //This seperated the 2 digit number for example
        // 18 -> 1 + 8
         total_sum += (temp % 10 + temp / 10);
    }
    else{
        total_sum += temp;
    }
    
}
    else{
        total_sum += card_number % 10;
    }
    card_number /=10;
    position ++;
    total_length ++;
}

     
 }
while(card_number != 0);



if(total_sum % 10 == 0){
    
    //Conditions for American Express Card
    long Amex = card_copy/10000000000000;
    if((Amex == 34 || Amex == 37) && total_length == 15){
        printf("AMERICAN EXPRESS\n");
        return 0;
    }
    //Conditions for Master Card
    long MasterCard = card_copy/100000000000000;
    if((total_length == 16) && (MasterCard >= 51 && MasterCard <= 55)){
        printf("MASTERCARD\n");
        return 0;
    } 
    //Conditions for Visa Card    
    long Visa = card_copy/100000000000000;
    if((total_length == 16 || total_length == 13 ) && (Visa == 4 || MasterCard / 10 == 4)){
        printf("VISA\n");
        return 0;
    } 
}

else{
    printf("INVALID\n");
}




    return 0;
}
