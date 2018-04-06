#include <stdio.h>

int main() {
	/*
	 * 1) Team leaders (fixed fortnightly salary)
	 * 2) Sales workers ($500 plus 6.5% of their gross fortnightly sales)
	 * 3) Pieceworkers (fixed amount of money per item for each of the items they produce,
	 * each piece worker in this company works on only 1 type of item)
	 * 4) Hourly workers (fixed hourly wage for up to the first 60 hours they work and "time-anda-half"
	 * i.e. 1.5 times their hourly wage, for overtime hours worked)
	*/
	/*
	 * Code 1: Team leaders
	 * Code 2: Sales workers
	 * Code 3: Pieceworkers
	 * Code 4: Hourly workers
	*/

	// totalPayroll for the fortnight
	float totalPayroll = 0;
	// of true then the loop will stop
	int shouldExit = 0;
	do {
		// employee number to check
		int employeeNumber;
		printf("Enter employee's number code (-1 to end): ");
		scanf("%d", &employeeNumber);
		switch(employeeNumber) {
			case -1:
				shouldExit = 1;
				// time to exit the loop and display the total payroll
				break;
			case 1:
				// calculate the payroll for Team leader
				float payRate;
				printf("Enter the Team leaders’s pay rate: ");
				scanf("%f", &payRate);
				printf("fortnightly pay is: %.2f\n\n", payRate);
				totalPayroll = totalPayroll + payRate;
				break;
			case 2:
				// calculate the payroll for Sales worker
				float weeklySales, pay;
				printf("Enter Sales employee's gross weekly sales: ");
				scanf("%f", &weeklySales);
				pay = 500 + (weeklySales * 0.065);
				printf("fortnightly pay is: %.2f\n\n", pay);
				totalPayroll = totalPayroll + pay;
				break;
			case 3:
				// calculate the payroll for Pieceworker
				float pieces, payPerPieceRate, totalPay;
				printf("Enter the number of pieces completed: ");
				scanf("%f", &pieces);
				printf("Enter the employee's per piece pay rate: ");
				scanf("%f", &payPerPieceRate);
				totalPay = pieces * payPerPieceRate;
				printf("fortnightly pay is: %.2f\n\n", totalPay);
				totalPayroll = totalPayroll + totalPay;
				break;
			case 4:
				// calculate the payroll for Hourly worker
				float hourlyRate, hoursWorked, fortnightPay;
				printf("Enter hourly worker's pay rate: ");
				scanf("%f", &hourlyRate);
				printf("Enter the number of hours worked: ");
				scanf("%f", &hoursWorked);
				fortnightPay = (hoursWorked > 60) ? (60 * hourlyRate + ((hoursWorked - 60) * hourlyRate * 1.5)) : (hoursWorked * hourlyRate);
				printf("fortnightly pay is: %.2f\n\n", fortnightPay);
				totalPayroll = totalPayroll + fortnightPay;
				break;
			default:
				// invalud employee number
				printf("You have entered an invalid code.\n\n");
				break;
		}
	} while (!shouldExit); // exit the loop
	// display the total payroll and quit the app
	printf("The total payroll for the fortnight is: %.2f\n", totalPayroll);
	return 0;
}
