# 第七章，Java数据库编程

![](D:\桌面\后端\进阶作业图片\第七章\1.jpg)

![2](D:\桌面\后端\进阶作业图片\第七章\2.jpg)

![3](D:\桌面\后端\进阶作业图片\第七章\3.jpg)

![4](D:\桌面\后端\进阶作业图片\第七章\4.jpg)

![5](D:\桌面\后端\进阶作业图片\第七章\5.jpg)

![6](D:\桌面\后端\进阶作业图片\第七章\6.jpg)

![7](D:\桌面\后端\进阶作业图片\第七章\7.jpg)



## 作业

![](D:\桌面\后端\进阶作业图片\第七章\a.png)

```
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DoIt {
	public static void main(String[] args){    	
  	  
        Connection conn = null;
        try {
            conn = DruidFactory1.getConnection();
            System.out.println("连接池构建成功！");    
            Statement stmt = conn.createStatement(); 
            System.out.println("创建Statement成功！");  
            ResultSet rs = stmt.executeQuery("select * from t_mail where id = 1");
            while(rs.next())
            {
            	System.out.println("获取数据成功");
				MailSend ms = new MailSend(rs.getString("from"), rs.getString("to"), rs.getString("subject"),
						rs.getString("content"));
				ms.init();
				ms.sendMessage();
				ms.close();
            }
            rs.close();
            stmt.close();
        } catch (Exception e){
            e.printStackTrace();
        } finally {
        	try	{
        		if(null != conn) {
            		conn.close();
            	}
        	} catch (SQLException e){
                e.printStackTrace();
        	}        	
        }
    }
}

```

```
import java.sql.Connection;

import com.alibaba.druid.pool.DruidDataSource;


public class DruidFactory1 {
	private static DruidDataSource dataSource = null;

	public static void init() throws Exception {
		
		dataSource = new DruidDataSource();
		dataSource.setDriverClassName("com.mysql.jdbc.Driver"); 
		dataSource.setUsername("root");
		dataSource.setPassword("123456");
		dataSource.setUrl("jdbc:mysql://localhost:3306/mybatis?useSSL=false");
		dataSource.setInitialSize(5);
		dataSource.setMinIdle(1); 
		dataSource.setMaxActive(10);
	}
	
	public static Connection getConnection() throws Exception {
		if(null == dataSource)
		{
			init();
		}
        return dataSource.getConnection();
    }
}

```

```
import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

import java.util.*;

public class MailSend {
	private Session session;
	private Transport transport;
	private String from;
	private String to;
	private String subject;
	private String content;
	private String password = "";
	private String smtpServer = "smtp.qq.com";
	
	public MailSend(String from, String to, String subject, String content) {
		this.from = from;
		this.to = to;
		this.subject = subject;
		this.content = content;
	}
	
	public void init()throws Exception
	  {
	    Properties  props = new Properties();
	    props.put("mail.transport.protocol", "smtp");
	    props.put("mail.smtp.class", "com.sun.mail.smtp.SMTPTransport");
	    props.put("mail.smtp.host", smtpServer); 
	    props.put("mail.smtp.port", "25");
	    props.put("mail.smtp.auth", "true");
	    session = Session.getInstance(props,new Authenticator(){   
	        public PasswordAuthentication getPasswordAuthentication() { 
	          return new PasswordAuthentication(from, password); 
	        }            
	 });
	    session.setDebug(true);
	    transport = session.getTransport();           
	  }
	public void sendMessage() throws Exception {
		Session session = Session.getDefaultInstance(new Properties());
		MimeMessage message = new MimeMessage(session);
		message.setFrom(new InternetAddress(from));
		message.setRecipients(Message.RecipientType.TO, InternetAddress.parse(to));
		message.setSentDate(new Date());
		message.setSubject(subject);
		message.setText(content);
		message.saveChanges();
		transport.connect();
		transport.sendMessage(message, message.getAllRecipients());
		System.out.println("发送邮件成功");
	}
	public void close()throws Exception
	  {
		transport.close();
	  }
}

```

