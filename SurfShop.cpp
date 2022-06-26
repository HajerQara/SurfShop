/*
Name: Hajer Qara 
Date: 6/26/2022
File Name: SurfShop
Section: ITCS 2530 V0801 2021SS - C++ Programming 1

SurfShop.cpp:
Johnny Utah owns a surf shop on the beach called �Point Break Surf Shop�. 
Johnny sells surfboards in 3 three sizes: small (2 meters), medium (3 meters), and large (4 meters). 
The cost of one small surfboard is $175.00, one medium is $190.00, and one large is $200.00.  
Write a program that will make the surf shop operational.  

Your program should allow the user to do the following:
    1) Buy any surfboard in any size and in any quanity.
    2) At any time show the total number of surfboards of each size sold.
    3) At any time show the total money made.

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//a function to sell surfboards.
void MakePurchase(int& iTotalXXXSmall)
{
    //Declared Variables
    int quantity;
    string size;

    // Prompts the users to make a single purchase of a surfboard
    cout << "Please enter the quantity and type (XXXS= extra extra extra small) of surfboard you would like to purchase:";
    // Allows the user to enter how many surfboards and in what size
    cin >> quantity >> size;
    cout << endl;

    // This will allow the total quantity of the small size to increment 
    // if users purchase more small surfboards
    iTotalXXXSmall += quantity;



}

// function to show the number of surfboards of each size sold.
void DisplayPurchase(const int iTotalXXXSmall)
{
    //Declared Variables
    string size;

    // checks to see if there where any small surfboards purchased

    size = "extra extra extra small"; // dynamically inputs size
  //Prints out total quantity for the specific size
    cout << "The total number of " << size << " surfboards is " << iTotalXXXSmall << endl;


    cout << endl;

}

//a function to show the total amount of money made.
void DisplayTotal(const int iTotalXXXSmall)
{
    //Constant Variables
    const double xxxSmallPrice = 100.00;

    //Declared Variables
    double totalPrice = 0.00;
    double amountDue = 0.00;
    string size;


    size = "extra extra extra small";
    // calculates the total price for the individual size group
    totalPrice = iTotalXXXSmall * xxxSmallPrice;
    cout << "The total number of " << size << " surfboards is " << iTotalXXXSmall << " at a total of $" << fixed << setprecision(2) << totalPrice << endl;
    // accumulates the amount for the total amount due by the user
    amountDue = amountDue + totalPrice;



    cout << "Amount due: $" << fixed << setprecision(2) << amountDue << endl;
    cout << endl;
}

//a function to show the user how to use the program.
void ShowUsage()
{
    //A menu the user can select from 
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchase press 'C" << endl;
    cout << "To display total amount due press 'T" << endl;
    cout << "To quit the program press 'Q" << endl << endl;


}


int main()
{
    //Constant Variables
    const int BORDER_LENGTH = 80;

    //Declared Variables
    string welcomeMessage;
    int welcomeLength;
    int border;
    int halfBorder;

    // Greeting that welcomes the users to the shop 
    welcomeMessage = " Welcome to my Johnny Utah's PointBreak Surf Shop! ";
    welcomeLength = static_cast<int>(welcomeMessage.length()); // calculates the number of char in welcome message

    border = BORDER_LENGTH - welcomeLength; // calculates how much space the greeting takes up 
    halfBorder = border / 2; // calculates how long the half border will be 
    string asterisk(halfBorder, '*'); // repeats the asterisk based on the length of the half border

    //Prints out the bordered welcome sign 
    cout << setfill('*') << setw(BORDER_LENGTH) << "*" << endl; // prints out asterisks based on the length of the border
    cout << asterisk << right << welcomeMessage << asterisk << endl; // prints half border with message
    cout << setw(BORDER_LENGTH) << "*" << setfill(' ') << endl; // resets so whitespaces no longer print out asterisks

    cout << endl << endl;

    ShowUsage();

    //Declared variables for menu 
    char selection;
    // initializes the parameters that get passed through the functions
    int iTotalXXXSmall = 0;

    // Asks the user to make a selection from the menu
    cout << "Please enter selection:";
    cin >> selection;

    while (selection != 'Q' && selection != 'q') {
        if (selection == 'S' || selection == 's') {
            ShowUsage();
        }
        else if (selection == 'P' || selection == 'p') {
            MakePurchase(iTotalXXXSmall);
        }
        else if (selection == 'C' || selection == 'c') {
            //checks if there have been any purches yet 
            if (iTotalXXXSmall == 0) {
                cout << "No purchases made yet." << endl;
                cout << endl;
            }
            else {
                DisplayPurchase(iTotalXXXSmall);
            }
        }
        else if (selection == 'T' || selection == 't') {
            //checks if there have been any purches yet 
            if (iTotalXXXSmall == 0) {
                cout << "No purchases made yet." << endl;
                cout << endl;
            }
            else {
                DisplayTotal(iTotalXXXSmall);
            }
        }
        else {
            // should quite program by going back to main
            exit(1);
        }

        cout << "Please enter selection:";
        cin >> selection;

    }

    cout << "Thank you" << endl;
    system("pause");
    return 0;
}




//////////////////////////////////////////////////////////////////////////////
////////// CODE THAT I TRIED BUT DIDN'T WORK ////////////////////////////////
/*
* // This  while structure didn't take into account if there was no purchases made
* // declare varaibles
    int iTotalSmall = 175;
    int iTotalMedium = 190;
    int iTotalLarge = 200;

    while (selection != 'Q' && selection != 'q') {
        if (selection == 'S' || selection == 's') {
            ShowUsage();
        }
        else if (selection == 'P' || selection == 'p') {
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge);
        }
        else if (selection == 'C' || selection == 'c') {
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge);
        }
        else if (selection == 'T' || selection == 't') {
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge);
        }
        else {
            // should quite program by going back to main
            exit(1);
        }

    // This didn't increment the quantity if another purchase was made 
    if (size == 's' || size == 'S') {
        iTotalSmall = quantity;
    }
    else if (size == 'm' || size == 'M') {
        iTotalMedium = quantity;
    }
    else {
        iTotalLarge = quantity;
    }


    // This didn't allow all the orders to show 
    // Instead I put individual if statements to check for past orders 
    // also didn't accumulate amount due properly since it only took last total price it scanned 
    if (iTotalSmall) {
        size = "small";
        totalPrice = iTotalSmall * smallPrice;
        cout << "The total number of " << size << " surfboards is " << iTotalSmall << " at a total of $" << fixed << setprecision(2) << totalPrice << endl;
    }
    else if (iTotalMedium) {
        size = "medium";
        totalPrice = iTotalMedium * mediumPrice;
        cout << "The total number of " << size << " surfboards is " << iTotalMedium << " at a total of $" << fixed << setprecision(2) << totalPrice << endl;
    }
    else if (iTotalLarge) {
        size = "large";
        totalPrice = iTotalLarge * largePrice;
        cout << "The total number of " << size << " surfboards is " << iTotalLarge << " at a total of $" << fixed << setprecision(2) << totalPrice << endl;
    }
    else{
        cout << "Invalid Entry."<< endl; 
    }

    amountDue = amountDue + totalPrice;

    // // This didn't allow all the orders to show 
    // Instead I put individual if statements to check for other size orders 
    else if (iTotalSmall) {
        size = "small"; 
        cout << "The total number of " << size << " surfboards is " << iTotalSmall << endl;
    }
    else if (iTotalMedium) {
        size = "medium"; 
        cout << "The total number of " << size << " surfboards is " << iTotalMedium << endl;
    }
    else if (iTotalLarge) {
        size = "large"; 
        cout << "The total number of " << size << " surfboards is " << iTotalLarge << endl;
    }
    else{
        cout << "Invalid Entry."<< endl;
    }

*/