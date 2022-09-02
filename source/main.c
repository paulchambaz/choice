/**
 * @file main.c
 * @author Paul Chambaz
 * @date Sep 02 2022
 * @brief This is the main file of the project
 * @license GPLv2
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void copy_file_to_lines ( FILE *file, char ***str, size_t *len );

void exit_error ( char *message );

/**
 * @brief The main function
 * @param argc The number of arguments
 * @param argv The list of arguments
 */
int
main ( int argc, char *argv[] )
{
  char **lines;
  size_t number_lines;

  copy_file_to_lines(stdin, &lines, &number_lines);

  while (getchar() != EOF) { }

  FILE *tty = fopen("/dev/tty", "rw");
  if (!tty)
    exit_error("Error, could not open file");

  // prints the output
  for (int i = 0; i < number_lines; i++) {
    fprintf(stderr, "%d: %s\n", i + 1, lines[i]);
  }
  fprintf(stderr, "%d: Exit\n", number_lines + 1);


  int choice = 0;
  char answer[16];
  do {
    // gets the answer from user
    if (argc > 1) {
      fprintf(stderr, "%s (1-%d): ", argv[1], number_lines + 1);
    } else {
      fprintf(stderr, "Enter your choice (1-%d): ", number_lines + 1);
    }
    fgets(answer, 15, tty);
    choice = atoi(answer);
  } while (choice < 1 || choice > number_lines + 1);

  if (choice == number_lines + 1)
    exit(EXIT_SUCCESS);

  printf("%s\n", lines[choice - 1]);


  fclose(tty);


  exit(0);
}

/*
 * @brief Copies the lines of a file to a list of list of string
 * @param file The file to copy
 * @param lines The address of the lines to copy to
 * @param number_lines The address of the number of lines
 */
void
copy_file_to_lines ( FILE *file, char ***lines, size_t *number_lines )
{
  // TODO: this function needs commenting
  char c;
  size_t nb_lines = 1;
  int line_break = 0;
  size_t length = 1;
  size_t len = 0;
  int i = 0;

  *lines = (char **) malloc(nb_lines * sizeof(char *));
  (*lines)[0] = (char *) malloc(length * sizeof(char));
  if (!*lines || !(*lines)[0])
    exit_error("Error, not enough memory.");

  *number_lines = 0;
  while ((c = fgetc(file)) != EOF) {
    if (len > length) {
      length *= 2;
      (*lines)[*number_lines] = (char *) realloc((*lines)[*number_lines], length * sizeof(char));
      if (!(*lines)[*number_lines])
        exit_error("Error, not enough memory.");
    }
    if (*number_lines >= nb_lines) {
      nb_lines *= 2;
      *lines = (char **) realloc(*lines, nb_lines * sizeof(char *));
      if (!*lines)
        exit_error("Error, not enought memory.");
    }
    if (c == '\n' || c == '\0') {
      (*lines)[*number_lines][len] = '\0';
      (*lines)[*number_lines] = (char *) realloc((*lines)[*number_lines], len * sizeof(char));
      if (!(*lines)[*number_lines])
        exit_error("Error, not enough memory.");
      length = 1;
      len = 0;
      i = 0;
      (*number_lines)++;
      (*lines)[*number_lines] = (char *) malloc(length * sizeof(char));
    } else {
      (*lines)[*number_lines][len] = c;
      len++;
      i++;
    }
  }
}

void
exit_error ( char *message )
{
  if (message)
    fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}
