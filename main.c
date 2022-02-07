#include <stdio.h>

// ввод в масив array с клавиатуры size элементов
void inputArray(int *array, size_t size) {
    for (int pos = 0; pos < size; ++pos)
        scanf("%d", &array[pos]);
}

// вывод size элементов масива array;
void outputArray(int *array, size_t size) {
    for (int pos = 0; pos < size; ++pos)
        printf("%d ", array[pos]);
}

// ввод входных данных для задачи и ее номер
// task - номер задачи
// arrayA - массив A
// arrayB - массив B
// sizeA - количество элемнтов массива arrayA
// sizeB - количество элемнтов массива arrayB
void setTaskCondition(size_t *task, int *arrayA, int *arrayB, size_t *sizeA, size_t *sizeB) {
    puts("Input task number");
    scanf("%lld", task);

    puts("Input number of elements for arrayA < 100");
    scanf("%lld", sizeA);
    puts("Input arrayA");
    inputArray(arrayA, *sizeA);

    puts("Input number of elements for arrayB < 100");
    scanf("%lld", sizeB);
    puts("Input arrayB");
    inputArray(arrayB, *sizeB);
}

//Дано:
//
//А – массив натуральных чисел, в котором нет одинаковых элементов;
//
//В – массив натуральных чисел, в котором нет одинаковых элементов.
//
//Получить массив С, содержащий все элементы массивов А и В без повторений.

void task1(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    for (int i = 0; i < *sizeA; ++i) {
        int isUnique = 1;
        int j = 0;
        while (isUnique && j < *sizeC) {
            if (arrayA[i] == arrayC[j])
                isUnique = 0;
            else
                j++;
        }
        if (isUnique) {
            arrayC[*sizeC] = arrayA[i];
            *sizeC += 1;
        }
    }

    for (int i = 0; i < *sizeB; ++i) {
        int isUnique = 1;
        int j = 0;
        while (isUnique && j < *sizeC) {
            if (arrayB[i] == arrayC[j])
                isUnique = 0;
            else
                j++;
        }
        if (isUnique) {
            arrayC[*sizeC] = arrayB[i];
            *sizeC += 1;
        }
    }
}

//Дано:
//
//А – массив натуральных чисел, в котором нет одинаковых элементов;
//
//В – массив натуральных чисел, в котором нет одинаковых элементов.
//
//Получить массив С, содержащий все такие элементы, которые есть и в массиве А и в массиве В.
void task2(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    for (int i = 0; i < *sizeA; ++i) {
        int isUnique = 1;
        int j = 0;
        while (isUnique && j < *sizeB) {
            if (arrayA[i] == arrayB[j])
                isUnique = 0;
            else
                j++;
        }
        if (!isUnique) {
            arrayC[*sizeC] = arrayA[i];
            *sizeC += 1;
        }
    }
}

//Вариант 3
//
//Дано:
//
//А – массив натуральных чисел, в котором нет одинаковых элементов;
//
//В – массив натуральных чисел, в котором нет одинаковых элементов.
//
//Получить массив С, содержащий все элементы массива А, которых нет в В.

void task3(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    for (int i = 0; i < *sizeA; ++i) {
        int isUnique = 1;
        int j = 0;
        while (isUnique && j < *sizeB) {
            if (arrayA[i] == arrayB[j])
                isUnique = 0;
            else
                j++;
        }
        if (isUnique) {
            arrayC[*sizeC] = arrayA[i];
            *sizeC += 1;
        }
    }
}

//Вариант 4
//
//Дано:
//
//А – массив натуральных чисел, в котором нет одинаковых элементов;
//
//В – массив натуральных чисел, в котором нет одинаковых элементов.
//
//Получить массив С, содержащий все элементы массива А, которых нет в В и все элементы массива В, которых нет в А.

