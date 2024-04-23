#include <iostream>
#include <cmath>
#include <iomanip>
#include "globals.h"

using namespace std;

enum AmortizeProgram
{
    LOAN_PRINCIPAL = 1,
    INTEREST_RATE = 2,
    YEARS_OF_LOAN = 3
};

enum AmortEnum
{
    YR_OUT = 2,
    MN_OUT = 2,
    CUM_MN_OUT = 5,
    PAYMENT_OUT = 12,
    INTEREST_OUT = 12,
    PRINCIPAL_OUT = 12,
    BALANCE_OUT = 16
};

string AmortHeader[] =
{
    "Yr",
    "Mn",
    "CumMn",
    "Payment",
    "Interest",
    "Principal",
    "Balance"
};

void printAmortHeader()
{
    cout <<
        endl <<
        setw(YR_OUT) << AmortHeader[0] << " " <<
        setw(MN_OUT) << AmortHeader[1] << " " <<
        setw(CUM_MN_OUT) << AmortHeader[2] << " " <<
        setw(PAYMENT_OUT) << AmortHeader[3] << " " <<
        setw(INTEREST_OUT) << AmortHeader[4] << " " <<
        setw(PRINCIPAL_OUT) << AmortHeader[5] << " " <<
        setw(BALANCE_OUT) << AmortHeader[6] <<
        endl <<
        endl;
}

int main(int argc, char* argv[])
{
    double principal = 0.0;
    double humanInterest = 0.0;
    int yearsOfLoan = 0;
    
    if (argc == 1)
    {
        cout << "Enter the principal amount: ";
        cin >> principal;
        
        cout << "Enter the interest rate: ";
        cin >> humanInterest;
        
        cout << "Enter the years of loan: ";
        cin >> yearsOfLoan;
        
    } else {
        
        principal = atof(argv[LOAN_PRINCIPAL]);
        humanInterest = atof(argv[INTEREST_RATE]);
        yearsOfLoan = atoi(argv[YEARS_OF_LOAN]);
        
    }
    
    cout << "Loan Principal: " << principal << endl;
    cout << "Interest Rate: " << humanInterest << "%" << endl;
    cout << "Time Period: " << yearsOfLoan << " year(s)" << endl;
    
    double interest = humanInterest/ (double) gPercentDenominator;
    
    double monthInterest = interest/ gMonthsInYear;
    long monthsOfLoan = yearsOfLoan * gMonthsInYear;
    
    double payment = 0.0;
    
    payment = principal *
    (monthInterest /
     (1 - (pow((double)1 + monthInterest,
               (double)-monthsOfLoan))));
    
    cout << "Payment: " << setiosflags(ios::fixed) <<
    setprecision(2) << payment << endl;
    
    double currInterestPayment = 0.0;
    double currPrincipalPayment = 0.0;
    double currBalance = 0.0;
    
    currBalance = principal;
    
    long currLoanMonth = 1;
    
    int year = 1;
    int switchYear = 0;
    
    int yearMonth = 1;
    
    while(currLoanMonth <= monthsOfLoan){
        
        if(switchYear != year){
            
            switchYear = year;
            
            printAmortHeader();
        }
        
        gAmortizeMonth amortMonth;
        
        currInterestPayment = currBalance * monthInterest;
        currPrincipalPayment = payment - currInterestPayment;
        currBalance = abs(currBalance - currPrincipalPayment);
        
        amortMonth.year = year;
        amortMonth.yearMonth = yearMonth;
        amortMonth.loanMonth = currLoanMonth;
        amortMonth.payment = payment;
        amortMonth.pureInterest = currInterestPayment;
        amortMonth.paidDownPrincipal = currPrincipalPayment;
        amortMonth.principalBalance = currBalance;
        
        cout <<
        setw(YR_OUT) << amortMonth.year << " " <<
        setw(MN_OUT) << amortMonth.yearMonth << " " <<
        setw(CUM_MN_OUT) << amortMonth.loanMonth << " " <<
        setw(PAYMENT_OUT) << amortMonth.payment << " " <<
        setw(INTEREST_OUT) << amortMonth.pureInterest << " " <<
        setw(PRINCIPAL_OUT) << amortMonth.paidDownPrincipal << " " <<
        setw(BALANCE_OUT) << amortMonth.principalBalance <<
        endl;
        
        yearMonth++;
        
        if (yearMonth > gMonthsInYear)
        {
            yearMonth = 1;
            year++;
        }
        
        currLoanMonth++;
    }
    
    cout <<
        endl <<
        "Loan payments complete." <<
        endl <<
        endl;
    
    return 0;
}