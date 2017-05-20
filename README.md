# struct-senior-fileopt
将结构体仓howto-use-struct的基本任务完成后，完成此项目，需求需要后期更新README.md


项目描述
------------------------------------------------------------------------------------------------------
利用struct stat， readdir, 等等Unix高级环境编程里面的函数来实现 find, ls, grep, cat, touch,等

执行方式 shell# ./a.out -find file.txt

接口函数如下
*yang_find_file(filename);
**yang_ls_file();
**yang_grep_string(strname);
**yang_cat_file(filename);
**yang_touch_file(filename);

*特殊说明
ls等支持参数，如 ./a.out -ls -l  , grep -nIr hello

编程注意，目的是强化结构体的熟识度，所以要把struct stat等内核结构体直接写到代码里面，最好不用include包含,目的是方便看着操作
-----------------------------------------------------------------------------------------------------------
