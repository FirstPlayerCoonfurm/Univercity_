#include <stdio.h>
#include <math.h>

// Функция 18: Разворот массива
void F18(int c[], int n) {
  int i, j, k;
  for (i = 0, j = n - 1; i < j; i++, j--) {
    k = c[i];
    c[i] = c[j];
    c[j] = k;
  }
}

int F18_call() {
  // Пример 1: Разворот массива из 5 элементов
  int arr1[] = {1, 2, 3, 4, 5};
  F18(arr1, 5);
  printf("\nПример 1: ");
  for (int i = 0; i < 5; i++) printf("%d ", arr1[i]);

  // Пример 2: Разворот массива из 6 элементов
  int arr2[] = {10, 20, 30, 40, 50, 60};
  F18(arr2, 6);
  printf("\nПример 2: ");
  for (int i = 0; i < 6; i++) printf("%d ", arr2[i]);
  printf("\n");
  return 0;
}

// Функция 10: Поиск наиболее часто встречающейся заглавной буквы
char F10(char c[]) {
  char m, z = 'A'; // Инициализация z значением по умолчанию
  int n, s = 0, i;

  for (m = 'A'; m <= 'Z'; m++) {
    n = 0;
    for (i = 0; c[i] != '\0'; i++) {
      if (c[i] == m) n++;
    }
    if (n > s) {
      z = m;
      s = n;
    }
  }
  return z;
}

int F10_call() {
  // Пример 1: Строка с одной самой частой буквой
  char str1[] = "HELLO WORLD";
  char result1 = F10(str1);
  printf("\nПример 1: %c\n", result1);

  // Пример 2: Строка с несколькими буквами одинаковой частоты
  char str2[] = "ABBCCCDDDD";
  char result2 = F10(str2);
  printf("Пример 2: %c\n", result2);

  // Пример 3: Пустая строка
  char str3[] = "";
  char result3 = F10(str3);
  printf("Пример 3: %c (для пустой строки)\n", result3);

  return 0;
}

// Функция 5: Вычисление гиперболического синуса через ряд Тейлора
double sh_taylor_optimized(double x, int n_terms) {
  double sum = x;
  double term = x;

  for (int n = 2; n <= n_terms; ++n) {
    term *= x * x / ((2 * n - 2) * (2 * n - 1));
    sum += term;
  }
  return sum;
}

void sh_taylor_test() {
  const double x_start = 0.1;
  const double x_end = 1.0;
  const double x_step = 0.1;
  const int terms = 10;

  printf(" x   | Taylor (2) | Taylor (4) | Taylor (5) | Math lib   | Term -> 0?\n");
  printf("-----|------------|------------|------------|------------|------------\n");

  for (double x = x_start; x <= x_end + 1e-9; x += x_step) {
    double taylor = sh_taylor_optimized(x, terms);
    double exact = sinh(x);
    double last_term = x;

    for (int n = 2; n <= terms; n++) {
      last_term *= x * x / ((2 * n - 2) * (2 * n - 1));
    }

    printf("%.1f | %-10.2f | %-10.4f | %-10.5f | %-10.6f | %s\n",
           x, taylor, taylor, taylor, exact,
           fabs(last_term) < 1e-6 ? "Yes" : "No");
  }
}

int main() {
  printf("_______________\n");
  printf("Задача №1: перестановка элементов массива\n");
  F18_call();

  printf("_______________\n");
  printf("Задача №2: строки\n");
  F10_call();

  printf("_______________\n");
  printf("Задача №3: итерационные циклы\n");
  sh_taylor_test();

  printf("_______________\n");
  return 0;
}
