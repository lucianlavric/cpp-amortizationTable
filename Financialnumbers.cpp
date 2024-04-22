#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const int monthsInYear = 12;
    const int percentDenominator = 100;
    
    double principal = 0.0;
    
    cout << "Enter the principal amount: ";
    
    cin >> principal;
    
    double humanInterest = 0.0;
    
    cout << "Enter the interest rate: ";
    
    cin >> humanInterest;
    
    double interest = humanInterest/ percentDenominator;
    
    int yearsOfLoan = 0;
    
    cout << "Enter the years of loan: ";
    
    cin >> yearsOfLoan;
    
    double monthInterest = interest/ (double)monthsInYear;
    long monthsOfLoan = yearsOfLoan * (long)monthsInYear;
    
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
    
    while(currLoanMonth <= monthsOfLoan){
        
       currInterestPayment = currBalance * monthInterest;
       currPrincipalPayment = payment - currInterestPayment;
       currBalance = currBalance - currPrincipalPayment;
       
       cout << "CM " << currLoanMonth << " CI: " << currInterestPayment <<
       " CP: " << currPrincipalPayment <<
       " Bal: " << currBalance << endl;

       currLoanMonth++;
    }
    
    cout << "Loan payments complete." << endl;
    
    return 0;
}