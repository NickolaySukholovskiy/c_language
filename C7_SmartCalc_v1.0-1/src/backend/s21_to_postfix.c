
#include "s21_calc.h"

/**
 * @brief Фукнция добавляет новй элемент в стек
 *
 * @param top Указатель на вершину стека, если она NULL, то создаётся новый
 * элемент, который и становится вершиной
 * @param symbol Символ-оператор, который заносится в стек
 */

void push_to_stack_sym(stack **top, char symbol) {
  stack *new_element = (stack *)calloc(1, sizeof(stack));  // или struct
  new_element->operator_symbol = symbol;
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

void remove_from_stack_sym(stack **top) {
  stack *buf_ptr = (*top)->prev;
  free(*top);
  *top = buf_ptr;
}

/**
 * @brief Функция принимает на вход символ и проверяет на то, является ли он
 * цифрой
 *
 * @param symbol Символ для проверки
 * @return int Возвращает SUCCESS в случае, если символ число, а противном
 * случае возвращает FAILURE
 */
int is_digit(char symbol) {
  int output_result = FAILURE;

  if (symbol >= '0' && symbol <= '9') {
    output_result = SUCCESS;
  }

  return output_result;
}

/**
 * @brief Get the num from str object Функция считывает число из строки str,
 * параллельно занося его в postfix_str
 *
 * @param str Указатель на строку с префиксной записью выражения
 * @param postfix_str Указатель на строку с постфиксной записью выражению
 * @return int Возвращает SUCCESS, если функция завершилась успешно, если была
 * найдена ошибка, то возвращается FAILURE
 */

int get_num_from_str(char **str, char **postfix_str) {
  int output_result = SUCCESS;
  int flag_num = 0;

  while (is_digit(**str) == SUCCESS) {
    **postfix_str = **str;
    *str += 1;
    *postfix_str += 1;
    flag_num = 1;
  }

  if (**str == '.') {
    **postfix_str = '.';
    *str += 1;
    *postfix_str += 1;
    if (is_digit(**str) == SUCCESS && flag_num) {
      while (is_digit(**str) == SUCCESS) {
        **postfix_str = **str;
        *str += 1;
        *postfix_str += 1;
      }
    } else {
      output_result = FAILURE;
    }
  }

  if (**str == 'x') {
    if (!flag_num) {
      **postfix_str = **str;
      *postfix_str += 1;
      *str += 1;
    } else {
      output_result = FAILURE;
    }
  }

  if (output_result != FAILURE) {
    **postfix_str = ',';
    *postfix_str += 1;
  }

  return output_result;
}

/**
 * @brief Get the priority stack object Функция возвращает приоритет элемента на
 * вершине стека
 *
 * @param top Указатель на вершину стека
 * @return int Возвращает приоритет числа, находящегося на вершине стека
 */

int get_priority_stack(stack *top) {
  int output_result = -1;

  if (top == NULL) {
    output_result = -1;
  } else if (top->operator_symbol == '-' || top->operator_symbol == '+') {
    output_result = PRIORITY_1;
  } else if (top->operator_symbol == '*' || top->operator_symbol == '/') {
    output_result = PRIORITY_2;
  } else if (top->operator_symbol == 's' || top->operator_symbol == 'c' ||
             top->operator_symbol == 't' || top->operator_symbol == 'o' ||
             top->operator_symbol == 'i' || top->operator_symbol == 'a' ||
             top->operator_symbol == 'l' || top->operator_symbol == 'n' ||
             top->operator_symbol == 'q') {
    output_result = PRIORITY_3;
  } else if (top->operator_symbol == '^') {
    output_result = PRIORITY_4;
  } else if (top->operator_symbol == '~') {
    output_result = PRIORITY_5;
  }

  return output_result;
}

/**
 * @brief Get the priority str object Функция возвращает приоритет
 * элемента-указателя
 *
 * @param str Указатель на строку, где необходимо узнать приоритет оператора
 * @return int Возвращает приоритет числа, на который указывает str
 */

int get_priority_str(char **str) {
  int output_result = -1;

  if (**str == '-' || **str == '+') {
    output_result = PRIORITY_1;
  } else if (**str == '*' || **str == '/' || **str == '%') {
    output_result = PRIORITY_2;
  } else if (**str == '^') {
    output_result = PRIORITY_4;
  } else if (**str == '~') {
    output_result = PRIORITY_5;
  } else {
    output_result = PRIORITY_3;
  }

  return output_result;
}

/**
 * @brief Get the push symbol object Функция преобразовывает функции длиной в
 * несколько символов в одиночный символ
 *
 * @param str Указатель на строку, где встретилась функция
 * @return char Возвращает один символ, эквивалентный функции из нескольких
 * символов
 */

char get_push_symbol(char **str) {
  int output_result = '0';

  if (**str == 's') {
    if (*(*str + 1) == 'i') {
      output_result = 's';
      *str += 2;
    } else {
      output_result = 'q';
      *str += 3;
    }
  } else if (**str == 'c') {
    output_result = 'c';
    *str += 2;
  } else if (**str == 't') {
    output_result = 't';
    *str += 2;
  } else if (**str == 'a') {
    if (*(*str + 1) == 's') {
      output_result = 'i';
    } else if (*(*str + 1) == 'c') {
      output_result = 'o';
    } else {
      output_result = 'a';
    }
    *str += 3;
  } else if (**str == 'l') {
    if (*(*str + 1) == 'o') {
      output_result = 'l';
      *str += 2;
    } else {
      output_result = 'n';
      *str += 1;
    }
  }

  return output_result;
}

/**
 * @brief Функция обрабатывает скобки в выражении
 *
 * @param func_stack Указатель на вершину стека с символами-операторами
 * @param str Указатель на строку в префиксной записи
 * @param postfix_str Указатель на строку в постфиксной записи
 * @return int Возвращает SUCCESS, если функция завершилась успешно, если была
 * найдена ошибка, то возвращается FAILURE
 */

int work_with_bracket(stack **func_stack, char **str, char **postfix_str) {
  int output_result = SUCCESS;

  if (**str == '(') {
    push_to_stack_sym(func_stack, '(');
  } else {
    while (*func_stack != NULL && (*func_stack)->operator_symbol != '(') {
      **postfix_str = (*func_stack)->operator_symbol;
      *postfix_str += 1;
      remove_from_stack_sym(func_stack);
    }
    if (*func_stack == NULL || (*func_stack)->operator_symbol != '(') {
      output_result = FAILURE;
    } else {
      remove_from_stack_sym(func_stack);
    }
    if (get_priority_stack(*func_stack) == PRIORITY_4) {
      **postfix_str = (*func_stack)->operator_symbol;
      *postfix_str += 1;
      remove_from_stack_sym(func_stack);
    }
  }

  *str += 1;

  return output_result;
}

/**
 * @brief Get the operator from str object Функция берёт оператор из строки в
 * инфиксном виде и заносит его в стек
 *
 * @param func_stack Указатель на вершину стека с символами-операторами
 * @param str Указатель на строку в префиксной записи
 * @param postfix_str Указатель на строку в постфиксной записи
 * @return int Возвращает SUCCESS, если функция завершилась успешно, если была
 * найдена ошибка, то возвращается FAILURE
 */

int get_operator_from_str(stack **func_stack, char **str, char **postfix_str) {
  int output_result = SUCCESS;
  int priority = -1;

  if (is_digit(**str) == FAILURE && **str != '\0' && output_result == SUCCESS) {
    if (**str == '(' || **str == ')') {
      output_result = work_with_bracket(func_stack, str, postfix_str);
    } else {
      priority = get_priority_str(str);

      while (*func_stack != NULL &&
             get_priority_stack(*func_stack) >= priority) {
        **postfix_str = (*func_stack)->operator_symbol;
        *postfix_str += 1;
        remove_from_stack_sym(func_stack);
      }

      priority = -1;
      char symbol = get_push_symbol(str);
      if (symbol == '0') {
        symbol = **str;
      }
      push_to_stack_sym(func_stack, symbol);
      *str += 1;
    }
  }

  return output_result;
}

/**
 * @brief Функция переводит число из префиксной записи в постфиксную
 *
 * @param str Указатель на строку в префиксной записи
 * @param postfix_str Указатель на строку в постфиксной записи
 * @return int Возвращает SUCCESS, если функция завершилась успешно, если была
 * найдена ошибка, то возвращается FAILURE
 */

int string_parser_to_postfix(char **str, char **postfix_str) {
  int output_result = SUCCESS;
  stack *func_stack = NULL;
  int flag_empty_postfix_str = 0;

  while (**str && output_result == SUCCESS) {
    if (is_digit(**str) == SUCCESS || **str == 'x' || **str == '.') {
      output_result = get_num_from_str(str, postfix_str);
    } else {
      if (**str == '-') {
        if (!flag_empty_postfix_str) {
          **str = '~';
        } else {
          if (*(*str - 1) == '(') {
            **str = '~';
          }
        }
      }
      output_result = get_operator_from_str(&func_stack, str, postfix_str);
    }
    flag_empty_postfix_str = 1;
  }

  while (func_stack != NULL && output_result == SUCCESS) {
    if (func_stack->operator_symbol == '(') {
      output_result = FAILURE;
    } else {
      **postfix_str = func_stack->operator_symbol;
      *postfix_str += 1;
    }
    remove_from_stack_sym(&func_stack);
  }

  **postfix_str = '\0';

  return output_result;
}
