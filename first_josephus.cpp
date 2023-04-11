#include<iostream>
#include<set>
#include<iterator>

/* The problem: there are n kids standing in a circle numbered from 1 to n. You go around the circle and remove 
every other child until there are no children left. In which order are the children removed? I solved the
problem using two binary trees: a working tree from which I can remove elements and another which is updated
after every round. */

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