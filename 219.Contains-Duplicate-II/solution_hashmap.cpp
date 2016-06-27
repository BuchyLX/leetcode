#include<iostream>
#include<time.h>

using namespace std;

const int MAX_INTERVAL = 20;

struct Answer {
    bool has_duplicate;
    int i, j, value;
    
    Answer() {
        has_duplicate = false;
        i = 0;
        j = 0;
        value = 0;
    }
};

Answer find_duplicate(int *int_arr, int len);

void show_answer(Answer answer);

int main(int argc, char* argv[]) {    
    int num_elements = -1;
    cout << "Enter elements in the array." << endl;

    cin >> num_elements;
    if (num_elements <= 0) {
        printf("Enter a number larger than 0!\n");
    }
    srand((unsigned)time(NULL));    // 用系统时间初始化种子
    int * int_arr = new int[num_elements];
    for (int i = 0; i < num_elements; ++i) {
        int_arr[i] = rand() % 100;  // 生成1-100之间的随机数组
    }

    Answer answer = find_duplicate(int_arr, num_elements);
    show_answer(answer);

    return 0;
}

Answer find_duplicate(int * int_arr, int len) {
    Answer answer;
    for (int i = 0; i < len - MAX_INTERVAL; ++i) {
        for (int j = 1; j <= 20; ++j) {
            if (int_arr[i] == int_arr[j]) {
                answer.has_duplicate = true;
                answer.i = i;
                answer.j = i + j;
                answer.value = int_arr[i];
                break;
            }
        }
    }

    return answer;
}

void show_answer (Answer answer) {
    if (answer.has_duplicate == true) {
        printf("The array has same elements within %d distance. e.g Array[%d] = Array[%d], the value is %d.\n", MAX_INTERVAL, answer.i, answer.j, answer.value);
    } else {
        printf("The array has no same elements within %d distance.\n", MAX_INTERVAL);
    }
}
