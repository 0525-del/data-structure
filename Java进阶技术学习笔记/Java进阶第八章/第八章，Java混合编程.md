# 第八章，Java混合编程

![](D:\桌面\后端\进阶作业图片\第八章\1.jpg)

![2](D:\桌面\后端\进阶作业图片\第八章\2.jpg)

![3](D:\桌面\后端\进阶作业图片\第八章\3.jpg)

![4](D:\桌面\后端\进阶作业图片\第八章\4.jpg)

![5](D:\桌面\后端\进阶作业图片\第八章\5.jpg)



## 作业

​		Naming.bind("rmi://127.0.0.1:8001/warehouse1",(Remote)centralWarehouse);有问题，无能力解决

```
import java.rmi.Naming;
import java.rmi.Remote;
import java.rmi.registry.LocateRegistry;
public class FuWuDuan {
 
	public static void main(String[] args) throws Exception {
		System.out.println("产生服务器对象");
		FuWuDuan centralWarehouse=new FuWuDuan();
		System.out.println("将服务器对象绑定在8001端口");
		LocateRegistry.createRegistry(8001);//定义端口
		Naming.bind("rmi://127.0.0.1:8001/warehouse1",(Remote)centralWarehouse);
		System.out.println("等待客户端");
		
	}

 
}
```

```
import java.rmi.RemoteException;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.List;
import java.util.Scanner;
 
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NameClassPair;
import javax.naming.NamingException;
public class KeHuDuan {
 
	public static void main(String[] args)throws NamingException,RemoteException{
		Context namingContext=new InitialContext();
		System.out.print("RMI 注册表绑定列表：");
		Enumeration<NameClassPair>e=namingContext.list("rmi://127.0.0.1:8001/");
		while(e.hasMoreElements()) {
			System.out.println(e.nextElement().getName());
		}
		String url="rmi://127.0.0.1:8001/warehouse1";
		Warehouse centralWarehouse=(Warehouse) namingContext.lookup(url);
		
		Scanner in=new Scanner(System.in);
		System.out.println("Enter keywords:");
		String kewords=in.nextLine();
		List<String> result=centralWarehouse.cmdExec(kewords);
		for(String res:result) {
			System.out.println(res);
		}
		in.close();
		
	}
 
}
```

```
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;
 
public interface Warehouse extends Remote{
    List<String> cmdExec(String cmd)throws RemoteException;
}
```

```
import java.io.BufferedReader;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.List;
 
public class WarehouseImpl extends UnicastRemoteObject implements Warehouse{
    String cmd1="javac HelloWorld";
    String cmd2="java HelloWorld";
	protected WarehouseImpl() throws RemoteException {
		super();
		
	}
	public List<String> cmdExec(String cmd) throws RemoteException {
		List<String> result=new ArrayList<String>();
		if(cmd1.equals(cmd)) {
			Process p;
			String[] cmds=new String[2];
			cmds[0]="javac";
			cmds[1]="D:/temp/HelloWord.java";
			try {
				p=Runtime.getRuntime().exec(cmds);
				InputStream fis=p.getInputStream();
				InputStreamReader isr=new InputStreamReader(fis);
				BufferedReader br=new BufferedReader(isr);
				String line=null;
				while((line=br.readLine())!=null) {
					result.add(line);
				}
				System.out.println("");
				int exitVal=p.waitFor(); 
				System.out.println("Process exitValue: "+exitVal);
			}catch(Exception e) {
				e.printStackTrace();
			}
			result.add("编译成功");
			return result;
		}else if(cmd2.equals(cmd)){
			Process p;
			String[] cmds=new String[2];
			cmds[0]="java";
			cmds[1]="HelloWorld";
			
			try {
				p=Runtime.getRuntime().exec(cmds,null,new File("D:/temp"));
				InputStream fis=p.getInputStream();
				InputStreamReader isr=new InputStreamReader(fis);
				BufferedReader br=new BufferedReader(isr);
				String line=null;
				while((line=br.readLine())!=null) {
					result.add(line);
					System.out.println(line);
				}
				System.out.println("");
				int exitVal=p.waitFor(); 
				System.out.println("Process exitValue: "+exitVal);
			}catch(Exception e) {
				e.printStackTrace();
			}
			result.add("执行成功");
			return result;
 
		}else {
			Process p;
			try {
				p=Runtime.getRuntime().exec(cmd);
				InputStream fis=p.getInputStream();
				InputStreamReader isr=new InputStreamReader(fis);
				BufferedReader br=new BufferedReader(isr);
				String line=null;
				while((line=br.readLine())!=null) {
					result.add(line);
				}
				System.out.println("");
				int exitVal=p.waitFor();
				System.out.println("Process exitValue: "+exitVal);
			}catch(Exception e) {
				e.printStackTrace();
			}
			return result;
		}
		
	}
 
}
```

![](D:\桌面\后端\进阶作业图片\第八章\a.png)