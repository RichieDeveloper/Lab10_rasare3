/**
 * @file Lab10_rasare3.cpp
 * @author Richie
 * @date 2026-11-20
 * @brief Demonstrates a bank account system with deposits, withdrawals, interest calculations, and saving account information to a file.
 */
#include<iostream>
#include "SavingsAccount.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();
double getDepositAmount();
double getWithdrawalAmount();
void printInvalidAmountMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int SAVE = 4;
const int QUIT = 5;

/**
 * @brief Entry point of the CSCC Bank and Trust program.
 * @return 0 to indicate successful execution.
 */
int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    SavingsAccount *account = new SavingsAccount("5423678409", 100.00, .05, customer);
    account->printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        double deposit = 0, withdrawal = 0;

        switch (menuChoice)
        {
        case DEPOSIT:
            deposit = getDepositAmount();
            account->deposit(deposit);
            break;
        case WITHDRAWAL:
            withdrawal = getWithdrawalAmount();
            account->withdraw(withdrawal);
            break;
        case CLOSE_OF_BUSINESS:
            account->closeOfBusiness();
            break;
        case SAVE:
            account->Save();
			cout << "Account information saved successfully." << endl;
            break;
        }

        menuChoice = getMenuOption();
    }

	delete account;

	return 0;
}
/**
* @brief Displays the main menu options to the user.
* @return None.
*/
void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
	cout << SAVE << ". Save Account Information" << endl;
    cout << QUIT << ". Quit" << endl;
}
/**
* @brief Gets and validates the user's menu choice.
* @return The valid menu choice selected by the user.
*/
int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

/**
* @brief Validates the user's menu choice.
* @param choice The menu choice to validate.
* @return True if the choice is valid, false otherwise.
*/
bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}


/**
* @brief Validates the user's deposit or withdrawal amount.
* @param amount The amount to validate.
* @return True if the amount is valid, false otherwise.
*/
bool isAmountValid(double amount)
{
    return amount > 0;
}

/**
* @brief Prints a message indicating an invalid menu choice was selected.
* @return None.
*/
void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}
/**
* @brief Gets the deposit amount from the user.
* @return The valid deposit amount entered by the user.
*/
double getDepositAmount()
{
    double deposit = 0;
    do
    {
        cout << "Please enter the deposit amount: $";
        cin >> deposit;

        if (!isAmountValid(deposit))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(deposit));

    return deposit;
}
/**
* @brief Prompts the user to enter a valid withdrawal amount.
* @return The valid withdrawal amount entered by the user.
*/
double getWithdrawalAmount()
{
    double withdrawal = 0;
    do
    {
        cout << "Please enter the withdrawal amount: $";
        cin >> withdrawal;

        if (!isAmountValid(withdrawal))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

/**
* @brief Prints a message indicating an invalid amount was entered.
* @return None.
*/
void printInvalidAmountMessage()
{
    cout << "The dollar amount must be greater than $0.00. Please try again." << endl;
}