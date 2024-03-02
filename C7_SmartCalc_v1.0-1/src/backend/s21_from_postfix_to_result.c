
// #include "s21_from_postfix_to_result.h"
// #include "s21_to_postfix.h"
#include "s21_calc.h"

/**
 * @brief Фукнция добавляет новй элемент в стек
 *
 * @param top Указатель на вершину стека, если она NULL, то создаётся новый
 * элемент, который и становится вершиной
 * @param number Число, которое будет добавлено в стек
 */

void push_to_stack_num(stack **top, double number) {
  // тут, возможно, требуется выделять память не только под структуру, но и под
  // все её составляющие
  stack *new_element = (stack *)calloc(1, sizeof(stack));  // или struct
  new_element->number = number;
  new_element->prev = NULL;
  if (top != NULL) {
    new_element->prev = *top;
  }
  *top = new_element;
}

/**
 * @brief Функция удаляет элемент, лежащий на вершине стека
 *
 * @param top Указатель на вершину стека
 */

void remove_from_stack_num(stack **top) {
  stack *buf_ptr = (*top)->prev;
  free(*top);
  *top = buf_ptr;
}

/**
 * @brief Get the number of elements in stack object Функция сравнивает
 * количество элементов в стеке с числом number
 *
 * @param top Указатель на вершину стека
 * @param number Количество элементов, которое минимально должно быть в стеке
 * @return int Возвращает FAILURE, если количество элементов в стеке меньше, чем
 * указано в number. В случае успеха возвращает SUCCESS
 */

int get_number_of_elements_in_stack(stack **top, int number) {
  int output_result = SUCCESS;

  if (number == 1) {
    if (*top == NULL) {
      output_result = FAILURE;
    }
  } else if (number == 2) {
    if (*top == NULL || (*top)->prev == NULL) {
      output_result = FAILURE;
    }
  }

  return output_result;
}

/**
 * @brief Get the uminus operator object Функция применяет оператор "унарный
 * минус" к элементам в стеке
 *
 * @param top Указатель на вершину стека
 * @return int Возвращает SUCCESS, если операция прошла успешно, в противном
 * случае возвращет FAILURE
 */

int get_uminus_operator(stack **top) {
  int output_result = SUCCESS;

  if (get_number_of_elements_in_stack(top, 1) == SUCCESS) {
    (*top)->number *= -1;
  } else {
    output_result = FAILURE;
  }

  return output_result;
}

/**
 * @brief Get the trigonometry operator object Функция применяет
 * оператор-функцию к элементам в стеке
 *
 * @param top Указатель на вершину стека
 * @param symbol Символ-оператор, который необходимо применить к числам в стеке
 * @return int Возвращает SUCCESS, если операция прошла успешно, в противном
 * случае возвращет FAILURE
 */

int get_trigonometry_operator(stack **top, char symbol) {
  int output_result = SUCCESS;
  double num_1 = 0, result = 0;

  if (get_number_of_elements_in_stack(top, 1) == SUCCESS) {
    num_1 = (*top)->number;
    remove_from_stack_num(top);

    if (symbol == 's') {
      push_to_stack_num(top, sin(num_1));
    } else if (symbol == 'c') {
      push_to_stack_num(top, cos(num_1));
    } else if (symbol == 't') {
      push_to_stack_num(top, tan(num_1));
    } else if (symbol == 'o') {
      push_to_stack_num(top, acos(num_1));
    } else if (symbol == 'i') {
      push_to_stack_num(top, asin(num_1));
    } else if (symbol == 'a') {
      push_to_stack_num(top, atan(num_1));
    } else if (symbol == 'q') {
      if (num_1 < 0) {
        output_result = FAILURE;
      } else {
        push_to_stack_num(top, sqrt(num_1));
      }
    } else if (symbol == 'l' || symbol == 'n') {
      if (num_1 <= 0) {
        output_result = FAILURE;
      } else {
        result = symbol == 'l' ? log10(num_1) : log(num_1);
        push_to_stack_num(top, result);
      }
    }
  } else {
    output_result = FAILURE;
  }

  return output_result;
}

/**
 * @brief Get the pow operator object Функция применяет оператор "степень" к
 * элементам в стеке
 *
 * @param top Указатель на вершину стека
 * @param symbol Символ-оператор, который необходимо применить к числам в стеке
 * @return int Возвращает SUCCESS, если операция прошла успешно, в противном
 * случае возвращет FAILURE
 */

int get_pow_operator(stack **top, char symbol) {
  int output_result = SUCCESS;
  double num_1 = 0, num_2 = 0;

  if (get_number_of_elements_in_stack(top, 2) == SUCCESS) {
    num_1 = (*top)->number;
    remove_from_stack_num(top);
    num_2 = (*top)->number;
    remove_from_stack_num(top);

    if (symbol == '^') {
      push_to_stack_num(top, pow(num_2, num_1));
    }
  } else {
    output_result = FAILURE;
  }

  return output_result;
}

/**
 * @brief Get the div mul operator object Функция применяет оператор деления или
 * умножения к элементам в стеке
 *
 * @param top Указатель на вершину стека
 * @param symbol Символ-оператор, который необходимо применить к числам в стеке
 * @return int Возвращает SUCCESS, если операция прошла успешно, в противном
 * случае возвращет FAILURE
 */

