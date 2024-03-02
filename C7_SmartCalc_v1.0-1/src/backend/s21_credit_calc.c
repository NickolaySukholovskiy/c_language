
#include "s21_calc.h"

/**
 * @brief Функция подсчитывает ежемесячный аннуитентный платёж для кредита
 *
 * @param ammount Сумма кредита
 * @param percent Процент по кредиту
 * @param months Срок кредита в месяцах
 * @param result Указатель, куда будет записан ежемесячный платёж по кредиту
 */

void annuitent_function(double ammount, double percent, int months,
                        double *result) {
  double interest_rate = percent / 1200;
  *result = (interest_rate * pow(1 + interest_rate, months)) /
            (pow(1 + interest_rate, months) - 1);
  *result *= ammount;
}

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
                           double *result_percent) {
  double month_payment = ammount / months;
  *result_1 = month_payment + ammount * percent / 1200;

  for (int i = 0; i < months; i++) {
    *result_percent += ammount * percent / 1200;
    *result_2 = ammount * percent / 1200 + month_payment;
    ammount -= month_payment;
  }
}

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
                           double *result) {
  *result = ammount * percent * months / 1200;
  *result += ammount;
}