void task4(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    for (int i = 0; i < *sizeA; ++i) {
        int isUnique = 1;
        int j = 0;
        while (isUnique && j < *sizeB) {
            if (arrayA[i] == arrayB[j])
                isUnique = 0;
            else
                j++;
        }
        if (isUnique) {
            arrayC[*sizeC] = arrayA[i];
            *sizeC += 1;
        }
    }

    for (int i = 0; i < *sizeB; ++i) {
        int isUnique = 1;
        int j = 0;
        while (isUnique && j < *sizeA) {
            if (arrayB[i] == arrayA[j])
                isUnique = 0;
            else
                j++;
        }
        if (isUnique) {
            arrayC[*sizeC] = arrayB[i];
            *sizeC += 1;
        }
    }
}

//Вариант 5
//
//Дано:
//
//А – массив натуральных чисел, в котором нет одинаковых элементов;
//
//В – массив натуральных чисел, в котором нет одинаковых элементов.
//
//Определить, верно ли, что массив В содержит каждый элемент массива А.
void task5(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    if (*sizeA <= *sizeB) {
        int i = 0;
        int isFound = 1;
        while (isFound && i < *sizeA) {
            int j = 0;
            while (arrayA[i] != arrayB[j] && j < *sizeB) {
                j++;
            }
            if (j == *sizeB)
                isFound = 0;
            else
                i++;
        }
        arrayC[0] = i == *sizeA;
        *sizeC += 1;
    } else {
        arrayC[0] = 0;
        *sizeC += 1;
    }
}

//Вариант 6
//
//Дано:
//
//А – массив натуральных чисел, в котором нет одинаковых элементов;
//
//В – массив натуральных чисел, в котором нет одинаковых элементов.
//
//Определить, верно ли, что массивы А и В состоят из одинаковых элементов.
void task6(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    if (*sizeA == *sizeB) {
        int i = 0;
        int isFound = 1;
        while (isFound && i < *sizeA) {
            int j = 0;
            while (arrayA[i] != arrayB[j] && j < *sizeB) {
                j++;
            }
            if (j == *sizeB)
                isFound = 0;
            else
                i++;
        }
        arrayC[0] = i == *sizeA;
        *sizeC += 1;
    } else {
        arrayC[0] = 0;
        *sizeC += 1;
    }
}

//Вариант 7
//
//Дано:
//
//А – массив натуральных чисел, в котором нет одинаковых элементов;
//
//В – массив натуральных чисел, в котором нет одинаковых элементов.
//
//Определить, верно ли, что в массивах А и В нет общих элементов.

void task7(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    if (*sizeA <= *sizeB) {
        int i = 0;
        int isFound = 0;
        while (!isFound && i < *sizeA) {
            int j = 0;
            while (arrayA[i] != arrayB[j] && j < *sizeB) {
                j++;
            }
            if (j != *sizeB)
                isFound = 1;
            else
                i++;
        }
        arrayC[0] = i == *sizeA;
        *sizeC += 1;
    } else {
        arrayC[0] = 0;
        *sizeC += 1;
    }
}

//Вариант 8
//
//Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
//
//Получить упорядоченный по возрастанию массив С, содержащий все элементы массивов А и В.
void task8(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    size_t iWriteC = 0;
    while (iReadA < *sizeA && iReadB < *sizeB) {
        if (arrayA[iReadA] == arrayB[iReadB]) {
            iReadA++;
            iReadB++;
        } else if (arrayA[iReadA] < arrayB[iReadB]) {
            arrayC[iWriteC] = arrayA[iReadA];
            iReadA++;
            iWriteC++;
        } else {
            arrayC[iWriteC] = arrayB[iReadB];
            iReadB++;
            iWriteC++;
        }
    }
    if (iReadA < iReadB) {
        if (arrayA[iReadA] == arrayC[iWriteC - 1])
            iReadA++;
        while (iReadA < *sizeA) {
            arrayC[iWriteC] = arrayA[iReadA];
            iReadA++;
            iWriteC++;
        }
    } else {
        if (arrayB[iReadB] == arrayC[iWriteC - 1])
            iReadB++;
        while (iReadB < *sizeB) {
            arrayC[iWriteC] = arrayB[iReadB];
            iReadB++;
            iWriteC++;
        }
    }
    *sizeC = iWriteC;
}

