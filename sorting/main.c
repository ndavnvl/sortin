#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define BUBLE_SORTING


#ifdef BUBLE_SORTING

int compare_ascend(long double first_number, long double second_number) {

	if (first_number < second_number) {
		return 0;
	}
	else {
		return 1;
	}

}


int compare_descend(long double first_number, long double second_number) {

	if (first_number > second_number) {
		return 0;
	}
	else {
		return 1;
	}

}


int compare_ascend_abs(long double first_number, long double second_number) {

	if (fabs(first_number) < fabs(second_number)) {
		return 0;
	}
	else {
		return 1;
	}

}


int compare_descend_abs(long double first_number, long double second_number) {

	if (fabs(first_number) > fabs(second_number)) {
		return 0;
	}
	else {
		return 1;
	}

}


int replace(long double *first_el_ptr, long double *second_el_ptr) {

	long double tmp = 0;

	tmp = *first_el_ptr;
	*first_el_ptr = *second_el_ptr;
	*second_el_ptr = tmp;
	return 0;
}


int sort_array(long double *input_array_ptr, long long int number_of_el, int compare_func(long double, long double)) {

	for (long long int i = number_of_el; i > 0; i--) {

		for (long long int j = 0; j < i - 1; j++) {

			if (compare_func(*(input_array_ptr + j), *(input_array_ptr + j + 1))) {
				replace(input_array_ptr + j, input_array_ptr + j + 1);
			}

		}

	}

	return 0;
}

#endif // BUBLE_SORTING


int main() {
	printf("This programm generates an array of random numbers with input parameters and sorts it.\n\n");

	for (int cont = 1; cont;) {
		printf("In all following inputs if you input extra elements they will be ignored but if you input\nan invalid element insted of an excepted one the programm will be restarted.\n\nInput a number of elements in the array.\n");

		long long int num_of_el = 1;

		for (int err = 0; (err = (scanf_s("%lli", &num_of_el) != 1)) || num_of_el <= 0;) {
			ungetc('~', stdin);

			while (getchar() != '\n');

			if (err) {
				printf("\nYou have input not a number. Please, try again...\n");
			}
			else {
				printf("\nYou have input invalid number. It must be more than 0. Please, try again...\n");
			}

		}

		ungetc('~', stdin);

		while (getchar() != '\n');

		printf("\nInput a range of the elements in the following format \"lower_limit upper_limit\".\n");

		long double lower_limit = 0;
		long double upper_limit = 1;
		
		for (int err = 0; (err = (scanf_s("%Lf %Lf", &lower_limit, &upper_limit) != 2)) || \
			lower_limit > upper_limit;) {

			ungetc('~', stdin);

			while (getchar() != '\n');
			
			if (err) {
				printf("\nYou have input not a number. Please, try again...\n");
			}
			else {
				printf("\nLower limit must be less than upper limit. Please, try again...\n");
			}

		}

		ungetc('~', stdin);

		while (getchar() != '\n');

		printf("\nInput direction of sorting according to a following table\ninput 1 if you want to sort the array ascending\ninput 2 if you want to sort the array descending\ninput 3 if you want to sort the array ascending of absolute values\ninput 4 if you want to sort the array descending of absolute values\n\n");
		
		int direction = 0;

		for (int err = 0; (err = (scanf_s("%d", &direction) != 1)) || direction > 4 || \
			direction < 1;) {

			ungetc('~', stdin);

			while (getchar() != '\n');

			if (err) {
				printf("\nYou have input not a number. Please, try again...\n");
			}
			else {
				printf("\nInput number is out of range. It must be more than 0 and less than 5. Please, try again...\n");
			}

		}

		srand(time(NULL));

		long double *input_arr_ptr = (long double *)malloc(num_of_el * sizeof(long double));
		long double range = upper_limit - lower_limit;

		printf("\nUnsorted array:\n");

		for (int i = 0; i < num_of_el; i++) {
			printf("%Lf\t", *(input_arr_ptr + i) = lower_limit + range * rand() / RAND_MAX);
		}

		switch (direction) {
		case 1:
			sort_array(input_arr_ptr, num_of_el, compare_ascend);
			break;
		case 2:
			sort_array(input_arr_ptr, num_of_el, compare_descend);
			break;
		case 3:
			sort_array(input_arr_ptr, num_of_el, compare_ascend_abs);
			break;
		case 4:
			sort_array(input_arr_ptr, num_of_el, compare_descend_abs);
			break;
		}
		
		printf("\n\nSorted array:\n");

		for (int i = 0; i < num_of_el; i++) {
			printf("%Lf\t", *(input_arr_ptr + i));
		}
		
		printf("\n\nIf you want to do it again with another parameters input 1, else input 0\n");

		while (scanf_s("%d", &cont) != 1) {
			ungetc('~', stdin);

			while (getchar() != '\n');

			printf("\nTry again...\n\n");
		}

		ungetc('~', stdin);

		while (getchar() != '\n');

		printf("\n");
	}

	return 0;
}