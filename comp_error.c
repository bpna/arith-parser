#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE 32
#define IN 1
#define NOTIN 0
#define NEWLINE 10

int main(int argc, char *argv)
{
        char str[100000];
        char word[100];
        for (int i = 0; i < 100; i++) {
                word[i] = '\0';
        }

        fgets(str, 100000, stdin);

        /* NR scores */
        double scores[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        int c = 69;
        int iter = 0;
        int wordcount = 0;
        int state = NOTIN;
        int curr_char = 0;
        double diff = 0.0;

        while (c != '\0') {
                if (wordcount == 11) {
                        wordcount = 0;
                        for (int i = 0; i < 11; i++) {
                                if (scores[i] != 0.0) {
                                        printf("%.2f ", scores[i]);
                                } else {
                                        printf("student_error ");
                                }
                        }
                        printf("\n");
                }
                c = str[iter];
                iter++;

                if (state == IN) {
                        if (c == SPACE || c == NEWLINE) {
                                word[curr_char] = '\0';
                                curr_char = 0;
                                if (strcmp(word, "student-NR")) {
                                        scores[wordcount] = atof(word);
                                        wordcount++;
                                }
                                state = NOTIN;
                        } else {
                                if (c != '(') {
                                        word[curr_char++] = c;
                                }
                        }
                } else {
                        if (c == SPACE) {
                                scores[wordcount++] = 0;
                                iter += 4;
                        } else {
                                if (c != '(') {
                                        word[curr_char++] = c;
                                        state = IN;
                                }
                        }
                }
        }

        return 0;
}
