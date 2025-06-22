#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 100

void calculate_area(char shape, float *dims, float *result) {
    switch (shape) {
        case 'c': // Circle
            *result = M_PI * dims[0] * dims[0];
            break;
        case 't': // Triangle
            *result = 0.5 * dims[0] * dims[1];
            break;
        case 'r': // Rectangle
            *result = dims[0] * dims[1];
            break;
        case 's': // Square
            *result = dims[0] * dims[0];
            break;
        default:
            *result = -1;
            break;
    }
}

int main() {
    int to_child[2], to_parent[2];
    pid_t pid;

    if (pipe(to_child) == -1 || pipe(to_parent) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        
        close(to_child[1]); 
        close(to_parent[0]);

        char shape;
        float dims[2];
        read(to_child[0], &shape, sizeof(char));
        read(to_child[0], dims, sizeof(dims));

        float result;
        calculate_area(shape, dims, &result);

        write(to_parent[1], &result, sizeof(float));

        close(to_child[0]);
        close(to_parent[1]);
    } else {
        close(to_child[0]);  
        close(to_parent[1]);

        char shape;
        float dims[2] = {0.0, 0.0};

        printf("Choose shape (c: circle, t: triangle, r: rectangle, s: square): ");
        scanf(" %c", &shape);

        if (shape == 'c') {
            printf("Enter radius: ");
            scanf("%f", &dims[0]);
        } else if (shape == 't' || shape == 'r') {
            printf("Enter base/length: ");
            scanf("%f", &dims[0]);
            printf("Enter height/breadth: ");
            scanf("%f", &dims[1]);
        } else if (shape == 's') {
            printf("Enter side: ");
            scanf("%f", &dims[0]);
        } else {
            printf("Invalid shape\n");
            exit(1);
        }

       
        write(to_child[1], &shape, sizeof(char));
        write(to_child[1], dims, sizeof(dims));

       
        float result;
        read(to_parent[0], &result, sizeof(float));

        
        if (result >= 0)
            printf("Calculated area: %.2f\n", result);
        else
            printf("Error calculating area.\n");

        close(to_child[1]);
        close(to_parent[0]);
    }

    return 0;
}
/*
Choose shape (c: circle, t: triangle, r: rectangle, s: square): c
Enter radius: 7.0
Calculated area: 153.94

[2021ict100@fedora ~]$ ./cpipetwo
Choose shape (c: circle, t: triangle, r: rectangle, s: square): t
Enter base/length: 12
Enter height/breadth: 18
Calculated area: 108.00

Enter base/length: 10
Enter height/breadth: 18
Calculated area: 180.00

[2021ict100@fedora ~]$ ./cpipetwo
Choose shape (c: circle, t: triangle, r: rectangle, s: square): s
Enter side: 14
Calculated area: 196.00

*/