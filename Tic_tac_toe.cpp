#include <iostream>
using namespace std;

//These are global variables.

char space[3][3] = {{'1', '2', '3'},{'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool draw = false;
string Player1 ="";
string Player2="";


//Here we defining all the functions

void functionOne(){

    std::cout <<  "    |  |      \n";
    std::cout << "  " << space[0][0] << " |" << space[0][1] << " | " << space[0][2] << " \n";  
    std::cout <<  "----|--|------\n";
    std::cout <<  "    |  |      \n";
    std::cout << " " << space[1][0]  << "  |" << space[1][1] << " | " << space[1][2] << " \n"; 
    std::cout <<  "----|--|------\n";
    std::cout <<  "    |  |      \n";
    std::cout << " " << space[2][0] << "  | " << space[2][1] << "| " << space[2][2] << " \n"; 
    std::cout <<  "----|--|------\n";
    std::cout <<  "    |  |      \n\n\n";

    

    
}

void functionTwo(){

    int digit;                          // this is a variable under functionTwo().
    

//Conditionals and Logic.


    if (token=='x'){                    //This is basically equating the token to the letter x, so when user press a number, it would represent x. 
        std::cout << Player1 << " Please enter a number: \n";      
        std::cin >> digit;
    }

    if (token=='o'){                   //The same with this line of code, but the token equates the number to o.
        std::cout << Player2 << " Your Turn! Enter Number: \n";
        std::cin >> digit;
    }


    

    if (digit == 1){         
        row=0;
        column=0;
    }

    if (digit == 2){
        row=0;
        column=1;
    }

    if (digit == 3){
        row=0;
        column=2;
    }

    if (digit == 4){
        row=1;
        column=0;
    }

    if (digit ==5){
        row=1;
        column=1;
    }

    if (digit == 6){
        row=1;
        column=2;
    }

    if (digit==7){
        row=2;
        column=0;
    }

    if (digit == 8){
        row=2;
        column=1;
    }

    if (digit == 9){
        row=2;
        column=2;    //Remember that the values are inside an array which are {01, 02,03}, {10,11,12} and {20,21,22}.
    }


    else if (digit < 1 || digit > 9) {
        std::cout << " Invalid!!!" << endl;
    }


    if (token=='x' && space[row][column] != 'x' && space[row][column] != 'o'){
        space[row][column]='x';
        token='o';

    }

    else if(token=='o' && space[row][column] !='x' && space[row][column] !='o'){
        space[row][column] = 'o';
        token = 'o';
    }

    else{
        std::cout << "There is no empty space!" << endl;
        functionTwo();
    }

    functionOne();
}


//Check row and columns.

bool functionThree() {

    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }

    // Check diagonals
    
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Checking for tie

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (space[i][j] != 'x' && space[i][j] != 'o') {
                return false;
            }
        }
    }

    // If none of the winning conditions or tie condition is met, return false.
    return false;
}


int main() {


    std::cout << "Enter the name of Player1: \n\n";
    std::cin >> Player1;
    
    std::cout << "Enter the name of Player2: \n\n";
    std::cin >> Player2;

    std::cout << Player1 << " is Player1 so he/she will play first. \n\n";
    std::cout << Player2 << " is Player2 so he/she will start second. \n\n";


    // Main code here

    while(!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }

    if(token=='x' && draw == false){
        std::cout << Player1 <<" Wins!!" <<endl;

    }

    else if(token=='o' && draw == false){
        std::cout << Player2 << " Wins!!" <<endl;

    }

    else{
        std::cout  << "It is a Tie!!" << endl;
    }

    return 0;
}
