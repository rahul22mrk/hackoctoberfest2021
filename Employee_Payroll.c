
#include <stdio.h>
#include<stdlib.h>

struct Employee_Payroll
{
    float empId;
    float hourlyWorked;
    float hourlyRate;
    float grossPay;
    float regularPay;
    float overtimePay;
    float fed_tax_deduction;
    float ssno_tax_deduction;
    float finally_net_pay;
};



void Payroll_record(int n,  struct Employee_Payroll *ptr)
{
    int i;
    for ( i = 0; i < n; ++i)
    {
        printf("Enter Employees ID: ");
        scanf("%f", &((ptr+i)->empId));
        printf("Enter Employees hourly Worked: ");
        scanf("%f", &((ptr+i)->hourlyWorked));
        printf("Enter Employees hourly Rate: ");
        scanf("%f", &((ptr+i)->hourlyRate));

        if ((ptr+i)->hourlyWorked > 40){
            (ptr+i)->overtimePay = 1.5*((ptr+i)->hourlyWorked - 40) * (ptr+i)->hourlyRate;
        }
        else{
            (ptr+i)->overtimePay = 0.00;
        }

        (ptr+i)->regularPay = (ptr+i)->hourlyWorked * (ptr+i)->hourlyRate;
        (ptr+i)->grossPay = 7*((ptr+i)->regularPay +  (ptr+i)->overtimePay);
        (ptr+i)->fed_tax_deduction = 0.275 * (ptr+i)->grossPay;
        (ptr+i)->ssno_tax_deduction = 0.0772 * (ptr+i)->grossPay;
        (ptr+i)->finally_net_pay = (ptr+i)->grossPay - ((ptr+i)->fed_tax_deduction + (ptr+i)->ssno_tax_deduction );
    } 
}


void payroll_record_display(int n, struct Employee_Payroll* ptr)
{
        int i;
        printf("\nEmp No       Hourly Rate      Hours Worked       Reg. Pay         OT Pay         Gross Pay       Fed Tax         Other Tax          Net Pay");
        for ( i = 0; i < n; ++i)
        {
            
    printf("\n%.0f          $%.2f          %.2f            $%.2f           $%.2f         $%.2f          $%.2f           $%.2f         %.2f",(ptr+i)->empId, (ptr+i)->hourlyRate, (ptr+i)->hourlyWorked, (ptr+i)->regularPay, (ptr+i)->overtimePay, (ptr+i)->grossPay, 
                                                                                                                (ptr+i)->fed_tax_deduction, (ptr+i)->ssno_tax_deduction, (ptr+i)->finally_net_pay);

        }   

}

int main()
{
    struct Employee_Payroll *ptr, record;
    int n;
    int choice, num; 

    printf("Enter the no of Employees: ");
    scanf("%d", &n);
      
    do
    {    
        printf("\n\n");
        printf("1. Enter a new payroll record\n"); 
        printf("2. Display all payroll summary information\n"); 
        printf("3. Quit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice);
        while(choice < 1 || choice > 4)
        {
            printf("\nPlease enter a valid choice");
			printf("\nEnter 1, 2 or 3: ");
			scanf("%d", &choice);
        }
        switch (choice) { 
            case 1: 
            { 
                
                //allocting the memory of n no of struct employee
                ptr = (struct Employee_payroll*)malloc(n* sizeof(struct Employee_Payroll));
                ptr = &record;
                Payroll_record(n, &ptr);
                break;
                
            } 

            case 2: 
            { 
                payroll_record_display(n, &ptr);
                break;
            } 

            case 3: 
            { 
                printf("\nGoodbye! ");
               
            } 
        } 

    } while (choice <= 2 && choice >= 1);

    
    return 0; 
} 
