# 十一章，Java文件读写

## 第一节，文件系统及Java文件基本操作

File类不涉及文件类容，只涉及属性

```java
import java.io.*;
File d = new File("c:/temp");
d.exists();//判断是否存在
d.mkdirs();//有s则是创建多级目录，无则是创建一级目录
d.isDirectory//是否有目录
    isFile();//是否是文件
d.createNewFile//创建新文件
    d.getPath();//获取全部路径
d.listFiles();//列出d目录的以及所有子文件
```

NIO包，是java.io.File的补充

Path

```java
1.Path path = FileSystems.getDefault().getPath("c:/temp","abc.txt");
2. File file = new File("c:/temp/abc.txt");
    Path pathOther = file.toPath();
3.Path path3 = Path.get("c:/temp","abc.txt");
4. Path path4 = Paths.get("c:/temp");
  path4.resolve("abc.txt");
```

```java
import java.io.IoException;
Files.isDirectory//判断是否是目录
BasicFileAttributes.isDirectory//判断是否是目录
BasicFileAttributes.creationTime//返回创建时间
BasicFileAttributes.lastModifiedTime//返回最后修改时间
```

## 第二节，java.io包概述

Java读写文件，只能以数据流的形式进行读写

Java.io包：节点类：直接对文件进行读写

​              包装类：转化类：字节/字符/数据类型的转化类

​                              装饰类：装束节点类

文件是以字节保存的

**节点类**：InputStream和OutputStream :字节类

​              Reader和Writer:字符类

**转换类**：InputStreamReader:文件读取，字节到字符

​              OutputStreamWriter:字符到字节，输入到文件

**装饰类**：装饰节点类

​         -DataInputStream,DataOutputStream:封装数据流

​        -BufferedInputStream,BufferOutputStream:缓存字节流

​         -BufferedReader,BufferedWriter:缓存字符流

## 第三节，文件文本读写

**输出**：从Java到文件，写操作

**输入**：从文件到Java中，读操作

写文件：

```java
FileOutputStream//往文件写字节
OutputStreamWriter//字节加字符转化
BufferWriter//写缓存类，加速写操作
        write()//写
         newline()//换行
```

try-resource语句：关闭资源，关闭最外层的数据流，讲会把其上所以的数据流关闭

读文件：

```java
//BufferReader
FileInputStream//节点类，负责都字节
InputStreamReader//转化类，负责字节到字符转化
    BufferedReader//装饰类，负责从缓存区读入字符
```

三者构建关系：

​           BufferedReader(InputStreamReader(FileInputStream))

## 第四节，二进制文件读写

**写**：Output：先创建文件，写入数据，关闭文件

```java
FileoOutputStream
BufferedOutputStream;
DataOutputStream;
DataOutputStream;
    flush//刷新缓存
```

try-resource语句，自动关闭资源，关闭最外层

**读**：先打开文件，读入数据，关闭文件

```
FileInputStream;
BufferedInputStream;
DataInputStream;
DataInputStream;
```

## 第五节，zip文件读写

```
import java.util.zip;//zip文件操作类
-java.io.InputStream,java.io.OutputStream的子类
-ZipInputStream,ZipOutputStream//压缩文件的输入/输出流
-ZipEntry//压缩项
```

**压缩**：1.添加一个ZipEntry

​            2.打开一个输入文件，读数据，向ZipEntry写数据，关闭输入文件

**解压**：1.获取一个ZipEntry

​           2.新建一个目标文件，从ZipEntry读取数据，向目标文件写入数据，关闭目标文件

## 作业

![](D:\桌面\后端\图片\Java第十一章作业图片\1.png)



```java
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class MyComparator implements Comparator<Map.Entry<String,Integer>>{
    public int compare(HashMap.Entry<String,Integer> he1,HashMap.Entry<String,Integer> he2) {
        return he2.getValue()-he1.getValue();
    }
}

public class Test11 {
    static final int MAX = 50;

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        HashMap<String, Integer> hm = new HashMap<String,Integer>();
        
        //文件读取
        try(BufferedReader br=new BufferedReader(new InputStreamReader(new FileInputStream("D:/Java/a.txt")))){
            String line;
            while((line = br.readLine())!=null) {
                Pattern p = Pattern.compile("\\s+");//正则匹配空格
                String words[]= p.split(line);//获取的字符串进行分割单词
                
                for(String item : words) {
                    if(item.length()!=0) {
                        if(hm.get(item)==null)
                            hm.put(item, 1);//将数据放入map中
                        else
                            hm.put(item, hm.get(item)+1);
                    }
                }
            }
        }catch(Exception e) {
            System.err.println(e.getMessage());
        }
        
        //HashMap转换为list，进行排序
        List<Map.Entry<String,Integer>> list = new ArrayList<Map.Entry<String,Integer>>(hm.entrySet());
        Collections.sort(list,new MyComparator());
        
        //将数据写入文件
        try(BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(new FileOutputStream("D:/Java/b.txt")))){
            for(Map.Entry<String, Integer> item: list) {
                bw.write(item.getKey()+","+item.getValue());
                bw.newLine();
            }
        }catch(Exception e) {
            System.err.println(e.getMessage());
        }
        
    }

}
```

