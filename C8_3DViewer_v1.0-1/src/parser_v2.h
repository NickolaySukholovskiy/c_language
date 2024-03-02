#ifndef S21_PARCER_V2_H
#define S21_PARCER_V2_H

#include <OpenGL/gl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 0
#define FAILURE -1

/**
 * @brief Структура, которая хранит в себе координаты точки
 */
typedef struct point {
  GLfloat x;
  GLfloat y;
  GLfloat z;
} point;
/**
 * @brief Структура, которая хранит в себе массив
 * индексов вершин, которые нужно соединить линией
 * Минимум массив должен содеражать 3 элемента
 */
typedef struct polygons {
  GLuint* faceElement;
  unsigned int amountOfFaceElements;
} polygons;

/**
 * @brief Структура, которая хранит в себе все координаты вершин,
 * количество вершин, и минимальные и максимальные значения X, Y, Z;
 */
typedef struct vertex {
  GLfloat* allVertecies;
  int amountOfPoints;
  GLfloat maxValueOfCoords;
} vertex;

/**
 * @brief Структура, которая хранит в себе объект,
 * загруженный из файла
 */
typedef struct model {
  vertex* vrtx;
  polygons* plgns;
  int numOfPolygons;
} model;

/**
 * @brief Функция, которая парсит файл и заносит все нужные значения в
 * переменную d3model
 *
 * @param d3model Указатель на структуру, куда запишуться все занчения
 * @param objFile Указатель на файл, из которого будут парситься значения
 * @return int Возвращаем код ошибки
 */

/**
 * @brief Функция, которая парсит значения из .obj файла и заносит данные в
 * формат удобный для дальнейшего использования
 *
 * @param d3model структура 3д модели, содержащая вершины и индексы
 * @param filename название файла, из которого будет считана модель
 * @return int
 */
int modelParser(model* d3model, const char* filename);

/**
 * @brief Функция для отчистки памяти за считанной моделью
 *
 * @param d3model Указатель на модель
 */
void removemodel(model* d3model);

#endif