//Вариант 9
//
//Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
//
//Получить упорядоченный по возрастанию массив С, содержащий все такие элементы, которые есть и в массиве А и в массиве В.

void task9(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    size_t iWriteC = 0;
    while (iReadA < *sizeA && iReadB < *sizeB) {
        if (arrayA[iReadA] == arrayB[iReadB]) {
            arrayC[iWriteC] = arrayA[iReadA];
            iWriteC++;
            iReadB++;
            iReadA++;
        } else if (arrayA[iReadA] > arrayB[iReadB])
            iReadB++;
        else
            iReadA++;
    }
    *sizeC = iWriteC;
}


//Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
//
//Получить упорядоченный по возрастанию массив С, содержащий все элементы массива А, которых нет в В.

void
task10(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    size_t iWriteC = 0;
    while (iReadA < *sizeA && iReadB < *sizeB) {
        if (arrayA[iReadA] < arrayB[iReadB]) {
            arrayC[iWriteC] = arrayA[iReadA];
            iReadA++;
            iWriteC++;
        } else if (arrayA[iReadA] == arrayB[iReadB]) {
            iReadA++;
            iReadB++;
        } else {
            iReadB++;
        }
    }
    if (iReadA != *sizeA) {
        while (iReadA < *sizeA) {
            arrayC[iWriteC] = arrayA[iReadA];
            iWriteC++;
        }
    }
    *sizeC = iWriteC;
}

//Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
//
//Получить упорядоченный по возрастанию массив С,
//
// содержащий все элементы массива А, которых нет в В и все элементы массива В, которых нет в А.
void
task11(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    size_t iWriteC = 0;
    while (iReadA < *sizeA && iReadB < *sizeB) {
        if (arrayA[iReadA] < arrayB[iReadB]) {
            arrayC[iWriteC] = arrayA[iReadA];
            iReadA++;
            iWriteC++;
        } else if (arrayA[iReadA] == arrayB[iReadB]) {
            iReadA++;
            iReadB++;
        } else {
            arrayC[iWriteC] = arrayB[iReadB];
            iReadB++;
            iWriteC++;
        }
    }
    while (iReadA != *sizeA) {
        arrayC[iWriteC] = arrayA[iReadA];
        iReadA++;
        iWriteC++;
    }
    while (iReadB != *sizeB) {
        arrayC[iWriteC] = arrayB[iReadB];
        iReadB++;
        iWriteC++;
    }
    *sizeC = iWriteC;
}

//Вариант 12
//
//Даны массивы натуральных чисел А и В, упорядоченные по возрастанию.
//
//Определить, верно ли, что массив В содержит каждый элемент массива А.
void
task12(int const *arrayA, const int *arrayB, int *arrayC, const size_t *sizeA, const size_t *sizeB, size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    if (*sizeA <= *sizeB) {
        while (iReadA < *sizeA && iReadB < *sizeB && arrayA[iReadA] >= arrayB[iReadB]) {
            if (arrayA[iReadA] == arrayB[iReadB]) {
                iReadA++;
                iReadB++;
            } else {
                iReadB++;
            }
        }
    }
    arrayC[0] = iReadA == *sizeA;
    *sizeC = 1;
}


void doTask(const size_t task, int *arrayA, int *arrayB, int *arrayC, size_t *sizeA, size_t *sizeB, size_t *sizeC) {
    switch (task) {
        case 1:
            task1(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 2:
            task2(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 3:
            task3(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 4:
            task4(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 5:
            task5(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 6:
            task6(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 7:
            task7(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 8:
            task8(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 9:
            task9(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 10:
            task10(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 11:
            task11(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        case 12:
            task12(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);
            break;
        default:
            break;
    }
}


int main() {
    size_t capacity = 100;
    size_t sizeA, sizeB, task;
    int arrayA[capacity];
    int arrayB[capacity];
    int arrayC[capacity * 2];
    size_t sizeC = 0;

    setTaskCondition(&task, arrayA, arrayB, &sizeA, &sizeB);

    doTask(task, arrayA, arrayB, arrayC, &sizeA, &sizeB, &sizeC);

    outputArray(arrayC, sizeC);

    return 0;
}