#include <format>
#include <string>
#include <algorithm>

#include "shell.hh"

using namespace std;

void CShell::help(){ for (auto &cmd : cmd_entry_map) {
    cout << cmd.first.c_str() << endl;
  }
}



void CShell::main_loop() { while (1) {
    static string input;
    cout << format("root@{}:~# ", user_name);
    getline(cin, input, '\n');
    
    string cmd_main = input.substr(0, input.find_first_of(' '));
    if (cmd_main == " " || !cmd_main.size()) continue;

    auto disp_iter = std::find_if(cmd_entry_map.cbegin(), cmd_entry_map.cend(),
              [&](auto& p) {
                if (!cmd_main.compare(p.first))
                  return true;
                else
                  return false;
              });

    if (disp_iter == cmd_entry_map.end()) {
      cout << format("{}: command not found\n", cmd_main);
    } else {
      disp_iter->second();
    }

    if (is_quit_emit) break;

  }
}


void CShell::add_cmd(std::string cmd_str, std::function<void(void)> func) {
  cmd_entry_map.insert({cmd_str, func});
}