En:  
lightwight shell to get simple interaction(because writing gui is cumbersome)  
google c++ style  
only for windows  
usage: copy shell.hh and shell.cc to your project  

Ch: 
很简单的交互,用来代替简单的gui需求


```
void f() { cout << "hello world\n"; };

int main()
{
  CShell shell;
  shell.add_cmd("test", f);
  shell.main_loop();
  


  return 0;
}
```

![img](https://github.com/helloobaby/shell/blob/master/1.gif)




