#include <stdio.h>
#include <math.h>
#include <string.h>

void processCommand(double &x, double &y, double &teta, char *command, double number) {
    if (!strcmp(command, "fd")) {
        x += number*cos(teta*M_PI/180);
        y += number*sin(teta*M_PI/180);
    }
    else if (!strcmp(command, "bk")) {
        x -= number*cos(teta*M_PI/180);
        y -= number*sin(teta*M_PI/180);
    }
    else if (!strcmp(command, "lt")) {
        teta += number;
        teta = fmod(teta, 360);
    }
    else if (!strcmp(command, "rt")) {
        teta -= number;
        teta = fmod(teta, 360);
    }
}

double distance(double x, double y) {
    return round(sqrt(pow(x,2) + pow(y, 2)));
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        double x = 0;
        double y = 0;
        double teta = 0;

        for (int j = 0; j < N; j++) {
            char command[3];
            double number;
            scanf("%s %lf", command, &number);
            processCommand(x, y, teta, command, number);
        }

        printf("%d\n", int(distance(x, y)));
    }


    return 0;
}