/* Collatz conjecture */

#include<iostream>


int main(void){

    long long int nnn;
    std::cin >> nnn;
        while (nnn>1){

        std::cout << nnn << " ";

        if (nnn%2 == 0){
            nnn /= 2;
        }
        else{
            nnn = 3*nnn + 1;
        }
        
    }
    std::cout << nnn << std::endl;
    return 0;

}