# File operations

项目描述
------------------------------------------------------------------------------------------------------
#### 1.强化字符  字符串  文本  二进制  fopen系列 open系列 移位操作  等重复练习
* 1.1 二进制的练习  
* 1.2 字符串与二进制结合的练习  
* 1.3 文本文件操作+二进制文件操作
* 1.4 所有相关函数族的练习：fopen ftell rewind  fprintf sprintf strcat strstr isalpha等等  
* 1.5 [read/fread write/fwrite 的实现原理](https://blog.csdn.net/xiaofei0859/article/details/74686254)  
* 1.6 [说说fflush和fsync函数](https://blog.csdn.net/xiaofei0859/article/details/74686254)  

### Q&A  
* 1.验证： 二进制读写是将内存里面的数据直接读写入文本中，而文本呢，则是将数据先转换成了字符串，再写入到文本中。下面我用个例子来说明。
我们定义了一个结构体，表示一个学生信息，我们打算把学生的信息分别用二进制和文本的方式写入到文件中。

* 2.fprintf  fwrite对写入的处理, 如果不清楚看下面的**参考链接**  
* 3.**读写之间要有刷新**, 对于一个可写可读流，是不能在一次读之后马上进行一次写，或者进行一次写之后马上进行一次读的，这可能会发生问题，需要在两个操作之间进行**至少一次刷新**，刷新的方法可以用fseek、rewind、fflush等等函数  
* 4.关于fopen中参数的说明如r r+ r+b 等等[mode有下列几种形态字符串](https://blog.csdn.net/hjjph/article/details/7090770)  
* 4.读写函数fread fwrite的**参数size nemb**一定要注意什么意思，不要写反了，会出大问题  

### 总结
* 写一篇总结性的文章《论文本操作》  
##### **参考**：  
[二进制方式和文本方式的区别](https://blog.csdn.net/renjiewen1995/article/details/52108645)  
[fprintf与fwrite使用区别](https://blog.csdn.net/godenlove007/article/details/7721647)  
[mmap和direct io和write和fwrite区别](https://blog.csdn.net/xiaofei0859/article/details/74674631?locationNum=10&fps=1)  
[glibc源码拜读 - printf](https://blog.csdn.net/InsZVA/article/details/54234201)

### 实践项目  
1. 002.c: 打开一个文件，如果某一行存在hello world（中间匹配多个空格或者\t）， 则在这行行首四个字符替换为fuck  
  希望用到的知识有**字串匹配算法fopen+fwrite+fseek+ftell+fgets+isspace等等的使用和实现，要求代码可读性强+简洁美观**  

  关键参考：[C 语言 边读 边写入文件](https://www.cnblogs.com/easyfrog/archive/2011/12/27/2303919.html)  
  [关于文件指针定位函数fseek的一个用法](http://oldbbs.rupeng.com/thread-8189-1-1.html)  

```
  读入一个文本文件中的字符串，对给定的patten进行甄别并修改。
  利用边甄别，边转换，边写入的办法实现
  方法：
  1. 把原文件改名，然后新建一个与原文件名相同的文件(目的文件)，然后读取原文件，转换后写入目的文件
  2. 最好同时对同一个文件进行读写操作，这样往原文件中写入数据会使原文件中数据丢失(除非是a方式打开)。如果非要这么做，那应先把文件中的数据全读到内存中(内存要能满足需要)，然后在内存中对文件进行修改，再写回原文件。 
  3.
  以读写方式打开(r+ w+ a+都可以，不过要注意读写位置指针分别指向文件头、文件头、文件尾);
  一次读一个字符(此时读写位置指针指向此字节后面，判断后，若要转换，移动读写位置指针fseek(fp,-1L,SEEK_CUR)，再写入;
		  由于C规定：以上述三种方式打开文件，既可读又可写，但:
		  (1) 在没有插入fseek()或rewind()的情况下,写不可以直接跟在读后面;
		  (2) 在没有插入fseek()或rewind()或碰到文件结束的情况下，读不可以直接跟在写后面.
		  所以要转换读写状态
```
2.c实现文本编辑器, 参考代码&nbsp;&nbsp;&nbsp;&nbsp;"edit.c"和 "jedit.c"  
文本编辑器是一个大坑，但是确实磨练字符的操作  

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

3. 将文本文件中的字符分为三种方式存储，比较其文件的大小  
	1.直接按照字符存储为文本文件jcps_file1  
	2.按照字符对应的ASCCI编码存储为二进制文件jcps_file2  
	3.按照字符的出现次数来通过huffman方式编码为二进制存储jcps_file3  
	Tips: 以上存储方式要确保存储本身的正确性，可以通过解码读取到原始数据  
	难点：如果文本中如a可以当作65写，如果是汉字怎么办？ huffman的解码问题 ?  

 My 编程珠玑：
 > 根据编程网站的调查分析，所有工程代码统计的结果表明：30%的工作量是字符的操作，所以字符相关的操作一定要手到擒来

# &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 《论文本操作》  
xxx
文本文件是二进制文件的一种特殊形式，特殊在对应的每个字节可以转换成0-127内规定的ASCCI码值。

为了兼容win和linux平台，最好将文件打开方式一律规定为 wb， 如果仅仅是w 文本方式，window 平台会将linux平台下的0x0A默认转换成0x0D 0x0A, 这样就将文件变大了. 0x0A对应的是换行符\n, 同理linux打开window文件会出现 ^M是因为她对应了\n\r后面这个\r.

下面写一个标准的打开写入操作，c系统是操作字符流的：

```  
char buf[BUFSIZE];
fp = fopen("test", "r+b");  
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
