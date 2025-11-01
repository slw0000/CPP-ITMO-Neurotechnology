//
//  main.cpp
//  TasksSolutionCPP
//
//  Created by Artem Golubev on 31.10.2025.
//

#include <iostream>
#include <string>
#include <ranges>
#include <cmath>
#include <algorithm>
#include <sstream>



namespace Test
{
    void argregatorPersolalInfo(int age, double weight) {

        double height;
        std::wstring name{ L"Vladislav" }, description;

        std::wcout << "Name: " << name << "\n";
        std::wcout << "Age: " << age << " Weight: "
            << weight << std::endl;

        {
            std::wcout << "Enter height:" << std::endl;
            std::cin >> height;
            std::wcin >> description;
        }
    }

    void argregatorPersolalInfo()
    {
        argregatorPersolalInfo(27, 77.3);
    }
}

namespace problems
{
    // TO DO:
    /*
    * Дано трехзначное натуральное число N.
    * Нужно найти сумму цифр числа N
    */
    int problem1() {
        int N;
        std::cin >> N;
        return N % 10 + (N / 10) % 10 + N / 100;
    }

    int problem1Alt() {
        int N;
        std::cin >> N;

        auto acc{ 0 };
        while (N) {
            acc += N % 10;
            N /= 10;
        }

        return acc;
    }

    int problem1Perfect() {
        std::string number_str;
        std::cin >> number_str;

        auto acc{ 0 };

        for (auto symbol : number_str)
            acc += symbol - '0';
        return acc;
    }

    /*
        Дано натуральное шести значное число n,
        найти сумму его четных и нечетных элементов
        и вывести их на экран подряд.
        
        Пример: 531277
        Результат: 1312
    */

    std::pair<int, int> problem2() {
        std::string n;
        std::cin >> n;
        auto accEven = 0, accNotEven = 0;
        for (int i = 0; i < 6; i++)
        {
            if (i % 2 == 0){
                accEven += n[i] - '0';
            } else {
                accNotEven += n[i] - '0';
            }
        }
        return { accEven, accNotEven };
    }

    /*
    На вход подается натуральное число k.
    На вход подается натуральное число n.
    И затем подается n натуральных чисел.
    Нужно найти количество числе равных числу k.

    Пример:
    17
    4
    15
    16
    17
    18

    Результат: 1

    */

    int problem3()
    {
        int k, n;
        std::cin >> k >> n;
        auto acc{ 0 };
        for (auto i = 0; i < n; i++)
        //while (n--)
        {
            int number;
            std::cin >> number;

            //acc += number == k;
            if (number == k)
               acc++;
        }
        return acc;
    }

    /*
    На вход подается натуральное число n.
    И затем подается n натуральных чисел.
    Нужно найти среднее арифметическое среди
    всех чисел кратных 3, если таких чисел нет, то вывести -1

    Пример:
    4
    15
    16
    17
    18

    Результат: 16.5
    */

    double problem4()
{
        int n;
        std::cin >> n;
        auto count{ 0.0 }, acc{ 0.0 };
        for (auto i = 0; i < n; i++)
        {
            int number;
            std::cin >> number;
            if (!(number % 3))
            {
                count++;
                acc += number;
            }
        }
        
        if (count)
            return acc / count;
        return -1;
    }


    /*
     Задача 5

     Вводится натуральное число N, а затем N целых чисел последовательности. Найдите количество минимальных элементов последовательности.

     Пример ввода:
     3
     21
     11
     4

     Пример вывода:
     1
     */
    int problem5(){
        int n;
        std::cin >> n;
        
        int minimum;
        std::cin >> minimum;
        
        int sum {1};
        for (int i = 1; i < n; i++){
            int cur_val;
            std::cin >> cur_val;
            
            if (cur_val < minimum){
                minimum = cur_val;
                sum = 1;
            } else if (cur_val == minimum){
                sum++;
            }
        }
        return sum;
    }


    /*
     Дано натуральное число A > 1.
     Определите, каким по счету числом Фибоначчи оно является, то есть выведите такое число n, что φn = A. Если А не является числом Фибоначчи, выведите число -1.

     Пример ввода:
     8

     Пример вывода:
     6
     */

    int problem6() {
        int A;
        std::cin >> A;
        
        int fp = 1;
        int fn = 1;
        
        int cur = 2;
        
        while (fn <= A){
            if (fn == A){
                return cur;
            }
            cur++;
            
            int temp_f = fn;
            fn = fn + fp;
            fp = temp_f;
        }
        return -1;
        
    }


    /*
     Задача 7

     Вводится два целых числа a и b. Найдите самое большее число на отрезке от a до b, кратное 7. Если такого числа нет выведите -1.

     Пример ввода:
     100
     500

     Пример вывода:
     497

     */


