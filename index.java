package ValidateCreditCard;

import java.util.Scanner;

public class index
{
	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			long card_number;
			long card_copy;
			

			int total_sum = 0;
			int position = 0;
			int total_length = 0;

			do{
				System.out.print("Number: ");
				card_number = input.nextLong();
				card_copy = card_number;
			
			while(card_number != 0){
				if(position % 2 != 0){
					long temp = (card_number % 10)*2;
				
				if(temp > 9){
					total_sum += temp%10 + temp/10 ;
				}
				else{
					total_sum += temp;
				}


				}
				else{
					total_sum += card_number % 10;
				}
				card_number = card_number/10;
				position ++;
				total_length ++;
			}


					}
					while(card_number !=0);

			if(total_sum % 10 == 0){
				long Amex = card_copy/10000000000000L;
			    if((Amex == 34 || Amex == 37) && total_length == 15){
					System.out.println("AMERICAN EXPRESS\n");
					
				}
				long MasterCard = card_copy/100000000000000L;
				if((total_length == 16) && (MasterCard >= 51 && MasterCard <= 55)){
					System.out.println("MASTERCARD\n");
				} 
				long Visa = card_copy/100000000000000L;
				if((total_length == 16 || total_length == 13 ) && (Visa == 4 || MasterCard / 10 == 4)){
					System.out.println("VISA\n");
				} 	
			}

			else{
				System.out.println("INVALID\n");
			}
		}

	
}
}