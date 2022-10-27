#include<iostream>
#include<vector>
#include<iterator>

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