#include<iostream>


class Partition
{

private:

    long long int working_sum = 0;
    long long int total = 0;

public:
    bool *choice;
    long long int size;
    bool *result;
    Partition(long long int n)
    {

        choice = new bool[n];
        result = new bool[n];
        size = n;
        for (int iii = 0; iii < size; iii++)
        {
            choice[iii] = false;
            total = (long long int)((size + 1) * size / 2);
        }
    }
    bool possible = false;
    long long int get_elements(){
        long long int count = 0;
        for (long long int iii=1; iii<size; iii++){
            if (result[iii]){
                count++;
            }
        }
        return count;
    }
    void parts(long long int working_index)
    {

        if (total % 2 != 0 or working_index == -1 or possible)
        {
            return;
        }

        else if (working_sum == total / 2){
            
            for (long long int iii=1; iii<size; iii++){
                result[iii] = choice[iii];
            }
            possible = true;
            return;
        }
        else if (working_sum > total / 2)
        {
            return;
        }
        else
        {
            choice[working_index] = true;
            working_sum += working_index + 1;
            parts(working_index - 1);
            choice[working_index] = false;
            working_sum -= working_index + 1;
            parts(working_index - 1);
        }
    }
};

int main(void)
{

    long long int upper_bound;
    std::cin >> upper_bound;

    Partition partition(upper_bound);

    partition.parts(upper_bound - 1);

    if (partition.possible)
    {
        std::cout << "YES" << std::endl;
        std::cout << partition.get_elements() << std::endl;
        for (int iii = 0; iii<upper_bound; iii++){
            if (partition.result[iii]){
                std::cout << iii + 1 << " ";
            }
        }
        std::cout << std::endl;
        std::cout << partition.size - partition.get_elements() << std::endl;
        for (int iii=0; iii<upper_bound; iii++){
            if (not partition.result[iii]){
                std::cout << iii + 1 << " ";
            }
        }
    }

    else
    {
        std::cout << "NO";
        return 0;
    }

    return 0;
}