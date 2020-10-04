# 索引到行

19335025 陈禹翰 chenyh369@mail2.sysu.edu.cn  10月1日

#### 摘要 

本实验通过对输入文件中的文本和关键字进行读取，在文本中查找关键字的位置（行号），生成索引表输出至输出文件中。

#### 引言

要解决的问题：设计一个程序，输入是一个英文文本文件和一个关键词文件，输出是文件中关键词出现的所有位置（行号）。

#### 解决方法

运行形式：

```powershell
.\count.exe .\inputfile .\keysfile .\outputfile
```

输入是一个英文文本文件和一个关键词文件，输出是文件中关键词出现的所有位置（行号）。

使用的数据结构是数组，用来存储输入的关键词，算法主要是：

1. 进入readFile()函数，读取时过滤掉标点和换行符并将每个关键词存储在string数组keys中
2. 进入keysLine()函数
   1. 循环遍历keys中的每个关键词，把每一个关键词传入searchFile()函数中；
   
   2. 在searchFile()函数中，通过在每行中查找关键词，查找到则跳入在文件中输出行号并跳入下一行；
   
   3. 遍历完后程序结束。
   
      

#### 程序使用和测试说明

使用g++编译：

```powershell
g++ .\count.cpp -o count.exe
```

 运行：

```powershell
.\count.exe .\inputfile .\keysfile .\outputfile
```



#### 总结和讨论

我的实现特色在于我过滤了除了英文字母大小写之外的其他字符，并且在搜索到一行后立刻进入下一行。我还实现了精确位置的索引（但是没啥用）。存在的问题是对于输入输出流掌握不够熟练。通过这次实验我学会了使用main函数的参数，并且学习了一些文件操作。

#### 参考文献

[命令行参数如何运行](https://zhidao.baidu.com/question/280662774.html)

[在c++中，如果在使用ifstream读入文件的时候，如何读入换行符('\n')？](https://zhidao.baidu.com/question/120769465.html)

[C++文件和流](https://www.runoob.com/cplusplus/cpp-files-streams.html)

[C++ 如何在一个文件末端添加信息](https://blog.csdn.net/weixin_48134278/article/details/107940580)

