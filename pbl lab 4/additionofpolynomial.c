#include <stdio.h>
#include <stdlib.h>


struct Term {
    int coeff;     
    int exp;       
    struct Term* next; 
};

// Function to create a new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* last = NULL;   
    
    while (poly1 != NULL || poly2 != NULL) {
        struct Term* newTerm = NULL;

        // If poly1 is exhausted
        if (poly1 == NULL) {
            newTerm = createTerm(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        // If poly2 is exhausted
        else if (poly2 == NULL) {
            newTerm = createTerm(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        // If both terms are available
        else if (poly1->exp > poly2->exp) {
            newTerm = createTerm(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp) {
            newTerm = createTerm(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else { // Both exponents are equal
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                newTerm = createTerm(sumCoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (newTerm) {
            if (result == NULL) {
                result = newTerm;
                last = result;
            } else {
                last->next = newTerm; 
                last = newTerm;
            }
        }
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}


struct Term* inputPolynomial() {
    struct Term* head = NULL;
    struct Term* last = NULL;
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);

        struct Term* newTerm = createTerm(coeff, exp);

        if (head == NULL) {
            head = newTerm;
            last = head;
        } else {
            struct Term* current = head;
            struct Term* prev = NULL;

            // Find the correct position to insert the new term
            while (current != NULL && current->exp > exp) {
                prev = current;
                current = current->next;
            }

            // Insert at the beginning
            if (prev == NULL) {
                newTerm->next = head;
                head = newTerm;
            } 
            // Insert in the middle or end
            else {
                newTerm->next = current;
                prev->next = newTerm;
            }
        }
    }

    return head;
}

int main() {
    printf("Input first polynomial:\n");
    struct Term* poly1 = inputPolynomial();
    
    printf("Input second polynomial:\n");
    struct Term* poly2 = inputPolynomial();

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Adding polynomials
    struct Term* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
