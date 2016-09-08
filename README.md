# Basic Theory
There are two kinds of data types, namely:
- Standard data type
  That is the type of data that has been defined by the compiler that can directly be declared when needed. Examples such as `int`, `float`, `char`, `double`, `void`.
- User defined data type
  That data types defined by the user according to his needs. The first step is to define or create the desired data type first, then declare variables with these data types. Examples like `struct` and `union`.

Structure (`struct`) is a set of data which may be different data types that use the same name and is distinguished through its field name. Thus it is possible a structure contains elements of different data types such as `char`, `int`, `float`, `double`, and others.

Structure is defined using the `struct` keyword. Here's an example of defining a data type structure:
```c
struct date 
{
	int month;
	int day;
	int year;
};
```
or
```c
struct date 
{
	int month, day, year
};
```

The examples above are the establishment of a new data type called `struct date` that has three elements (*fields*) in the form of `month`, `day`, and `year`.

Here is the other example
```c
struct date today;
```
The statement above states that a variable of type struct date today.

In defining a structure, the elements contained in them can also be a structure. Example:
```c
struct date 
{
	int month, day, year;
};

struct student 
{
	char name[30];
	struct date birthday;
};

struct student mhs;
```

Data structure diagram of a variable `mhs` can be described as follows:

![Image of Diagram](https://github.com/rizalasrul/c-basic-struct/blob/master/Images/1.png)

Elements of a structure variable can be accessed by mentioning the name of the structure variable followed by the dot operator ('.') And the name of the element structure. The way of writing as follows:
```c
struct_variable.field_name;
```

For example, provide the data field name to the name of the variable `student` above, then the statement is required, for example is:
```c
strcpy(mhs.name, “BUDI”);
```

The following example is an instruction to fill in the data field `birthday`:
```c
mhs.birthday.day = 10;
```

Meanwhile, to get the contents of a field of variable structure, for example: `date = mhs.birthday.day;` an instruction to deliver the content of the field day to a date variable. `puts (mhs.name);` an on-screen instructions to display the contents of the name field.

A structure can also be initialized when declared. This is similar to the array initialization, the elements are written in a pair of curly braces ('{}') with each separated by a comma.

Examples for variable `mhs` above:
```c
struct strudent mhs = {“Rizal”, 4, 11, 1993};
```
