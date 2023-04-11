#include<iostream>
#include<vector>
#include<algorithm>

/* The task was to take a list of coins and find the least natural number that can't be expressed as 
a sum of one or more of those coins. My approach was simple: I sorted the coin list, maintained a cumulative sum
and checked if it was more than or equal to the next coin. This was efficient because the bottleneck was the
sorting. */

class CoinSum{

    private:
        long long int coin_count;
        std::vector<long long int> coins;
        long long int working_sum;

    public:
        CoinSum(long long int n){
            coin_count = n;
            coins = std::vector<long long int>(n, 0);
            working_sum = 0;
        }
        void read_input(){
            long long int row = 0;
            for (int iii = 0; iii<coin_count;iii++){
                std::cin >> row;
                coins[iii] = row;
            }
            std::sort(coins.begin(), coins.end());
        } 
        long long int smallest_sum(){
            
            for (auto &coin: coins){
                if (coin > working_sum + 1){
                    return working_sum + 1;
                }
                working_sum += coin;
            }
            return working_sum + 1;
        }
};

int main(){

    long long int coins = 0;
    std::cin >> coins;
    CoinSum coinsum = CoinSum(coins);
    coinsum.read_input();
    std::cout << coinsum.smallest_sum(); 

}