int get_div_mul_operator(stack **top, char symbol) {
  int output_result = SUCCESS;
  double num_1 = 0, num_2 = 0;

  if (get_number_of_elements_in_stack(top, 2) == SUCCESS) {
    num_1 = (*top)->number;
    remove_from_stack_num(top);
    num_2 = (*top)->number;
    remove_from_stack_num(top);

    if (symbol == '*') {
      push_to_stack_num(top, num_2 * num_1);
    } else if (symbol == '/') {
      if (num_1 == 0) {
        output_result = FAILURE;
      } else {
        push_to_stack_num(top, num_2 / num_1);
      }
    } else {
      if (num_1 == 0) {
        output_result = FAILURE;
      } else {
        push_to_stack_num(top, fmod(num_2, num_1));
      }
    }
  } else {
    output_result = FAILURE;
  }

  return output_result;
}

/**
 * @brief Get the plus minus operator object Функция применяет оператор сложения
 * или вычитания к элементам в стеке
 *
 * @param top Указатель на вершину стека
 * @param symbol Символ-оператор, который необходимо применить к числам в стеке
 * @return int Возвращает SUCCESS, если операция прошла успешно, в противном
 * случае возвращет FAILURE
 */

int get_plus_minus_operator(stack **top, char symbol) {
  int output_result = SUCCESS;
  double num_1 = 0, num_2 = 0;

  if (get_number_of_elements_in_stack(top, 2) == SUCCESS) {
    num_1 = (*top)->number;
    remove_from_stack_num(top);
    num_2 = (*top)->number;
    remove_from_stack_num(top);

    if (symbol == '-') {
      push_to_stack_num(top, num_2 - num_1);
    } else {
      push_to_stack_num(top, num_2 + num_1);
    }
  } else {
    output_result = FAILURE;
  }

  return output_result;
}

/**
 * @brief Get the operator from postfix str object Функция смотрит оператор, на
 * который указывает str, а затем передаёт его в соответствующую функцию для
 * дальнейшей работы
 *
 * @param top Указатель на вершину стека
 * @param symbol Символ-оператор, который необходимо применить к числам в стеке
 * @return int Возвращает SUCCESS, если операция прошла успешно, в противном
 * случае возвращет FAILURE
 */

int get_operator_from_postfix_str(stack **top, char **postfix_str) {
  int output_result = SUCCESS;

  if (**postfix_str == '-' || **postfix_str == '+') {
    output_result = get_plus_minus_operator(top, **postfix_str);
  } else if (**postfix_str == '/' || **postfix_str == '*' ||
             **postfix_str == '%') {
    output_result = get_div_mul_operator(top, **postfix_str);
  } else if (**postfix_str == '^') {
    output_result = get_pow_operator(top, **postfix_str);
  } else if (**postfix_str == 's' || **postfix_str == 'c' ||
             **postfix_str == 't' || **postfix_str == 'o' ||
             **postfix_str == 'i' || **postfix_str == 'a' ||
             **postfix_str == 'l' || **postfix_str == 'n' ||
             **postfix_str == 'q') {
    output_result = get_trigonometry_operator(top, **postfix_str);
  } else if (**postfix_str == '~') {
    output_result = get_uminus_operator(top);
  }

  *postfix_str += 1;

  return output_result;
}

/**
 * @brief Get the number from str object Функция считывает число из строки
 * postfix_str и заносит его в стек
 *
 * @param top Указатель на вершину стека
 * @param postfix_str Указатель на строку, откуда считываем число
 * @param x Если находим в строке x, то заменяем его на это число
 */

void get_number_from_str(stack **top, char **postfix_str, double x) {
  double result = 0;
  int point_flag = 0;
  int ten = 1;

  while (is_digit(**postfix_str) == SUCCESS || **postfix_str == 'x') {
    if (**postfix_str == 'x') {
      result = x;
      *postfix_str += 1;
    } else {
      if (!point_flag) {
        result = result * 10 + **postfix_str - '0';
      } else {
        ten *= 10;
        double add_value = (**postfix_str - '0');
        add_value /= ten;
        result += add_value;
      }

      *postfix_str += 1;

      if (**postfix_str == '.') {
        point_flag = 1;
        *postfix_str += 1;
      }
    }
  }

  push_to_stack_num(top, result);
}

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

int from_postfix_to_result(char **postfix_str, double *result, double x) {
  size_t size = strlen(*postfix_str);
  int output_result = SUCCESS;
  stack *func_stack = NULL;
  *result = 0;
  while (output_result == SUCCESS && **postfix_str) {
    if (is_digit(**postfix_str) == SUCCESS || **postfix_str == 'x') {
      get_number_from_str(&func_stack, postfix_str, x);
    } else if (**postfix_str == ',') {
      *postfix_str += 1;
    } else {
      output_result = get_operator_from_postfix_str(&func_stack, postfix_str);
    }
  }

  if (output_result == SUCCESS) {
    *result = func_stack->number;
    *postfix_str -= size;
  } else {
    while (func_stack != NULL) {
      remove_from_stack_num(&func_stack);
    }
  }
  return output_result;
}