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

* 2.fprintf  fwrite对写入的处理, 如果不清楚看下面的**参考链接**

### 总结
* 写一篇总结性的文章《论文本操作》  
##### **参考**：  
[二进制方式和文本方式的区别](https://blog.csdn.net/renjiewen1995/article/details/52108645)
[fprintf与fwrite使用区别](https://blog.csdn.net/godenlove007/article/details/7721647)  

### 实践项目  
c实现文本编辑器, 参考代码&nbsp;&nbsp;&nbsp;&nbsp;"edit.c"

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
文本文件是二进制文件的一种特殊形式，特殊在对应的每个字节可以转换成0-127内规定的ASCCI码值。

为了兼容win和linux平台，最好将文件打开方式一律规定为 wb， 如果仅仅是w 文本方式，window 平台会将linux平台下的0x0A默认转换成0x0D 0x0A, 这样就将文件变大了. 0x0A对应的是换行符\n, 同理linux打开window文件会出现 ^M是因为她对应了\n\r后面这个\r.

下面写一个标准的打开写入操作，c系统是操作字符流的：

```  
char buf[BUFSIZE];
fp = fopen("test", "rb");  
//if err
while ((num = fread(buf, sizeof(char), BUFSIZE, fp)) > 0) {
  fwrite(buf, sizeof(char), num, fp2);
}
```

一个标准的读取字符过程(适用于文本或二进制，判断EOF只用于文本)：
```
char c = fgetc(fp);
while (!feof(fp)) {
    printf("0x%x ", c);
    c = fgetc(fp);
}
```
有时见到的EOF解释如下：EOF=-1=0xff， 不再0-127ASCCI码值范围，所以被用来判断是否是结尾或出错等.
//文本的读取
```
while ((c = fgec(fp)) != EOF) {
  printf("%c ", c);
}
```
