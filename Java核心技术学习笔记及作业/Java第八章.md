# 第八章 Java常用类

## 第一节 Java类库概述

包名以Java开始的是Java核心包，以Javax开始的是扩展包

java.lang.*      基本类库，不用特意用import

java.math.*      数字函数 

java.text.*         文本的处理

java.time.*         时间的处理

java.util.*        工具包

**查询API类库**  Java API文档

## 第二节 数字相关类

BigInteger：大整数类，支持无限大的整数运算，用字符串赋值

BigDecimal：大浮点数，支持无限大的小数运算，用字符串赋值

Random 随机数类

Math  工具类

```java
import java.math.BigInteger
BigInteger b1 = new BigInteger("123456789");
BigInteger b2 = new BigInteger("987654321");
b2.add(b1);//加法
b2.substract(b1);//减法
b2.multiply(b1);//乘法
b2.divide(b1);//除法
b2.max(b1);//最大值
b2.min(b1);//最小值
result[] = b2.divideAndRemainder(b1);//result[0]𫇭shang result[1] wei yu
b2.equals(b1);//等价性
b2.compareTo(b1);//比大小，返回-1，0，1
```

```java
import java.math.BigDecimal
    b2.divide(b1,3,BigDecimal.ROUND_HALF_UP);//3指保留三位小数，后面那个指四舍五入
```

```java
import java.util.random;
nextInt();//返回一个随机int
nextInt(int a);//返回[0，a）之间的随机int
next Double();//返回一个【0.0，1.0】之间的double
ints();//方法，批量返回随机数数组
Math.random();//返回一个【0.0，1.0】之间的double
Math.round();//四舍五入
rd.方法//random缩写为rd
arr = rd.ints(5,10,100).toArray();//返回5个【10，100】的数

```

```java
java.lang.Math
    Math.abs(-5);//绝对值，为5
         .max(-5,-8);//最大值，为-5
         .pow(-5,-2);//求幂，为25.0
         .round(3.5);//四舍五入，为4
        .ceil(3.5);//向上取整，为4.0
       Math.floor(3.5);//向下取整，为3.0
```

## 第三节，字符串相关类

```java
String a = "123;456;789";//以下所有方法，a的原始值不变
a.charAt(0);//返回第0个元素
a.indexof(";");//返回第一个；的位置
a.concat(";000");//连接一个新的字符串并返回，a不变
a.endsWith("000");//判断a是否以000结尾
a.contains("000");//判断a是否包含000
a.equals("000");//判断a是否等于000
a.equalsIgnoreCase("000");//判断忽略大小写下是否等于000
a.length();//返回a的长度
a.trim();//返回去掉a前后空格的字符串，中间的空格未去掉
String[] b = a.split(";");//将a按；分割成字符串数组
a.substring(2,5);//截取a的第二个到第五个字符
a.replace("1","a");//将所有的“1”换成“a”
a.replaceAll("1","a");//第一个参数是正则表达式，如[?]表示?
a.charAt(0)-'0';//字符串转数字
```

**可变字符串**

StringBuffer ：不同步

StringBulider：同步

```java
StringBuffer sb1 = new StringBuffer("123");
StringBuffer sb2 = sb1;//sb2和sb1指向同一内存，一改则全改，原地修改
//如果是String，则sb2改，sb1还是不变
```

速度：String<StringBuffer<StringBuilder

StringBuffer的初始大小为16+字符串长度，用sb2.append("112")在其上加长度，初始长度不变，一旦所加超过初始大小，则大小变为（16+此时字符串）*2

## 第四节，时间相关类

Calendar 是最常用的，是**抽象类**

```java
import java.util.Calendar
    Calendar cd = Calendar.genInstance();
.get(Field);//获取时间中的每个属性的值，月份从0-11
.getTime();//返回相应的Date对象
.getTimelnMillis();//返回自1970.1.1以来的毫秒数
.set(Field);//设置时间段
add(field,amount);//指定位置增加减少时间，会进位
aoll(field,amount);//不进位，日的加减不影响月
   
```

**java.time包**

```
//主要类
LocalDate:日期类
LocalTime:时间类
LocalDateTime:
Instant:时间戳
```

```java
//Instant
import java.time.Duration;
Instant timestamp = Instant.now()//当前时间戳
```

## 格式化相关类

-NumberFormat  :数字格式化，抽象类

​           工厂模式：DecimalFormal

-MessageFormat：字符串格式化

-DateFormat：日期/时间格式化，抽象类

​          工厂模式：SimpleDateFormal

java.time.format包里-DateTimeFormal

```java
//NumberFormat
import java.text.DecimalFormat;
   DecimalFormat df1,df2;
   df1 = new DecimalFormaat("#,00");
    df2 = new DecimalFormaat("0,00");
   df1.formal(0.1);//输出为.10   
    df2.formal(0.1);//输出为0.10

   DecimalFormat df3 = new DecimalFormat("#,##0,00");
    df3.format(data);//每三位插入“，”显示
```

**＃能省则省，即0不显示**

在整数部分，‘#’和“0”作用一样

```java
//MessageFormat 字符串格式化
String message = "{0}{1}";
object[] array = new object[]{"A","B"};
String value = MessageFormat(message,array);
//a <=>{0},B <=> {1};
//value = "AB";

```

