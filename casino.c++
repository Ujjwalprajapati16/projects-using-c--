# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
using namespace std;
void rules();

int main(){
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; //stores the random number
    char choice;
    srand(time(0));
    cout<<"\n\t\t=========WELCOME TO CASINO WORLD============\n\n";
    cout<<"\n\nEnter the starting balance to play game : $";
    cin>>balance;
    do{
        system("cls");
        rules();
        cout<<"\n\n Your current balance to play game : $"<<balance<<"\n";
        //Get Players betting balance
        do{
            cout<<"Hey, "<<playerName<<", enter amount to bet : $";
            cin>>bettingAmount;
            if(bettingAmount > balance){
                cout<<"Betting balance can't be more than current balance! \n"<<"\nRe-enter balance\n";
            }
        }while(bettingAmount > balance);
                //get players numbers
        do{
            cout<<"Guess any betting number between 1 & 10 :";
            cin>>guess;
            if(guess <= 0 || guess > 10){
                cout<<"\n Number should be between 1 to 10\n"<<"Re-enter number :\n";
            }
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess){
            cout<<"\n\nYou are in luck!! You have won Rs."<<bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }else{
            cout<<"Oops, better luck next time!! You Lost $ "<<bettingAmount<<"\n";
            balance = balance - bettingAmount;
        }
        cout<<"\nThe winning number was : "<<dice<<"\n";
        cout<<"\n"<<playerName<<", YOu have balance of $ "<<balance<<"\n";
        if(balance == 0){
            cout<<"You have no money to play";
            break;
        }
        cout<<"\n\n-->Do you want to play again (Y/n) ?";
        cin>>choice;
    }while(choice == 'Y' || choice == 'y');            
    cout<<"\n\n\n";
    cout<<"\n\nThanks for playing the game. Your balance is $ "<<balance<<"\n\n";
    return 0;
}
void rules(){
    system("cls");
    cout<<"\t\t=======CASINO NUMBER GUESSING RULES!!=============\n";
    cout<<"\t1. Choose a number between 1 to 10\n";
    cout<<"\t2. Winner gets 10 times of the money bet\n";
    cout<<"\t3. Wrong bet, and you lose the amount you bet\n\n";
}