# 第十章 Java数据结构

## 第一节，数组

声明定义数组：

```java
int[] b;
int[] c = new int[2];//初始化c={0，0}
int d[] = new int[];//
int d1[] = {1,3,5};
```

**错误示例**

```java
int e[5];//声明变量时未分配内存，不能指定大小
int[5] f;
int h[5] = new int[5];
```

另一种遍历数组的方法：

```java
for(int e,b)//b为数组
{
System.out.println(e);
}
```

不规则数组：

```java
int b[][];
b = new int[3][];
b[0] = new int[3];
b[1] = new int[4];
b[2] = new int[5];

```

## 第二节，JCF

集合接口：Collection

​       add：增加

​        contains：包括

​       remove：删除

​       size：数据元素个数

迭代器：Iterator

   -hasnext：判断是否有下一个元素

   -next

​    -remove

JCF主要的数据结构实现类：列表，集合，映射

## 第三节，List

-ArrayList（非同步）

-LinkedList（非同步）

-Vector（同步）



ArrayList：以数组实现的列表，充满时自动扩宽50%

```java
import java.util.ArrayList;
  ArrayList<Integer> a1 = new ArrayList<Integer>();//
a1.add();
a1.get(3);//访问第四个元素
a1.remove(3);//删除第四个
```

遍历：Iterator

​            索引位置遍历

​           for-each



LinkedList:以双向链表实现

```java
LinkedList<Integer> a1 = new LinkedList<Integer>
    a1.addFirst(9);//在头部加9
    a1.add(3,10);//在第四个位置插入10
```

遍历：Iterator

​            索引位置遍历

​           for-each



Vector：同步，可变数组实现的列表

方法与ArrayList相似

遍历：Iterator

​            索引位置遍历

​           for-each

​         Enumeration



## 第四节，集合

确定性，互异性，无序性

-HashSet：基于散列函数，无需，不支持同步

-TreeSet：基于树结构的集合，可排序的，不支持同步

-LinkedHashSet：基于散列函数何双向链表的集合，可排序的，不同步



**HashSet**

```java
HashSet<Integer> hs = new HashSet<Integer>();
hs.add();//重复加会无效
for(Integer item:hs)//遍历
{
    System.out.println(item);
}
hs.retainAll(hs2);//计算交集
```



**LinkedList**

方法与hashSet一致，只是输出是有序的



**TreeSet**

不可以容纳NULL

根据compareTo或Comparator排序，按照所存储对象的大小升序输出



三个类的元素都只能是对象

HashSet何LinkedList判定元素重复的原则

​      -判定HashCode是否相同，不同返回false

​     -若两者的hashCode相同，判定equals方法，若不同，返回false

​     -hashCode和equals方法是所有类都有的，因为Object类有

TreeSet判定元素重复的原则

​       -需要元素继承Comparable接口

​       -比较两个元素的compareTo方法

## 第五节，映射Map

-Hash table：同步，慢，数据量小

无序的，k-v对都不允许NULL

```
clear
contains
containsKey//是否包含某一个key
containsValue//是否包含某一个值
get
put
remove
size

import java.util.Enumeration;
hashtable<Integer,String> //key和value
```

**所用时间**

```java
long startTime = System.nanoTime();
long endTime = System.nanoTime（);
long duration = endTime - startTime;
```

-HashMap：不同步，块，数据量大

k-v对允许位NULL



-Properties：同步，文件形式，数据量小

  从文件加载load方法，写入到文件的store方法

获取属性getProperty,设置属性setProperty

## 工具类

不存储数据，排序和搜索

**Arrays**：处理数组对象

```
排序:sort/paralleSort
查找:binarySearch
批量拷贝:copyOf
批量赋值:fill
等价性比较:equals
```

**Collections**:处理对象是Collection及其子类

```
排序sort
搜索binarySearch
批量赋值fill
查最大最小max,min
反序reverse
```

对象实现：Comparable接口（需要修改对象类）

-compareTp方法（返回-1，0，1），默认升序

-Arrays和Collections在进行对象sort是自动调用该方法

Comparator（对象类不可更改的情况)

-compare方法

Comparator比较器将作为参数提交给工具类的sort方法

## 作业

![](D:\桌面\后端\图片\Java第十章作业图片\1.png)



```java
 package HuoBi;
import java.util.Arrays;
import java.util.Scanner;
class Currency {
    private String name;        //货币名称
	private int originalValue;  //原始值
	private int value;          //转换为人民币后的值
	public static String[] CURRENCY_NAME = { "CNY", "HKD", "USD", "EUR" };
	public static int[] CURRENCY_RATIO = { 100, 118, 15, 13 };
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getOriginalValue() {
		return originalValue;
	}
	public void setOriginalValue(int originalValue) {
		this.originalValue = originalValue;
	}
	public int getValue() {
		return value;
	}
	public void setValue(int value) {
	this.value = value;
	}
}
class HKD extends Currency implements Comparable<Currency> {
	// 实现你的构造函数与Comparable中的接口
	double a;
	public int compareTo(Currency e) {
		if(e.getValue()>a) return 1;
		if(e.getValue()<a) return -1;
		else return 0;
	}
	HKD(int a){
		this.a=a*1.18;
		this.setValue((int)this.a);
		this.setName("HKD");
		this.setOriginalValue(a);
	}
}
class USD extends Currency implements Comparable <Currency>{
	// 实现你的构造函数与Comparable中的接口
	double a;
	public int compareTo(Currency e) {
		if(e.getValue()>a) return 1;
		if(e.getValue()<a) return -1;
		else return 0;
	}
	USD(int a){
		this.a=a*0.15;
		this.setValue((int)this.a);
		this.setName("USD");
		this.setOriginalValue(a);
	}
	
}
class EUR extends Currency implements Comparable<Currency>{
	// 实现你的构造函数与Comparable中的接口	
	double a;
	public int compareTo(Currency e) {
		if(e.getValue()>a) return 1;
		if(e.getValue()<a) return -1;
		else return 0;
	}
	EUR(int a){
		this.a=a*0.13;
		this.setValue((int)this.a);
		this.setName("EUR");
		this.setOriginalValue(a);
	}
}
public class Main {
	public static void main(String[] args) {
		Currency[] cs = new Currency[3];
		//初始化
		Scanner sc = new Scanner(System.in);
                //利用hasNextXXX()判断是否还有下一输入项
                int a = 0;
                int b = 0;
                int c = 0;
                if (sc.hasNext()) {
                    a = sc.nextInt();
                    cs[0] = new HKD(a);
                }
                if (sc.hasNext()) {
                    b = sc.nextInt();
                    cs[1] = new USD(b);
                }
                if (sc.hasNext()) {
                    c = sc.nextInt();
                    cs[2] = new EUR(c);
                }
		//初始化结束
		//请补充排序
		//请补充输出结果
                Arrays.sort(cs);
                for(Currency obj:cs) {
                	System.out.println(obj.getName()+" "+obj.getOriginalValue());
                }
	}
}
```

