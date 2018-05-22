# File operations

项目描述
------------------------------------------------------------------------------------------------------
#### 1.强化字符  字符串  文本  二进制  fopen系列 open系列 移位操作  等重复练习
* 1.1 二进制的练习  
* 1.2 字符串与二进制结合的练习  
* 1.3 文本文件操作+二进制文件操作
* 1.4 所有相关函数族的练习：fopen ftell rewind  fprintf sprintf strcat strstr isalpha等等

### Q&A  
* 1.验证： 二进制读写是将内存里面的数据直接读写入文本中，而文本呢，则是将数据先转换成了字符串，再写入到文本中。下面我用个例子来说明。
我们定义了一个结构体，表示一个学生信息，我们打算把学生的信息分别用二进制和文本的方式写入到文件中。

* 2.fprintf  fwrite对写入的处理, 如果不清楚看下面的参考链接

### 总结
* 写一篇总结性的文章《论文本操作》
参考：  
[二进制方式和文本方式的区别](https://blog.csdn.net/renjiewen1995/article/details/52108645)
[fprintf与fwrite使用区别](https://blog.csdn.net/godenlove007/article/details/7721647)
#### 2. 利用struct stat， readdir, 等等Unix高级环境编程里面的函数来实现 find, ls, grep, cat, touch,等
执行方式 shell# ./a.out -find file.txt
接口函数如下  
** yang_find_file(filename);**   
** yang_ls_file();**  
** yang_grep_string(strname);**  
** yang_cat_file(filename);**  
** yang_touch_file(filename);**

---
## 特殊说明
ls等支持参数，如 ./a.out -ls -l  , grep -nIr hello  

 My 编程珠玑：
 > 根据编程网站的调查分析，所有工程代码统计的结果表明：30%的工作量是字符的操作，所以字符相关的操作一定要手到擒来

---
# &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 《论文本操作》  
xxx
