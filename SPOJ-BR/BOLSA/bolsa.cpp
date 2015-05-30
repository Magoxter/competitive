#include <iostream>
#include <queue>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
    int N;

    while (true) {
        std::cin >> N;
        if (N == 0) break;

        double total = 0;

        std::priority_queue<double> buy;
        std::priority_queue<double, std::vector<double>, std::greater<double>> sell;

        for (int i = 0; i < N; i++) {
            char type; double value;
            std::cin >> type >> value;
            
            switch (type) {
                case 'C':
                    if (!sell.empty() && value >= sell.top()) {
                        total += value - sell.top();
                        sell.pop();
                    } 
                    else
                        buy.push(value);
                    
                    break;
                case 'V':
                    if (!buy.empty() && value <= buy.top()) {
                        total += buy.top() - value;
                        buy.pop();
                    } 
                    else 
                        sell.push(value);

                    break; 
            }
        }
        
        std::cout << std::setprecision(2) << std::fixed << total << '\n';
    }

    return 0;
}