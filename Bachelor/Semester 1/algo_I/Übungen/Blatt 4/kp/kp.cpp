#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

void print_usage();
void print_vector(std::vector<int> v);
void print_results(std::vector<std::vector<int>>& P, std::vector<int>& utility, std::vector<int>& weights);
std::vector<int> csv_to_vector(std::string csv);
void write_to_csv(std::vector<std::vector<int>>& P, std::vector<int>& utility, std::vector<int>& weights);

std::vector<std::vector<int>> dyn_kp(int capacity, std::vector<int>& utility, std::vector<int>& weights);
std::vector<int> reconstruct_solution(std::vector<std::vector<int>>& P, std::vector<int>& weights);

int main(int argc, char **argv) {
    if (argc != 7 && argc != 8) {
        print_usage();
        return -1;
    }

    int capacity;
    std::vector<int> utility;
    std::vector<int> weights;
    bool csv = false;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0)
            capacity = std::stoi(argv[++i]);
        else if (strcmp(argv[i], "-p") == 0)
            utility = csv_to_vector(argv[++i]);
        else if (strcmp(argv[i], "-w") == 0)
            weights = csv_to_vector(argv[++i]);
        else if (strcmp(argv[i], "--csv") == 0)
            csv = true;
    }

    if (utility.size() != weights.size()) {
        std::cout << "Invalid arguments: count of weights and utilities do not match" << std::endl;
        return -1;
    }

    std::cout << "Knapsack size: " << capacity << std::endl;
    std::cout << "Available items:";
    for (int i = 0; i < utility.size(); i++) {
        std::cout << " (" << weights[i] << ", " << utility[i] << ")";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> P = dyn_kp(capacity, utility, weights);

    print_results(P, utility, weights);

    if (csv)
        write_to_csv(P, utility, weights);
}

void print_usage() {
    std::cout << "Program calculates solution to knapsack problem. Usage: " << std::endl;
    std::cout << "> kp -t [capacity] -p [utilities as csv] -w [weights as csv] [[--csv (to output calculation table into .csv file)]]" << std::endl;
}

std::vector<int> csv_to_vector(std::string csv) {
    std::vector<int> result = {};
    int start = 0;
    int length = csv.length();
    for(int i = 0; i < length; i++) {
        if (i == length - 1 || csv[i + 1] == ',') {
            int newEntry = std::stoi(csv.substr(start, i - start + 1));
            result.push_back(newEntry);
            start = i + 2;
            i++;
        }
    }
    return result;
}

void print_vector(std::vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        std::cout << v[i] << ',';
    }
    std::cout << v[v.size() - 1] << std::endl;
}

std::vector<std::vector<int>> dyn_kp(int capacity, std::vector<int>& utility, std::vector<int>& weights) {
    int n = utility.size();
    std::vector<std::vector<int>> P(n);
    for (int i = 0; i < n; i++)
        P[i] = std::vector<int>(capacity + 1);

    for (int w = 0; w < weights[0]; w++)
        P[0][w] = 0;
    for (int w = weights[0]; w <= capacity; w++)
        P[0][w] = utility[0];

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i] > w) {
                P[i][w] = P[i - 1][w];
                continue;
            }
            P[i][w] = std::max(utility[i] + P[i - 1][w - weights[i]], P[i - 1][w]);
        }
    }

    return P;
}

void print_results(std::vector<std::vector<int>>& P, std::vector<int>& utility, std::vector<int>& weights) {
    int n = P.size();
    int capacity = P[0].size() - 1;

    std::cout << "Optimal utility: " << P[n - 1][capacity] << std::endl;

    std::vector<int> solution = reconstruct_solution(P, weights);

    std::cout << "Items used:";
    for (int i = solution.size() - 1; i >= 0; i--) {
        std::cout << " (" << weights[solution[i]] << ", " << utility[solution[i]] << ")";
    }
    std::cout << std::endl;
}

std::vector<int> reconstruct_solution(std::vector<std::vector<int>>& P, std::vector<int>& weights) {
    int n = P.size();
    int capacity = P[0].size() - 1;

    std::vector<int> solution = {};

    int w = capacity;
    for (int i = n - 1; i > 0; i--) {
        if (P[i][w] > P[i - 1][w]) {
            solution.push_back(i);
            w -= weights[i];
        }
    }

    if (P[0][w] != 0) {
        solution.push_back(0);
    }

    return solution;
}

void write_to_csv(std::vector<std::vector<int>>& P, std::vector<int>& utility, std::vector<int>& weights) {
    int n = P.size();
    int capacity = P[0].size() - 1;
    
    std::ofstream fout;
    fout.open("kptable.csv");
    fout << "p_i,w_i,i,w" << std::endl; // header line

    fout << ",,";
    for (int i = 0; i <= capacity; i++)
        fout << "," << i;
    fout << std::endl;

    for (int i = 0; i < n; i++) {
        fout << utility[i] << "," << weights[i] << "," << i + 1;
        for (int w = 0; w <= capacity; w++) {
            fout << "," << P[i][w] << " | ";
            if (i == 0) {
                if (P[i][w] == 0)
                    fout << "0";
                else
                    fout << "1";
            }
            else {
                if (P[i][w] == P[i - 1][w])
                    fout << "0";
                else
                    fout << "1";
            }
        }
        fout << std::endl;
    }

    fout.close();
}