    int problem7(){
        int a, b;
        std::cin >> a >> b;
        
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        
        for (int i = b; i >= a; i--){
            if (i % 7 == 0){
                return i;
            }
        }
        return -1;
        
    }


    /*
     Задача 8
     
     В цепочках ДНК символы «А» и «Т» дополняют друг друга, как «С» и «G». Нужно написать программу, которая получает на вход последовательность ДНК и на выходе отображает комлементарную ей.

     Пример ввода:
     GTAT

     Пример вывода:
     CATA
     */


    std::string problem8() {
        std::string dna;
        std::cin >> dna;
        
        for (int i = 0; i < dna.length(); i++) {
            if (dna[i] == 'A') dna[i] = 'T';
            else if (dna[i] == 'T') dna[i] = 'A';
            else if (dna[i] == 'C') dna[i] = 'G';
            else if (dna[i] == 'G') dna[i] = 'C';
        }

        return dna;
    }


    /*
     Задача 9

     По данному числу N распечатайте все целые значения степени двойки, не превосходящие N, в порядке возрастания.

     Пример ввода:
     50

     Пример вывода:
     1 2 4 8 16 32
     */

    
    void problem9(){
        int n;
        std::cin >> n;
        
        int result = 1;
        
        while (result <= n){
            std::cout << result << " ";
            result *= 2;
        }
    }



    /*
     Задача 10

     На ввод подаются N целых чисел, их нужно сохранить в массив или список. Затем вывести максимальный элемент.
     
     Пример ввода:
     5
     2
     3
     56
     45
     21

     Пример вывода:
     56
     */


    int problem10(){
        int n;
        std::cin >> n;
        
        std::vector<int> lst;
        
        for (int i = 0; i < n; i++) {
            int inp;
            std::cin >> inp;
            
            lst.push_back(inp);
        }
        
        int max_lst = *std::max_element(lst.begin(), lst.end());
        
        return max_lst;
    }


    /*
     Задача 11

     Сначала на вход поступает длина последовательности N. Затем элементы последовательности – целые числа. Напишите программу, которая подсчитывает количество положительных чисел среди элементов последовательности.

     Пример ввода:
     5
     1
     2
     3
     -1
     -4

     Пример вывода:
     3
     */


    int problem11(){
        int n;
        std::cin >> n;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            int cur_val;
            std::cin >> cur_val;
            
            if (cur_val > 0) {
                sum++;
            }
        }
            
        return sum;
        
    }


    /*
     Задача 12

     Напишите программу, которая в последовательности чисел находит сумму двузначных чисел, кратных 8. Программа в первой строке получает на вход число n − количество чисел в последовательности, во второй строке − n чисел, входящих в данную последовательность.

     Пример ввода:
     5
     38 24 800 8 16

     Пример вывода:
     40
     */


    int problem12(){
        int n;
        std::cin >> n;
        std::cin.ignore();
        
        std::string str;
        std::getline(std::cin, str);

        std::stringstream ss(str);
        int num;
        int sum = 0;
        
        while (ss >> num) {
            if ((num >= 10 && num <= 99) && (num % 8 == 0)) {
                sum += num;
            }
        }
        
        return sum;
        
    }



    /*
     Задача 13

     Последовательность состоит из натуральных чисел и завершается числом 0. Определите количество элементов этой последовательности, которые равны ее наибольшему элементу.

     Пример ввода:
     1
     3
     3
     1
     0

     Пример вывода:
     2
     */


    int problem13(){
        int n;
        std::cin >> n;
        
        int count = 1;
        int max = n;
        
        while (n != 0) {
            std::cin >> n;
            if (n > max) {
                count = 1;
                max = n;
            } else if (n == max) {
                count++;
            }
        }
        
        return count;
    }


    /*
     Задача 14

     Даны два числа. Определить цифры, входящие в запись как первого, так и второго числа. Программа должна вывести цифры, которые имеются в обоих числах, через пробел. Цифры выводятся в порядке их нахождения в первом числе.

     Пример ввода:
     564 8954

     Пример вывода:
     5 4
     */



    void problem14() {
        std::string str;
        std::getline(std::cin, str);

        std::stringstream ss(str);
        std::string num;
        std::vector<std::string> lst;
        
        std::vector<char> chars;
        
        while (ss >> num) {
            lst.push_back(num);
        }
        
        for (int i = 0; i < lst[0].length(); i++) {
            if (lst[1].find(lst[0][i]) != std::string::npos && std::find(chars.begin(), chars.end(), lst[0][i]) == chars.end()) {
                chars.push_back(lst[0][i]);
            }
        }
        
        for (int i = 0; i < chars.size(); i++) {
            std::cout << chars[i] << ' ';
        }
    }
}


int main() {
    problems::problem14();
//    auto result = problems::problem13();
//    std::cout << "Результат: " << result << std::endl;
}
