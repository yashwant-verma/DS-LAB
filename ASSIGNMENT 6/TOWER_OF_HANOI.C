/*Problem Statement: Write a recursive C function to solve the Tower of Hanoi
problem for n disks, where the function moves disks from a source rod to a target
rod using an auxiliary rod, while ensuring that a larger disk is never placed on a
smaller disk*/

#include <stdio.h>

void TOH(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    TOH(n - 1, source, target, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, target);
    TOH(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
    return 0;
}
