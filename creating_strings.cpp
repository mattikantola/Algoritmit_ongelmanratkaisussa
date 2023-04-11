#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>

/* Making brute force backtracking anagrams, nothing special. */

class Substrings{

    private:
        std::string full_string;
        std::set<std::string> cache;
        std::vector<bool> included;
        std::string working;
        int size;
    
    public:
        Substrings(std::string initializer){
            full_string = initializer;
            size = full_string.length();
            included = std::vector<bool>(size, false);
            working = std::string(size, ' ');
        }

        void traverse(int work_index){

            if (work_index == size){
                cache.insert(working);
            }
            else{
                for (int iii=0;iii<size;iii++){
                    if (not included[iii]){
                        included[iii] = true;
                        working[work_index] = full_string[iii];
                        traverse(work_index+1);
                        included[iii] = false;
                    }
                }
            }
        }

        void print(){
            std::cout << cache.size() << std::endl;
            std::vector<std::string> items;
            for (auto &item: cache){
                items.push_back(item);
            }
            std::sort(items.begin(), items.end());
            for (auto &item: items){
                std::cout << item << std::endl;
            }
        }

};

int main(){

    std::string tutkittava;
    std::getline(std::cin, tutkittava);
    Substrings anagrams = Substrings(tutkittava);
    anagrams.traverse(0);
    anagrams.print();

}