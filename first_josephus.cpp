#include<iostream>
#include<set>
#include<iterator>

int main(){

    int upper_bound;
    std::cin >> upper_bound;
    std::set<int> untouched;
    std::set<int> working;

    for (int iii=1; iii<=upper_bound; iii++){
        untouched.insert(iii);
    }
    working = untouched;
    bool change = false;
    while (!untouched.empty()){

        std::set<int>::iterator item = untouched.begin();

        int first_item = *item;
        
        for (item = untouched.begin(); item != untouched.end(); item++){
            if (change){
                std::cout << *item << " ";
                working.erase(*item);
            }
            change = !change;
        }
        untouched = working;
    }

    return 0;
}