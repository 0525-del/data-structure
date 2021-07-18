# 第三章 java基础知识

## 第一节 java类结构与main函数

类名与文件名相同；

psvm：public static void main（String[] args)

一个Java文件只能有一个 public class

一个class最多只能一个main函数；

System.out.print 输出；

System.out.println  换行输出；

类的构成：成员变量/属性     成员方法/函数

args的赋值：Run As->Run Configurations->Program arguments里进行赋值

args.length才是引用的值

## 第二节基本类型和运算符

**基本类型**：

boolean 布尔:只有true和false，默认值为false，只能是小写

byte 字节：1byte=8bits    默认值0（-128 ~ 127）

short 短整型：默认值0  （-2^15  ~  2^15-1)

int:默认值0    （-2^31  ~  2^31-1)

long:默认值0L    （-2^63  ~  2^63-1)

float:单精度

double：双精度，占用8字节

char:单一任何字符  ，占两字节  （\u0000  ~  \uffff)    

**运算符**

移位运算符     >>    乘2  

​                       <<    除2

用括号隔开，括号优先级最高

## 第三节 选择和循环结构

if……if else……else

switch……case……case……default        要加break；

for，while，do……while   跟c语言用法一样

break：中断循环并退出

continue：跳出本次循环，继续下次循环

## 第四节 自定义函数

修饰词通常用public ，还可以static

重载函数：函数名相同，形参不同

## 作业

要用Integer.parseInt(args[0])将字符型数字化为整型，才能运行代码

**代码1**

package worktwo;

public class DataFangGe {

	public static void main(String[] args) {
	int m=1;
	for(int i=0;i <Integer.parseInt(args[0]);i++) {
		for(int j=0;j < Integer.parseInt(args[0]);j++) {
			System.out.print(" "+ m);
			m++;
			if(j==4) {
				System.out.println();
			}	
	
		}
	}
	}

}

**运行图1**

![](D:\桌面\后端\图片\Java第三章作业图片\1.png)

**代码2**

package workthree;
public class XingTa {
	public static void main(String[] args) {
		int n=Integer.parseInt(args[0]);
      for(int i=0;i<n;i++) {
    	  if(i<3) {
    	  for(int j=((n/2)-i);j>0;j--) {
    		  System.out.print(" ");
    	  }
    	  for(int m=n-2*((n/2)-i);m>0;m--) {
    		  System.out.print("*");
    	  }
    		System.out.println();
    	  }    
      if(i>=3) {
    	  for(int j=(i-(n/2));j>0;j--) {
    		  System.out.print(" ");
    	  }
    	  for(int m=n-2*(i-(n/2));m>0;m--) {
    		  System.out.print("*");
    	  }
    		System.out.println();   	  
      }
       }
	}
}

**运行图2**



​       ![](D:\桌面\后端\图片\Java第三章作业图片\2.png)