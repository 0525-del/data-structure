# 第五章，Java多线程和并发编程

![](D:\桌面\后端\进阶作业图片\第五章\a.jpg)

![b](D:\桌面\后端\进阶作业图片\第五章\b.jpg)

![c](D:\桌面\后端\进阶作业图片\第五章\c.jpg)

![d](D:\桌面\后端\进阶作业图片\第五章\d.jpg)

![e](D:\桌面\后端\进阶作业图片\第五章\e.jpg)

![f](D:\桌面\后端\进阶作业图片\第五章\f.jpg)

![g](D:\桌面\后端\进阶作业图片\第五章\g.jpg)

![h](D:\桌面\后端\进阶作业图片\第五章\h.jpg)

![i](D:\桌面\后端\进阶作业图片\第五章\i.jpg)

![j](D:\桌面\后端\进阶作业图片\第五章\j.jpg)

![k](D:\桌面\后端\进阶作业图片\第五章\k.jpg)

![l](D:\桌面\后端\进阶作业图片\第五章\l.jpg)



## 作业

```

public class Sum {
	public static void main(String[] args) {
		int m = 1;
		int n =100000000;
		int partSize = n/6;
		int mod = n%6;
		SumNumThread t = new SumNumThread();
		for(int i =0;i<6;i++) {
			t.partSizes[i]=partSize;
			if(mod>0) {
				t.partSizes[i]++;
				mod--;
			}
		}
		t.startNums[0]=m;
		for(int i =1;i<6;i++) { 
			t.startNums[i]=t.startNums[i-1]+t.partSizes[i-1];
		}
		new Thread(t, "Thread-1").start();
		new Thread(t, "Thread-2").start();
		new Thread(t, "Thread-3").start();
		new Thread(t, "Thread-4").start();
		new Thread(t, "Thread-5").start();
		new Thread(t, "Thread-6").start();

		while (true) {
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
			if (t.endFlag == 6) {
				break;
			}
		}
		System.out.print("total="+t.sum);
	}
}

class SumNumThread implements Runnable {
	public volatile long sum = 0; 
	public volatile int seq = 0; 
	public volatile int endFlag = 0;
	public volatile int[] partSizes= new int[6]; 
	public volatile int[] startNums= new int[6]; 
	public void run() {
		int seq = getSeq();
		int tempNum = startNums[seq];
		int partSize = partSizes[seq];
		long partSum = 0;
		int i = 0;
		for(i = 0;i<partSize;i++) {
			partSum+=tempNum;
			tempNum++;
		}
		sum(partSum);
		setEndFlag();
		System.out.println("Thread-"+seq+": "+startNums[seq]+"~"+(tempNum-1)+"("+i+") sum="+partSum);
	}

	public synchronized int getSeq() { 
		return seq++;
	}

	public synchronized void setEndFlag() {
		this.endFlag++;
	}

	public synchronized void sum(long partSum) { 
		this.sum+=partSum;
	}
}


```

![](D:\桌面\后端\进阶作业图片\第五章\1.png)





![2](D:\桌面\后端\进阶作业图片\第五章\2.png)