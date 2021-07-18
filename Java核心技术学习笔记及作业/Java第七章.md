# 第七章

## 第一节，package和import

```
package cn.edu.ecnu;
public class PackageExample{}
```

类全称  cn.edu.ecnu.PackageExample

短名称  PackageExample

引用类的时候用全称，程序正文永短名

```
package cn.edu.ecnu;
import cn.edu.ecnu.PackageExample
```

import 放在package后面

import cn.edu.ecnu.*

*不包括各个目录下的文件，不推荐用 *



## 第二节，jar文件导出和导入

jar文件时一组class文件的压缩包

jar文件可以包括多个class，只包括class，不包括java文件

利用Eclipse的Export功能到处jar文件

​           File ->Export =>java =>jar file=>Next

导入jar文件

​          Libraries =>Add Extenal JARS =>Apply and Close



## 第三节，package和import ——命令行

手动创建  c:\temp\cn\com\test\Man.java

记事本中的第一句：package cn.com.test

记事本保存类型 *. *

**命令行中**：  编译：c:\temp\cn\com\test\Man.java

​                   运行：java -cp .;c:\temp  cn.com.test.Man

包名和类所在的目录必须严格一致

编译需要文件的全路径，运行需要类的完整名字



## 第四节，Java的访问权限

private 私有的，只能在本类访问

default（**一般不写**） 同一个包内访问（指同一个目录，上下级目录不算）

protected  同一个包，子类都可以访问

public 公开的，所有类都可以访问

**只要没写，都是default，但是不能显式写default**

包 <=>目录，src下的目录

default和public可以修饰类

**1**：先new 对象类

​         A类 obj = new A类（）；才可以在同一个包下的不同类间访问

**2**：先package 目录

​         import 目录.A类

​       导入目录.A.java



## 作业：

![](D:\桌面\后端\图片\Java第七章作业图片\1.png)

![2](D:\桌面\后端\图片\Java第七章作业图片\2.png)