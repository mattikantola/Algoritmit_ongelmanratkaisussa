#include<iostream>
#include<deque>
#include<algorithm>

int main(){

    int number_of_movies = 0;
    std::deque<std::pair<long long int, long long int> > storage;

    long long int start, stop = 0;
    std::cin >> number_of_movies;


    for (int iii=0; iii<number_of_movies; iii++){
        std::cin >> start >> stop;
        std::pair<long long int, long long int> movie = std::pair<long long int, long long>(stop, start);
        storage.push_back(movie);
    }
    std::sort(storage.begin(), storage.end());

    long long int max_succ = 1;
    
    while (!storage.empty()){
        std::pair<long long int, long long int> cur_movie = storage.front();
        long long int cur_stop = cur_movie.first;
        storage.pop_front();
        while (!storage.empty()) {
            std::pair<long long int, long long int> next_movie = storage.front();
            storage.pop_front();
            if (next_movie.second >= cur_movie.first){
                max_succ += 1;
                storage.push_front(next_movie);
                break;
            }
        }
    }
    std::cout << max_succ << std::endl;
}