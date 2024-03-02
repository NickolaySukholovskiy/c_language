#ifndef S21_CALC_H
#define S21_CALC_H

#include <math.h>
#include <stdio.h>  // убрать потом
#include <stdlib.h>
#include <string.h>

#define SIZE 256  // last symbol for '\0'

enum {
  PRIORITY_0 = 0,  // скобки
  PRIORITY_1,      // плюс/минус
  PRIORITY_2,      // умножить/делить
  PRIORITY_3,      // степень
  PRIORITY_4,      // тригонометрия/корень
  PRIORITY_5,      // унарный минус
};

// sin  = s
// cos  = c
// tan  = t
// acos = o
// asin = i
// atan = a
// sqrt = q
// log  = l // логарифм с основанием 10
// ln   = n // логарифм с основанием e
// mod  = m // остаток от деления

#define SUCCESS 0
#define FAILURE 1
// #define FAILURE_1 // проблема с унарным минусом
// #define FAILURE_2 // проблема с скобками
// #define FAILURE_3 // проблема с арифметическим выражением
// #define FAILURE_4 // проблема в записи точки

typedef struct stack {
  double number;
  char operator_symbol;
  struct stack *prev;
} stack;

/**
 * @brief Функция принимает на вход символ и проверяет на то, является ли он
 * цифрой
 *
 * @param symbol Символ для проверки
 * @return int Возвращает SUCCESS в случае, если символ число, а противном
 * случае возвращает FAILURE
 */
int is_digit(char symbol);

/**
 * @brief Функция переводит число из префиксной записи в постфиксную
 *
 * @param str Указатель на строку в префиксной записи
 * @param postfix_str Указатель на строку в постфиксной записи
 * @return int Возвращает SUCCESS, если функция завершилась успешно, если была
 * найдена ошибка, то возвращается FAILURE
 */
int string_parser_to_postfix(char **str, char **postfix_str);

/**
 * @brief Функция принимает строку с постфиксной записью числа и возврает
 * итоговый результат выражения
 *
 * @param postfix_str Указатель на строку с постфиксной записью
 * @param result Указатель, куда будет записан результат
 * @param x Значение числа x
 * @return int Возвращает SUCCESS, если операция прошла успешно, в противном
 * случае возвращет FAILURE
 */
int from_postfix_to_result(char **postfix_str, double *result, double x);

/**
 * @brief Функция переводит число из префиксной записи в постфиксную
 *
 * @param str Указатель на строку в префиксной записи
 * @param postfix_str Указатель на строку в постфиксной записи
 * @return int Возвращает SUCCESS, если функция завершилась успешно, если была
 * найдена ошибка, то возвращается FAILURE
 */
int string_parser_to_postfix(char **str, char **postfix_str);

int s21_connect_number(char *prefix_str, double *result);

/**
 * @brief Функция подсчитывает ежемесячный аннуитентный платёж для кредита
 *
 * @param ammount Сумма кредита
 * @param percent Процент по кредиту
 * @param months Срок кредита в месяцах
 * @param result Указатель, куда будет записан ежемесячный платёж по кредиту
 */
void annuitent_function(double ammount, double percent, int months,
                        double *result);

/**
 * @brief Функция подсчитывает ежемесячный дифференциальный платёж для кредита
 *
 * @param ammount Сумма кредита
 * @param percent Процент по кредиту
 * @param months Срок кредита в месяцах
 * @param result_1 Указатель, куда будет записан первый платёж по кредиту
 * @param result_2 Указатель, куда будет записан последний платёж по кредиту
 * @param result_percent Указатель, куда будет записана переплата по кредиту
 */
void differential_function(double ammount, double percent, int months,
                           double *result_1, double *result_2,
                           double *result_percent);

/**
 * @brief Фукнция считает количество платёжных единиц, которые можно получить
 * при определённых условиях вклада
 *
 * @param ammount Сумма кредита
 * @param percent Процент по кредиту
 * @param months Срок кредита в месяцах
 * @param result Возвращает сумму, которую человек получит после закрытия вклада
 */
void contribution_function(double ammount, double percent, int months,
                           double *result);

#endif
