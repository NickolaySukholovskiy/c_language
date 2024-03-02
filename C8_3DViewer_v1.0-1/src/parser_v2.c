#include "parser_v2.h"

#include <time.h>
#include <unistd.h>

void removemodel(model* d3model);
void MaxCoordSet(model* d3Model, float x, float y, float z);
void normalization(model* d3Model);

// int main() {
//   double timeSpent = 0.;
//   FILE* ballerinaFile = fopen("ballerina.obj", "r");
//   model* d3model = (model*)calloc(1, sizeof(model));

//   clock_t begin = clock();
//   int numOfVertexes = modelParser(d3model, "ballerinacopy.obj");
//   clock_t end = clock();
//   timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;
//   printf("Time to parse: %lf, numOfVertexes: %d, numOfPolygons: %d\n",
//   timeSpent, numOfVertexes / 3, d3model->numOfPolygons);

//   begin = clock();

//   // for (int i = 0; i < d3model->vrtx->amountOfPoints; i++) {
//   //   printf("%f ", (float)d3model->vrtx->allVertecies[i]);
//   //     if(i % 3 == 0){printf("\n");}
//   // }
//   // for( int i = 0; i < d3model->numOfPolygons; i++){
//   //   printf("f ");
//   //   for(unsigned int j = 0; j < d3model->plgns[i].amountOfFaceElements;
//   j++){
//   //     printf("%u ", d3model->plgns[i].faceElement[j]);
//   //   }
//   //   printf("\n");
//   // }

//   // print("max/min value: %f", d3model->vrtx->maxValueOfCoords);

//   end = clock();
//   timeSpent = 0;
//   timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;
//   printf("Time to multiply by number: %f\n", timeSpent);
//   FILE* t = fopen("test_out.txt", "w");

//   fclose(t);
//   removemodel(d3model);
//   fclose(ballerinaFile);
//   return 0;
// }

int parsePoints(point* coordinata, char* line) {
  char* endptr = NULL;
  coordinata->x = (GLfloat)strtof(line, &endptr);
  coordinata->y = (GLfloat)strtof(endptr, &endptr);
  coordinata->z = (GLfloat)strtof(endptr, &endptr);

  return endptr == NULL ? 0 : 1;
}

char* rewindToSpace(char* line) {
  if (line != NULL) {
    while ((*line != '\n' || *line != '\r') && *line != '\0' && *line != ' ') {
      line++;
    }
    if (*line == ' ') line++;
  }
  return line;
}

int parsePolygons(polygons* plgn, char* line) {
  char* endptr = line;
  int polygonCounter = 0;
  plgn->faceElement = NULL;

  while (*endptr != '\n' && *endptr != '\r' && *endptr != '\0') {
    plgn->faceElement = (GLuint*)realloc(plgn->faceElement,
                                         (polygonCounter + 1) * sizeof(GLuint));
    plgn->faceElement[polygonCounter++] =
        (GLuint)strtol(endptr, &endptr, 10) - 1;
    endptr = rewindToSpace(endptr);
  }
  plgn->amountOfFaceElements = polygonCounter;
  // if(polygonCounter > 3) endptr = NULL;
  return endptr == NULL;
}

int modelParser(model* d3model, const char* filename) {
  if (filename == NULL) return FAILURE;
  FILE* objFile = fopen(filename, "r");
  if (d3model == NULL) return FAILURE;
  if (objFile == NULL) return FAILURE;
  int countVertex = 0;
  int countPolygons = 0;
  size_t bufferSize = 512;
  char* line = NULL;
  d3model->vrtx = (vertex*)calloc(1, sizeof(vertex));
  d3model->vrtx->allVertecies = NULL;
  d3model->plgns = NULL;
  while (getline(&line, &bufferSize, objFile) > 0) {
    // realloc array of pointers and add new point
    point coordinate = {0};
    polygons pl = {0};
    if (*line == 'v' && *(line + 1) == ' ') {
      parsePoints(&coordinate, (line + 2));
      countVertex += 3;
      d3model->vrtx->allVertecies = (GLfloat*)realloc(
          d3model->vrtx->allVertecies, countVertex * sizeof(GLfloat));
      d3model->vrtx->allVertecies[countVertex - 3] = coordinate.x;
      d3model->vrtx->allVertecies[countVertex - 2] = coordinate.y;
      d3model->vrtx->allVertecies[countVertex - 1] = coordinate.z;
      MaxCoordSet(d3model, coordinate.x, coordinate.y, coordinate.z);
    } else if (*line == 'f' && *(line + 1) == ' ') {
      int err = parsePolygons(&pl, (line + 1));
      if (err) continue;
      d3model->plgns =
          realloc(d3model->plgns, (countPolygons + 1) * sizeof(polygons));
      d3model->plgns[countPolygons++] = pl;
    }
  }
  d3model->numOfPolygons = countPolygons;
  d3model->vrtx->amountOfPoints = countVertex;
  normalization(d3model);
  // printf("amount of vertexes: %d\n", countVertex);
  free(line);
  fclose(objFile);
  return 0;
}

void removemodel(model* d3model) {
  if (d3model != NULL) {
    if (d3model->plgns != NULL) {
      for (int i = 0; i < d3model->numOfPolygons; i++) {
        free(d3model->plgns[i].faceElement);
      }
      free(d3model->plgns);
    }
  }
  if (d3model->vrtx && d3model->vrtx->allVertecies) {
    free(d3model->vrtx->allVertecies);
    free(d3model->vrtx);
  }
  free(d3model);
}

void normalization(model* d3Model) {
  for (int i = 0; i <= d3Model->vrtx->amountOfPoints; ++i)
    d3Model->vrtx->allVertecies[i] /= d3Model->vrtx->maxValueOfCoords;
}

void MaxCoordSet(model* d3Model, float x, float y, float z) {
  d3Model->vrtx->maxValueOfCoords = d3Model->vrtx->maxValueOfCoords < fabs(x)
                                        ? fabs(x)
                                        : d3Model->vrtx->maxValueOfCoords;
  d3Model->vrtx->maxValueOfCoords = d3Model->vrtx->maxValueOfCoords < fabs(y)
                                        ? fabs(y)
                                        : d3Model->vrtx->maxValueOfCoords;
  d3Model->vrtx->maxValueOfCoords = d3Model->vrtx->maxValueOfCoords < fabs(z)
                                        ? fabs(z)
                                        : d3Model->vrtx->maxValueOfCoords;
}