DateFormat 抽象类

-SimpleDateFormat 工厂模式

-parse 将字符串格式化为事件对象

-format 将时间对象格式化为字符串

```java
import java.text.DateFormat;
String steDate = "2008-10-19 10:11:30:345";
String pat1 = "yyyy-MM-dd HH:mm:ss:sss";//模板1
String pat2 = "yyyy年MM月dd日 HH时mm分ss秒sss毫秒";//模板2，变为指定格式
SimpleDateFormat sdf1 = new SimpleDateFormat(pat1);//
SimpleDateFormat sdf2 = new SimpleDateFormat(pat2);//
Dat d = null;
d = sdf1.parse(strDate);
sdf2.format(d);//将日期变成新的格式
```



Java.time.format.DateFormatter 时间格式化

-ofPattern 设定时间格式

-parse

-format

## 作业1

```java
import java.util.Scanner;
public class JudgeIdNumber {

	public static void main(String[] args) {
		Scanner ch = new Scanner(System.in);
       String num = ch.nextLine();
       if(num.length() != 18) {
    	   System.out.println("0000-00-00");
       }
       else if(num.length() == 18) {
    	   for(int i=0;i<17;i++) {
    		   if(!(num.charAt(i)>='0' && num.charAt(i)<='9') ) {
    			   System.out.println("0000-00-00");
    			   break;
    		   }
    		   char c = num.charAt(17);
    	if(!(c>='a'&& c <='z')||(c>='0'&&c<='9')) {
    		 System.out.println("0000-00-00");
    	}
    	   }
    	   String year = num.substring(6,10);
    	   String month = num.substring(10,12);
    	   String day = num.substring(12,14);
    	  
    		   if(!(Integer.parseInt(year,10)>0000 && Integer.parseInt(year,10)<2021) ){
    		   System.out.println("0000-00-00");
    	    }
    		   if(!(Integer.parseInt(month,10)>00 && Integer.parseInt(month,10)<13)) {
    			   System.out.println("0000-00-00");
    		   }
    		   if(!(Integer.parseInt(day,10)<32 &&Integer.parseInt(day,10)>00)){
    			   System.out.println("0000-00-00");
    		   }
    	   System.out.println(year+"-"+month+"-"+day);
    	   
    	   
       }
	}


}

```

![](D:\桌面\后端\图片\Java第八章作业图片\1.png)



## 作业2

```java
import java.util.Scanner;
public class JudgeIdNumberTwo {
	public static void main(String[] args) {
		int a[] = new int[17];
		Scanner ch = new Scanner(System.in);
       String num = ch.nextLine();
       if(num.length() != 18) {
    	   System.out.println("0000-00-00");
       }
       else if(num.length() == 18) {
    	   for(int i=0;i<17;i++) {
    		   if(!(num.charAt(i)>='0' && num.charAt(i)<='9') ) {
    			   System.out.println("0000-00-00");
    			   break;
    		   }
    		   char c = num.charAt(17);
    	if(!(c>='a'&& c <='z')||(c>='0'&&c<='9')) {
    		 System.out.println("0000-00-00");
    	}
    	   }
    	   String year = num.substring(6,10);
    	   String month = num.substring(10,12);
    	   String day = num.substring(12,14);
    	  
    		   if(!(Integer.parseInt(year,10)>0000 && Integer.parseInt(year,10)<2021) ){
    		   System.out.println("0000-00-00");
    	    }
    		   if(!(Integer.parseInt(month,10)>00 && Integer.parseInt(month,10)<13)) {
    			   System.out.println("0000-00-00");
    		   }
    		   if(!(Integer.parseInt(day,10)<32 &&Integer.parseInt(day,10)>00)){
    			   System.out.println("0000-00-00");
    		   }
    		  for(int m =0;m<17;m++) {
    			a[m] =num.charAt(m) - '0';
    		  }
    		 int sum;
    		  sum = 7*a[0]+9*a[1]+10*a[2]+5*a[3]+8*a[4]+4*a[5]+2*a[6]+1*a[7]+6*a[8]+3*a[9]+7*a[10]+9*a[11]+10*a[12]+5*a[13]+8*a[14]+4*a[15]+2*a[16];
    		   int yu = sum%11;
    		  String jiaoYanMa = new String();
    		   switch(yu) {
    		   case 0:jiaoYanMa="1";break;
    		   case 1:jiaoYanMa="0";break;
    		   case 2:jiaoYanMa="x";break;
    		   case 3:jiaoYanMa="9";break;
    		   case 4:jiaoYanMa="8";break;
    		   case 5:jiaoYanMa="7";break;
    		   case 6:jiaoYanMa="6";break;
    		   case 7:jiaoYanMa="5";break;
    		   case 8:jiaoYanMa="4";break;
    		   case 9:jiaoYanMa="3";break;
    		   case 10:jiaoYanMa="2";break;
    		   default: System.out.println("0000-00-00");break;
    		   }
    		 if(jiaoYanMa.charAt(0) ==num.charAt(17) ) {
    			   System.out.println(year+"-"+month+"-"+day);
    			   System.out.println("校验码为"+jiaoYanMa.charAt(0));
    		 }
    		   
    		   
    	 
    	   
    	   
       }
	}


}



```

![](D:\桌面\后端\图片\Java第八章作业图片\2.png)