#include <iostream>
#include <fstream>
#include <string>
using namespace std;;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "USAGE: " << argv[0] << " file.gs" << endl;
    return -1;
  }
  ifstream ifile;
  ofstream ofile;
  ifile.open(argv[1]);
  char c;
  string newfile = string(argv[1]).substr(0, string(argv[1]).length() - 3) + ".cc";
  ofile.open(newfile.c_str());
  int state = 0;
  int length = 0;
  while (ifile >> c) {
    if (('a' <= c && c <= 'z' && c != 's' && c != 'h') || ('A' <= c && c <= 'Z' && c != 'S' && c != 'H')) {
      cout << c << endl;
      cout << ('a' <= c <= 'z') << endl;
      cout << (c != 's') << endl;
      cout << (c != 'h') << endl;
      cout << ('A' <= c <= 'Z') << endl;
      cout << (c != 'S') << endl;
      cout << (c != 'H') << endl;
      cerr << "Error 1: only hissing!" << endl;
      return 1;
    } 
    if (state == 1 && c != 's') {
      if (length == -1) {
        cerr << "Error 2: only hissing!" << endl;
        return 1;
      }
      ofile << (char)('a' + length);
      state = 0;
    } else if (state == 2 && c != 'S') {
      if (length == -1) {
        cerr << "Error 3: only hissing!" << endl;
        return 1;
      }
      ofile << (char)('A' + length);
      state = 0;
    } else if (state != 0) {
      length++;
    }

    if (state == 0) {
      if (c == 'H') {
        state = 2;
        length = -1;
      } else if (c == 'h') {
        state = 1;
        length = -1;
      } else cout << c << endl;
    }
  }
  ifile.close();
  ofile.close();
}

