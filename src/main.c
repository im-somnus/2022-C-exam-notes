#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main()
{
/*
	 * 	printf();
	 * 		thingies.
*/
//  // puts() function can be used too to print on screen
//	printf("hi\n");
//	printf("\thi\n");
//	printf("hi");
//	printf("\n");
//	int i = 5;
//	printf("\t");
//	printf("%d\n", i);
//	printf("The number is: %d\n", i);
//	printf("The number is: [%d]\n", i);
//	printf("The number is: \"%d\"\n", i);
// 	printf("\"); // would throw error, cause incomplete " pair.
//	double d = 3;
//	printf("%lf\n", d); // can use %f too, but scanf uses %lf
//
//	float f = 7;
//	printf("%f\n", f);
//
//	char name[] = "john doe\n";
//	printf("%s", name); // We dont add \n, string has it at the end
//	int numOfCharacters = 123456; // you can see the difference on %6d vs %7d
//	printf("%6d\n", numOfCharacters);
//	printf("%7d\n", numOfCharacters);
//
//	int leftAlign = 0; // You can see the 0 is aligned to the left
//	printf("%-5d%d\n", leftAlign, numOfCharacters);
//
//	int rightAlign = 0; // You can see the 0 is aligned to the right
//	printf("%5d%d\n", rightAlign, numOfCharacters);
//	float numOfDecimals = 5.295; // if you use 5.294 it will output 5.29 instead of 5.30
//	printf("%.2f\n", numOfDecimals); // This will output 2 decimals only (rounded)
//	printf("%-8.2fhello\n", numOfDecimals); // left align. Change 8 to see the difference
//
//	int v1 = 3;
//	float v2 = 5.3;
//	char str[5] = "hello";
//	printf("%.5d %5f %.3s\n",v1, v2, str);
//	printf("%.5d %.5f %.3s",v1, v2, str);
//
/*
	 * 	datatype;
	 * 		thingies.
 */
//
/*	//	   Type    	// 			Description	       		// 	    Size
	char 			// Byte 					   		// 		 1
	int 			// Integer 					   		// 		 4
	float 			// Float with single precision 		//		 4
	double 			// Float with double precision 		// 		 8
	short 			// Short					   		//		 2
	long int		// Large integer 			   		//		 8
	signed char	 	// Signed number [-128, +127]  		//		 1
	unsigned char 	// Positive number [0, 255]    		// 		 1
	signed int 		// Signed integer [-32768, 32767] 	//  	 4
	unsigned int 	x// Positive integer [0, 65535]    	//		 4
	long double 	// Float with extended precision  	//		16
*/
//
// 	// We can use sizeof() to know the size of any datatype/variable
//	printf(" [%d] bytes\n", (int) sizeof(char));
//	printf(" [%d] bytes\n", (int) sizeof(int));
//	printf(" [%d] bytes\n", (int) sizeof(float));
//	printf(" [%d] bytes\n", (int) sizeof(double));
//	printf(" [%d] bytes\n", (int) sizeof(short));
//	printf(" [%d] bytes\n", (int) sizeof(long int));
//	printf(" [%d] bytes\n", (int) sizeof(signed char));
//	printf(" [%d] bytes\n", (int) sizeof(unsigned char));
//	printf(" [%d] bytes\n", (int) sizeof(signed int));
//	printf(" [%d] bytes\n", (int) sizeof(unsigned int));
//	printf("[%d] bytes\n", (int) sizeof(long double));
//
/*
	 * 	array
	 * 		thingies.
	 *
	 *  Important:
	 *  	C does not check if you are going outside the bounds of the array.
*/
//
// 	// 				   0   1   2   3   4
//	char counters[] = {11, 22, 33, 44, 55}; // same as char counters[5];
//	printf("{[%d],", counters[0]);
//	printf("[%d],", counters[1]);
//	printf("[%d],", counters[2]);
//	printf("[%d],", counters[3]);
//	printf("[%d]}\n", counters[4]);
//
//	// To calculate the number of elements in an array
//	int length = sizeof(counters) / sizeof(counters[0]);
//
//	// This will output the same as the other 5 printf's above
//	// but much cleaner and for any number of items.
//	printf("{");
//
//	for (int i = 0; i < length-1; i++)
//	{
//		printf("[%d],", counters[i]);
//	}
//
//	printf("[%d]}", counters[length-1]);
//
//	// We can do something similar with loops to fill it
//	for (int i = 0; i < 5; i++)
//	{
//		counters[i] = i;
//	}
//
/*
	 *  struct;
	 * 		thingies.
*/
//
//	// We can declare more complext data types using structs
//	struct worker {
//		double salary;
//		int age;
//	};
//
//	struct worker w1;
//	w1.salary = 50.0;
//	w1.age = 1000;
//
//	printf("%.2f\n", w1.salary);
//	printf("%d\n", w1.age);

//	// We can also declare them this way, which makes it easier to create multiple:
//	typedef struct Point Point;
//	struct Point {
//		int x, y;
//	};
//
//	// We can initialize it like this too:
//	Point p1 = {5, 3};
//	printf("(%d %d)\n", p1.x, p1.y);
//
/*
	 * 	union;
	 * 		thingies.
*/
//
//	typedef union {
//		int a;
//		int b;
//	} data;
//
//	data d1;
//
//	// unlike the 8 bytes if we were using struct
//	// we'll just need 4 bytes in this union!
//	printf("sizeof: %d\n", (int) sizeof(d1));
//
//	d1.a = 5;
//	printf("d1.a: %d\n", d1.a);
//	d1.b = 6; // Sobrescribirá el valor de a por 6.
//	printf("d1.a after d1.b init to 6: %d\n", d1.a);
//	printf("d1.b: %d\n", d1.b);
//
/*
	 * 	enums;
	 * 		thingies.
*/
//
//	// 			0       1      2         3    ....and so on
//	enum bool {False, True, Nullified, Other = 9} var; // you can assign values independently.
//	var = Other;
//
//	if (var == 9)
//	{
//		printf("Hello");
//	}
//	else
//	{
//		printf("bye");
//	}
//
/*
	 * 	string;
	 * 		thingies.
*/
//
//	char name1[6] = "hello";
//	char name2[6] = {'h', 'e', 'l', 'l', 'o', '\0'}; // the same as above
//	char name3[6] = {'h', 'e', 'l', 'l', 'o'} ;	 // the same as above
//
//	/*
//	 * 	string functions
//		strcpy(a, b); <- copies b into a
//		strlen(a); 	  <- returns length, must end in '\0'
//		strcat(a, b); <- concatenates b into a
//		strcmp(a, b); <- compares a with b, 0 if equals
//	*/
//
//	if (!strcmp(name1, name2)) // if they are the same
//	{
//		printf("cmp print: ");
//		int i = 0;
//
//		while (name2[i] != '\0') // iterate until we reach the end of the string.
//		{
//			printf("%c", name2[i]);
//			i++;
//		}
//		printf("\n");
//	}
//
//	strcat(name3, name2); // concat name2 into name1
//	printf("cat print: [%s]\n", name3);
//
/*
	 * 	pointers;
	 * 		thingies.
*/
//  // Pointers point to the initial address of the object, that is, where it starts in memory.
//	int var = 5;
//	int *ptrVar = &var; // With &var, we return the mem address of the variable "var"
//
//	printf("%d\n", var);	// here we can see they have the same value.
//	printf("%d\n", *ptrVar);
//
//	*ptrVar = 1; // If we modify the pointer, we modify the variable we are pointing to
//
//	printf("%d\n", var);	// here we can see the value has changed.
//	printf("%d\n", *ptrVar);
//
//	int arr[3] = {5, 8, 12}; // Arrays are pointers too!
//	int *ptrArr = arr; // Since arrays are pointers, we dont have to use the &
//
//	ptrArr++; // Increase the pointer by sizeof(int), since our ptr is an int pointer.
//	printf("%d\n", *ptrArr); // We can see its pointing to 8 now
//
//	ptrArr++;ptrArr++; // Increase the pointer by sizeof(int), since our ptr is an int pointer.
//	printf("%d\n", *ptrArr); // We can see its pointing to 12 now

//	// We can also point to structures, but for us to be able to use it
//	// we have to allocate enough memory to use the struct.
//
//	typedef struct Person *T_person;
//	struct Person {
//		int age;
//		double salary;
//	};
//
//	// malloc() allocates in memory certain size, thats why we pass the size
//	// of our struct and we convert it to the same type as our struct since it returns (void *).
//	T_person ptrPerson = (struct Person*) malloc(sizeof(struct Person));
//
//	ptrPerson->age = 50; // The way to access it changes, now its "->" instead of the . operator
//	ptrPerson->salary = 36.235;
//
//	//printf("%d\n%.3lf", ptrPerson->age, ptrPerson->salary);
//
//	int x = 5;
//	void *ptr = &x;
//
//	// &x is of type (int *)
//	// ptr is of type (void *)
//	// we convert ptr to int * with (int *)
//	// but we dont want (int *)ptr address, we want the value:
//	// we use *(int *)ptr then.
//	printf("value of x: [%d]", *(int *)ptr);
//
/*
	 * 	pointers as param
	 * 		thingies.
*/
//
//	int x = 5;
//	int y = 6;
//
//	printf("x: %d\ny: %d\n", x, y); // we can see they were swapped
//
//	// we must send them by reference if we want to  be able to modify them
//	void swap(int* x, int* y)
//	{
//		int temp;
//		temp = *x;
//		*x = *y;
//		*y = temp;
//	}
//
//	swap(&x, &y); // We send the pointers of the variables.
//	printf("after swap...\n");
//	printf("x: %d\ny: %d\n", x, y); // we can see they were swapped
//
/*
	 * 	Files
	 * 		thingies.
*/
//
//	// Reads 3 data from the file, and creates individual files for each.
//	void write(char name[], char surname[], int age)
//	{
//		FILE *fin;
//
//		if ((fin = fopen("names.txt","at")) == NULL)
//		{
//			perror("Error when creating names.txt");
//		}
//
//		fprintf(fin, "%s\n", name);
//		fclose(fin);
//
//		if ((fin = fopen("surnames.txt","at")) == NULL)
//		{
//			perror("Error when creating names.txt");
//		}
//
//		fprintf(fin, "%s\n", surname);
//		fclose(fin);
//
//
//		if ((fin = fopen("age.txt","at")) == NULL)
//		{
//			perror("Error when creating names.txt");
//		}
//
//		fprintf(fin, "%d\n", age);
//
//
//		fclose(fin);
//	}
//
//	// Reads one files and calls write to split it into 3, depending on the data.
//	void read()
//	{
//		FILE *fin;
//
//		if ((fin = fopen("myfile.txt","rt")) == NULL)
//		{
//			perror("Error when reading myfile.txt");
//			return;
//		}
//
//		int age;
//		int done = 0;
//		char name[50];
//		char surname[50];
//
//		while (!done) // We keep going until we are at the end of the file.
//		{
//			if (fscanf(fin, "%s%s%d", name, surname, &age) == 3) // if there are 3 data values we are interested on, we take them and add them.
//			{
//				printf("%s %s %d\n", name, surname, age);
//				write(name, surname, age);
//			}
//
//			if (feof(fin)) // Check if empty file/end of file to leave
//				done = 1;
//		}
//		fclose(fin);
//	}
//
//	read();
//
//  //  How to copy a file:
//	void copy()
//	{
//
//		int ok = 1, taken, written;
//		char buffer[1024];
//
//		FILE *fin, *fout;
//		fin = fopen("myfile.txt", "rb");
//		fout = fopen("output.txt", "wb");
//
//		while (ok && (taken = fread(buffer, 1, sizeof(buffer), fin)) > 0)
//		{
//			written = fwrite(buffer, 1, taken, fout);
//			ok = written == taken;
//		}
//		fclose(fin);
//		fclose(fout);
//
//	}
//
//	copy();

	return 0;
}

