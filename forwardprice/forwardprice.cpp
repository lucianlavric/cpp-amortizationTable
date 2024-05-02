#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

// A program in Cpp that uses the forward price formula 
// to calculate the forward price of a contract (without dividends)
// see formula here: https://corporatefinanceinstitute.com/resources/derivatives/forward-price/

using namespace std;

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

    forward_price = underlying_current_spot_price * (pow(M_E,delivery_date_in_yrs * risk_free_rate));

    cout << "Your contract's forward price is $" << fixed << setprecision(2) << forward_price;

}