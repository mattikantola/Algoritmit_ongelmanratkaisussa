#include<iostream>
#include<vector>
#include<unordered_set>

long long int subarrays(std::vector<int> data, int diversity){

    long long int matches = 0;

    for (int iii=0; iii<data.size(); iii++){
        std::unordered_set<int> matchset;
        for (int jjj = iii; jjj<data.size(); jjj++){
            matchset.insert(data[jjj]);
            if (matchset.size() >= diversity){
                matches += data.size() - jjj;
                break;
            }
        }
    }
    return matches;

}

int main(){

    int length;
    int div;
    std::cin >> length >> div;
    std::vector<int> data;
    for (int iii = 0; iii < length; iii++){
        int new_element;
        std::cin >> new_element;
        data.push_back(new_element);
    }

    std::cout << subarrays(data, div) << std::endl;
    return 0;

}