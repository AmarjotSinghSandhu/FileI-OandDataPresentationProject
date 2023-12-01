# Data Input and Processing

This program allows users to input and process data in a specific format from the console. It performs the following functions:

1. **Data Entry and Validation**: The program prompts users to input a title for the data, column headers, and data points. It validates the input format and ensures it adheres to predefined rules.

2. **Data Output**: It writes the validated input data into a file named `myfile.txt` in a comma-separated format (header, number). The data is then displayed in tabular form on the console.

3. **Chart Representation**: The program reads the data from the file `myfile.txt` and displays it in a tabular format on the console. It showcases the title along with the headers and data points.

4. **Histogram Generation**: Based on the data stored in `myfile.txt`, the program generates a histogram by counting the occurrences of numbers and representing them as asterisks.

## How to Use

1. Run the program.
2. Enter a title for the data.
3. Input column headers.
4. Enter data points (input -1 to stop).
5. View the generated chart and histogram for the entered data.

## Code Description

The code reads user inputs for data title, headers, and points. It validates the inputs, ensuring they conform to specific format requirements. After validation, the program writes the validated data into the `myfile.txt` file. It then reads from this file to display the data in table format and generate a histogram representation.

### Running the Program

Ensure the program file (`main.c`) is compiled and executed in a C-compatible environment (GCC, Visual Studio, etc.).

### Sample Compilation and Execution

```bash
gcc main.c -o dataProcessor
./dataProcessor
