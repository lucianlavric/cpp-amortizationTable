#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

// A program in Cpp that uses the forward price formula 
// to calculate the forward price of a contract (without dividends)
// see formula here: https://corporatefinanceinstitute.com/resources/derivatives/forward-price/

using namespace std;

//Function that will be used to prompt the users for a y or n to represent whether or not
//their underlying has dividends within the time period.
//Source: https://stackoverflow.com/questions/2209135/safely-prompt-for-yes-no-with-cin

bool PromptForChar(const char* prompt, char& readch) {
    cout << prompt << endl;
    cin >> readch; // Read a single character directly using cin
    cin.ignore(); // Ignore any remaining characters in the input buffer
    return (readch == 'y' || readch == 'n'); // Return true if input is 'y' or 'n'
}


int main(){
    double forward_price;
    double underlying_current_spot_price;
    double risk_free_rate;
    double delivery_date_in_yrs;

    cout << "Please enter the underlying's current spot price" << endl;
    cin >> underlying_current_spot_price;

    cout << "what is your risk-free rate?" << endl;
    cin >> risk_free_rate;
    risk_free_rate /= 100;


    cout << "In how many years will your contract reach maturity? (Ex. half a year is 0.5)" << endl;
    cin >> delivery_date_in_yrs;

    char pays_dividends = '\0';


    while (!PromptForChar("Does your stock pay dividends? [y/n]", pays_dividends)) {
        cout << "Invalid input. Please enter 'y' or 'n': ";
    }

    if (pays_dividends == 'y') {
        cout << "It pays dividends." << endl;
        // Calculate forward price with dividends

        cout << "How much is the dividend?" << endl;
        double dividend_amount;
        cin >> dividend_amount;

        cout << "When is the dividend to be paid?" << endl;
        double dividend_paid_date;
        cin >> dividend_paid_date;

        forward_price = (underlying_current_spot_price - dividend_amount/(pow((risk_free_rate + 1), (dividend_paid_date / 365)))) * pow(1+risk_free_rate, delivery_date_in_yrs);
        cout << "Your contract's forward price is $" << fixed << setprecision(2) << forward_price << endl;
    }

    else if (pays_dividends == 'n') {
        cout << "It does not pay dividends." << endl;
        // Calculate forward price without dividends
        forward_price = underlying_current_spot_price * (pow(M_E, delivery_date_in_yrs * risk_free_rate));
        cout << "Your contract's forward price is $" << fixed << setprecision(2) << forward_price << endl;
    }   

}