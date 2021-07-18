# 第四章

## 第一节

op中，方法是主体，所有的参数是类似于宾语

oo中，方法从属于一个对象，这个对象可以知行自身的某个方法

类可以继承：子类可以继承父类所有的类容，用“."访问，但不能直接访问private成员

## 第二节

最简单的类：class A{}

对象：A obj = new A()

类是定义，是规范；

对象是实例，是类的具体化中的一部分

没有两个对象是完全一样的，如不同的存放地址

obj可以看作c的指针，指向地址

对象赋值：Reference赋值，共享同一块内存区域

基本类型赋值：直接拷贝，如在对象函数中，用基本类型赋值，形参的改变不会影响实参，类似于指针。

对象函数的局部变量无默认值；

类的成员变量有默认值

## 第三节

构造函数：名称与类名一样；没有返回值，但不加void

构造函数的形参类型要区分清楚

构造函数是一个对象初始化的过程

Java没有解析函数，会自动回收区域空间。

## 第四节

private 私有的，不能继承，不公开

public 公开的，可以修改成员属性，通过此，改变private的值

**A obj = new A（b）    obj就指A的地址，b指给A的成员赋值 或者是运行A中的方法A（int m）**

getter和setter：可以Eclipse快速生成    Source ->Generate Getter and Setter,勾选像产生的成员

this指针指向本类中的成员变量：this可以指类名，**this.成员变量**；

​                                                         this（）可以代指引用构建函数；

## 作业

### 作业一

```
obj1 = a;
obj2 = b;
obj3 = c;
swap(obj1,obj2);
swap(obj2,obj3);
swap(obj1,obj3);
for(int i = 1;i<4;i++)
{
System.out.println(obji);
}
```



### 作业二

float 赋值要加f

类名+成员变量不是初始化定义

A 一个名字 = new A（）   ，‘一个名字’ 等价于obj

main方法可以被重载，main（String[] args)中arg可以改变，但是String[]不能改变

一次编译，到处运行   指class文件，即字节码文件

JDk包含JRE

![](D:\桌面\后端\图片\Java第四章作业图片\1.png)