#include<iostream>
#include<vector>
#include<iterator>

/* You are given an array of n integers. You want to modify the array so that it is increasing,
i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. 
What is the minimum number of moves required? 

My approach was to iterate through the array, always calculate the difference and increase the elements
accordingly. */

int main(){

    int size;
    std::cin >> size;
    std::vector<long long int> values;
    
    for (int index = 0; index < size; index++){
        int new_value;
        std::cin >> new_value;
        values.push_back(new_value);
    }

    long long int moves = 0;

    std::vector<long long int>::iterator iter;
    for (iter = values.begin() + 1; iter < values.end(); iter++){
        long long int diff = *(iter-1) - *(iter);
        if (diff > 0){
            moves += diff;
            *iter += diff;
        }
    }

    std::cout << moves << std::endl;
    return 0;
}