#include  <iostream>
#include <fstream>

using namespace std;

template<class T>
void readFile(T *arr, int size) {
    int num, index = 0;
    const char file_name [] ="data.txt";

    ifstream ifs(file_name , ios::in);

    // check file is open
    if (ifs.is_open()) {

        while (true) {
            // end of file then break or index greater than equal to  ( size ) Last index
            if (ifs.eof() || index >= size ) {
                break;
            }
            ifs >> num;
            arr[index] = num;
            index++;
        }

    } else {
        cout << file_name << " is not open" << endl;
    }
    // close the file
    ifs.close();
}


template<class T>
void writeFile(T *arr, int size) {

    const char file_name [] ="data.txt";

    // try different mode replace with  ios :: app
    ofstream ofs(file_name , ios::out);

    // check file is open
    if (ofs.is_open()) {
        cout << "Enter array of size :" << size << endl;
        for(int i =0 ; i < size ;i++){
            cin >> arr[i];
            ofs << arr[i] << "  ";
        }
        // end line after putting data helpful in ios:: app
        ofs << endl;


    } else {
        cout << file_name << " is not open" << endl;
    }
    // close the file
    ofs.close();
}

template<class T>
void display(T *arr, int size) {
    cout << "Display the array" << endl;
    for (int i = 0; i < size; i++)
        cout << i + 1 << ". " << arr[i] << endl;
}


int main() {
    const int MAX_SIZE = 10;
    int *array = new int[MAX_SIZE];
    // function read data into array
    readFile(array , MAX_SIZE);
    // display function
    display(array , MAX_SIZE);
    // function to write data into array
    writeFile(array , MAX_SIZE);

    // delete allocated memory
    delete [] array;
    return 0;
}