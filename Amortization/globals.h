struct gAmortizeMonth
{
    /* data */
    int year;
    int yearMonth;
    int loanMonth;
    int payment;
    double pureInterest;
    double paidDownPrincipal;
    double principalBalance;
};


const int gMonthsInYear = 12;
const int gPercentDenominator = 100;