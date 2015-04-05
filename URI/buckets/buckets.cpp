#include <iostream>
#include <vector>
#include <stack>

/** 
 * This algorithm works just like MergeSort. 
 * It performs a mergesort and count the inversions on each merge.
**/

/* Helper function to sort two pieces of the vector and count the number of inversions on them */
int sortAndCount(std::vector<int> &seq, int begin, int middle, int end) {
    int inv = 0;

    // Two stacks containing the elements from the ranges above, so we can sort it
    std::stack<int> stackLeft;
    for (int i = middle-1; i >= begin; i--) stackLeft.push(seq[i]);

    std::stack<int> stackRight;
    for (int i = end-1; i >= middle; i--) stackRight.push(seq[i]);

    int cnt = stackLeft.size() + stackRight.size(); // How many elements we have in the stacks;
    int index = begin; // Where we are inserting in the original vector
    while (cnt > 0) {
        // If we have values in both stacks, compare them and put the smaller into the position
        if (!stackLeft.empty() && !stackRight.empty()) {
            if (stackLeft.top() < stackRight.top()) {
                seq[index] = stackLeft.top();
                stackLeft.pop();
            }
            else {
                seq[index] = stackRight.top();
                stackRight.pop();
                inv += stackLeft.size();
            }

            index++;
            cnt--;
            continue;
        }

        // If we don't have values in one of the stacks, simply put the rest of the stacks in the vector
        if (stackLeft.empty()) {
            while (cnt > 0) {
                seq[index] = stackRight.top();
                stackRight.pop();
                index++;
                cnt--;
            }
        }
        else {
            while (cnt > 0) {
                seq[index] = stackLeft.top();
                stackLeft.pop();
                index++;
                cnt--; 
            }
        }
    }

    return inv;
}

/* How many movements to sort this */
int countMovements(std::vector<int> &seq, int begin, int end) {
    // If we have a array of one element, we need 0 moviments to order it */
    if (begin == end-1) return 0;

    // Devide array in the middle, call function to count both sides
    int middle = (begin + end) / 2;

    int countLeft = countMovements(seq, begin, middle);
    int countRight = countMovements(seq, middle, end);
    int countMerge = sortAndCount(seq, begin, middle, end);

    return countLeft + countRight + countMerge;
}



int main() {
    int N;

    std::cin >> N;
    while (N != 0) {
        std::vector<int> seq(N);

        for (int i = 0; i < N; ++i) {
            std::cin >> seq[i];
        }

        if (countMovements(seq, 0, N) % 2 == 0) std::cout << "Carlos" << std::endl;
        else std::cout << "Marcelo" << std::endl;

        std::cin >> N;
    }
    
    return 0;
}