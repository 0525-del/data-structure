# 第五章 继承、接口、抽象类

## 第一节，继承

son **extends** father :son 继承父类的方法，变量，但不能直接访问父类的private 变量

优先调用自己的方法，其次调用父类的方法

每个类只能继承一个父类

如果不写extends, Java类都默认继承 java.lang.Object类

**注**：每个子类的构建函数，都会调用父类的无参数构建函数super（），除非自己加上super（……）；并且super语句必须放在第一条，不能同时出现两条super语句。

## 第二节 抽象类和接口

抽象类的定义：方法只有方法名字，形参列表，没有方法体

**抽象类**关键字的声明 **abstract**：如public **abstract** void A();后面没有大括号，没有方法体

A a=new A()是不成立的.

通过子类继承父类抽象类，在子类中构建同名方法，将父类未实现的方法体完整写出，从而子类变成完      整类



**接口关键字声明interface**：类里所有的方法都未实现

一个类可以**实现**多个接口，但是只能**继承**一个类，继承与实现可以**同时**，但是要将所有的抽象方法都实现

一个接口可以继承多个接口，没有实现的方法讲会叠加

类实现接口，就必须实现所有为实现的方法，如果没有全部实现，那么只能成为一个抽象类，就要加关键字abstract声明

public class A **extends (父类名) implements (interface接口名)**：继承父类，实现接口 **顺序不能变**

## 第三节 转型、多态和契约设计

int a = (int) 3.5;

子类可以转换成父类，父类**不可以**转换成子类（从大变小，向上转型）

例子：可以：Human obj1 = new Man(); //man extends human

​      不可以：Man obj2 = new Human;

**特例**

父类本身就是从子类转化过来的。

```
Human obj1 = new Man;//OK,Man extends Human
Man obj2 = (Man) obj1;//Ok,because obj1 is born feom Man class;
```

**多态**：起源于类型转换

```
public class Man extends Human{
    public void eat(){
        System.ouy.println("I can eat more");
    }
    public void plough(){}
    
    public static void main(String[] args){
        Man obj1 = new Man();
        obj1.eat();  //call Mam.eat()
        Human obj2 = (Human) obj1;
        obj1.eat();  //call Man.eat()
        Man obj3 = (Man) obj2;
        obj3.eat(); //call Man.eat()
    }
}
```

多态的作用：1,以统一接口来操作某一类不同的对象的动态行为

​                       2，对象之间的解耦

**定义数组**：A[] as = new A[4];

​                   A[0] = new mingzi();

**契约设计:**

​       契约：规定了对象应该包含的行为方法

​        匿名类：new  接口名      //必须补全方法

​     类不会直接使用另一个类，而是采用接口形式，外部可以 ’空投‘ 这个接口下的人意子类对象



![](D:\桌面\后端\图片\Java第五章作业图片\1.png)

![2](D:\桌面\后端\图片\Java第五章作业图片\2.png)

![3](D:\桌面\后端\图片\Java第五章作业图片\3.png)

![4](D:\桌面\后端\图片\Java第五章作业图片\4.png)

![5](D:\桌面\后端\图片\Java第五章作业图片\5.png)