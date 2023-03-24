#include<iostream>
#include<vector>

int main(void){

    int size;
    int curr = 1;
    int rounds = 1;
    std::cin >> size;
    std::vector<int> indices;
    for (int iii = 0; iii<= size; iii++){
        indices.push_back(0);
    }
    for (int iii=0; iii<size; iii++){
        int new_value;
        std::cin >> new_value;
        indices[new_value] = iii;
    }

    for (int iii = 1; iii < size; iii++){
        if (indices[iii] < indices[iii+1]){
            continue;
        }
        rounds += 1;
    }


    std::cout << rounds << std::endl;
    return 0;
}