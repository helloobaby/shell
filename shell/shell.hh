//author: github helloobaby

#include <functional>
#include <iostream>
#include <unordered_map>

class CShell {
public:
 void help(); //show all support commands
 void quit() { is_quit_emit = true; }  //quit the shell (break the main_loop)
 void main_loop(); //dead loop

 void add_cmd(std::string cmd_str, std::function<void(void)>);
 

private:
 bool is_quit_emit = false;
 const char* user_name = "sbb";
  std::unordered_map<std::string, std::function<void(void)>> cmd_entry_map{
     {"help", [this]() { help(); }},
     {"quit", [this]() { quit(); }},
      };
};