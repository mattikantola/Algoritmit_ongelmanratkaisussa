#include<iostream>
#include<vector>
#include<iterator>

template<typename T> std::vector<std::vector<T>> sequence(const std::vector<T> &data, std::vector<int> included){

    for (auto& iii: included){
        iii = 1;
    }

    return;
}

int main(void){


    long long int upper_bound;
    std::cin >> upper_bound;
    std::vector<int> number_list;
    std::vector<int> included;

    for (int iii = 1; iii <= upper_bound; iii++){
        number_list.push_back(iii);
        included.push_back(0);
    }

    return 0;
}