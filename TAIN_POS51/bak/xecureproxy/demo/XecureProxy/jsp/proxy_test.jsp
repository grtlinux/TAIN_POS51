<%@ page import="java.io.*" %>
<%@ page import="java.net.*" %>


<%
 	String  host,method, text1, text2,str,len;
	Socket sock;
	DataInputStream ins;
	DataOutputStream outs;
	
	int port;
	host="127.0.0.1";
	port =8888;
	method=new String(request.getMethod());
	text1=new String(request.getParameter("text_field1"));
	text2=new String(request.getParameter("text_field2"));
	str=method;		
	str+=" http://127.0.0.1:443/XecureProxy/jsp/enc_server_response.jsp?abc=def&pop=hi HTTP/1.0\r\nAccept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/vnd.ms-powerpoint, application/vnd.ms-excel, application/msword, */*\r\n";
	str+="Referer: http://127.0.0.1/XecureProxy/jsp/enc_client_request.jsp\r\nAccept-Language: ko\r\nContent-Type: application/x-www-form-urlencoded\r\nAccept-Encoding: gzip, deflate\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT 5.0)\r\nHost: 127.0.0.1\r\n";
	
	if (method.equals("POST")) 
	{
		len=new String(request.getHeader("Content-Length"));
		str+="Content-Length: ";
		str+=len;
		str+="\r\nProxy-Connection: Keep-Alive\r\nPragma: no-cache\r\n\r\n";
		str+="text_field1=" + text1 + "&text_field2=" + text2 + "\r\n\r\n";
    	}
    	else
    		str+="Proxy-Connection: Keep-Alive\r\nPragma: no-cache\r\n\r\n";
    		
	sock = new Socket(host, port);
	ins = new DataInputStream(sock.getInputStream());
	outs = new DataOutputStream(sock.getOutputStream());
	
	
	outs.write(str.getBytes(), 0, str.length());
	outs.flush();
	
	byte[] read_data = new byte[4096];
	try {
			ins.readFully(read_data, 0, 4096);
			} catch(EOFException e){
			} catch(Exception e){}
	
	String data =new String(read_data);
	
	ins.close();
	outs.close();
	sock.close();  

	
%>

<html>

query string :<%=request.getQueryString()%><br>


method : <%=request.getMethod()%><br>
text_field1 : <%= request.getParameter("text_field1") %><br>
text_field2 : <%= request.getParameter("text_field2") %><br>
read_data : <%= data%>


 
<br>
</html>
