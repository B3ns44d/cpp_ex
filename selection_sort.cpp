#include <iostream>

using namespace std;

class List {
  private:
    int * array;
  int length;

  public:
    List() {
      this -> array = NULL;
      this -> length = 0;
    }

  void populate() {
    do {
      cout << "enter array size:" << endl;
      cin >> this -> length;
    } while (this -> length < 0);

    this -> array = new int[this -> length];

    for (int i = 0; i < this -> length; i++) {
      cout << "enter " << i << "th item" << endl;
      cin >> * (array + i);
    }
  }

  void selectionSort() {
    if (array == NULL) {
      cout << "list is empty !" << endl;
      return;
    }
    int minIndex, temp;
    for (int i = 0; i < this -> length; i++) {
      minIndex = i;
      for (int j = (i + 1); j < this -> length; j++) {
        if ( * (array + j) < * (array + minIndex)) {
          minIndex = j;
        }
      }
      temp = * (array + i);
      *(array + i) = * (array + minIndex);
      *(array + minIndex) = temp;
    }
  }

  int length() {
    return length;
  }

  void display() {
      if (array == NULL) {
        cout << "list is empty !" << endl;
        return;
      }
      cout << "[";
      for (int i = 0; i < this -> length; i++) {
        if (i != length - 1) {
          cout << * (array + i) << ", ";
        } else {
          cout << * (array + i);
        }
      }
      cout << "]" << endl;
    }

    ~List() {
      delete array;
    }
};

int main() {
  List list;
  list.populate();
  cout << "unsorted list:";
  list.display();
  cout << "sorted list:";
  list.selectionSort();
  list.display();
  return 0;
}