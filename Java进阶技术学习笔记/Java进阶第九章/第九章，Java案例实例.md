# 第九章，Java案例实例

![](D:\桌面\后端\进阶作业图片\第九章\1.jpg)



## 作业

![](D:\桌面\后端\进阶作业图片\第九章\2.png)

![3](D:\桌面\后端\进阶作业图片\第九章\3.png)

```java
import java.net.*;
import java.io.*;

public class TcpClient {
	public static void main(String[] args) {
		try {
			Socket s = new Socket(InetAddress.getByName("127.0.0.1"), 8001);
			InputStream ips = s.getInputStream();   
			BufferedReader brNet = new BufferedReader(new InputStreamReader(ips));			
			OutputStream ops = s.getOutputStream(); 
			DataOutputStream dos = new DataOutputStream(ops);			
			BufferedReader brKey = new BufferedReader(new InputStreamReader(System.in));
			while (true) 
			{
				String strWord = brKey.readLine();
				if (strWord.equalsIgnoreCase("quit"))
				{
					break;
				}
				else
				{
					System.out.println("I want to send: " + strWord);
					dos.writeBytes(strWord + System.getProperty("line.separator"));
					
					System.out.println("Server said: " + brNet.readLine());
				}				
			}			
			dos.close();
			brNet.close();
			brKey.close();
			s.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

```



```java
import java.net.*;
import java.io.*;
public class TcpServer
{
	public static void main(String [] args) 
	{
		try
		{
			ServerSocket ss=new ServerSocket(8001); 
			Socket s=ss.accept();                 
			System.out.println("welcome to the java world");
			InputStream ips=s.getInputStream();    
			OutputStream ops=s.getOutputStream();  
			
			ops.write("<head><body>hello</body></html>".getBytes());  	
			BufferedReader br = new BufferedReader(new InputStreamReader(ips));		
			System.out.println("Client said: " + br.readLine());			
			ips.close();          
			ops.close();
			s.close();
			ss.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
```

