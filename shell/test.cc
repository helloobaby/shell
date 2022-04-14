#include <iostream>
#include "shell.hh"
using namespace std;

void f() { cout << "hello world\n"; };

int main()
{
  CShell shell;
  shell.add_cmd("test", f);
  shell.main_loop();
  


  return 0;
}
