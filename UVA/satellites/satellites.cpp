#include <stdio.h>
#include <string.h>
#include <math.h>

int main() { 
    int s, a;       // Distance from the earth and angle from the other satelite
    char str[4];    // Says if the angle is in minutes or degrees

    while (scanf("%d %d %s", &s, &a, str) != EOF) {
        double radius = s + 6440;               // true radius of the circle
        double teta;                            // angle

        // The angle must be between 0 and 180, so we get the right arc and chord
        if (a > 180) teta = 360 - a;
        else teta = a;

        // If it's in minutes, convert to degrees
        if (!strcmp(str, "min")) teta = teta / 60.0;


        double arc = (radius * teta * M_PI) / 180;
        double chord = 2 * radius * sin(((teta * M_PI) / 180) / 2.0); 

        printf("%lf %lf\n", arc, chord);
    }

    return 0;
}