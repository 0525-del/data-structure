# 第九章 Java异常和处理

## 第一节 异常分类

Error：系统内部出错或资源耗尽，不管

Exception：程序有关的异常

-Runtime Exception：程序自身的错误

-Unruntime Exception:外界相关的错误，比如打开一个不存在的文件夹

​     典例：IOException

Checked Exception（非Run……）：易发生后处理为主，编译器会辅助检查

Uncheck Exception（Run……）：以预防为主，不会辅助检查

## 第二节，Java异常处理

try{}  -  catch(){}   -  finally{}

try必须有，catch和finally至少有一个，catch可以有多个，但只运行其中一个

try：写正常业务代码

catch：当try发生异常时，根据形参选择哪一个catch执行，前面的代码优先级高，若无异常，则跳过，所                         

​            以错误小的写在前面，错误大的写在后面 

finally：必须执行，一定会知行

异常父类：Exception

在try，catch，finally中可以加入完整的try-catch/finally

throws:声明异常

​        方法的覆盖或继承都需要再次抛出相同的异常或是更精细的小异常，不能比之前的大

## 第三节，自定义异常

java.lang.Exception：所有的异常的父类

自定义异常：需继承Exception类或是其子类

-继承Exception，变成Checked Exception

-继承Runtime Exception    ，变成Unchecked Exception

![](D:\桌面\后端\图片\Java第九章作业图片\1.png)

![2](D:\桌面\后端\图片\Java第九章作业图片\2.png)

![3](D:\桌面\后端\图片\Java第九章作业图片\3.png)