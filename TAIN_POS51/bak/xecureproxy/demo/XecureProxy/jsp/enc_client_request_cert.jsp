<html>
<%@ page contentType="text/html; charset=euc-kr" %>
<br>
<body>

<br>

 
1. ��ȣ���������� �̵�<br>
<br>�̹� ��ȣ������ �ΰ� �ִٸ� ����θ� �̿��Ͽ� ��ȣ���������� �̵��� �����ϴ�.
<pre>
&lt;a href="enc_server_response_cert.jsp" >&lt;/a>
</pre>
<a href="enc_server_response_cert.jsp" >�̵�
</a><br><br>


2. �ٸ� ����Ʈ�� �̵�

<pre>
&lt;a href="http://www.softforum.co.kr" >&lt;/a>
</pre>
<a href="http://www.softforum.co.kr" >�̵�

</a><br><br>


3. ��ȣ�� �̿��� Ŭ���̾�Ʈ FORM Request (GET)<br><br>

<pre>
&lt;form action="enc_server_response_cert.jsp?abc=def&amp;pop=hi" method="get" >
<br>&lt;input type=text name="text_field1" >&lt;br>
<br>&lt;input type=text name="text_field2">&lt;br>
<br>&lt;input type=submit value="����">
<br>&lt;/form>
</pre>

<form action="enc_server_response_cert.jsp?abc=def&amp;pop=hi" method="get" >
<input type=text name="text_field1" ><br>
<input type=text name="text_field2"><br>
<input type=submit value="����">
</form>
<br>

4. ��ȣ�� �̿��� Ŭ���̾�Ʈ FORM Request ( POST )<br><br>

<pre>
&lt;form action="enc_server_response_cert.jsp?abc=def&amp;pop=hi" method="post" >
<br>&lt;input type=text name="text_field1" >&lt;br>
<br>&lt;input type=text name="text_field2">&lt;br>
<br>&lt;input type=submit value="����">
<br>&lt;/form>
</pre>
<% String text1, text2;
   int i;
text1="1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
text2=new String("");
for (i=1;i<100;i++)
 text2=text2 + text1;

 %>
<form action="enc_server_response_cert.jsp?abc=def&pop=hi" method="post">
<textarea name="text_field1" cols=90 rows=15 class="form2" >
<%=text2%>

</textarea><br>
<% text1= "hello\nbye!"; %>
<textarea name="text_field2" cols=90 rows=15 class="form2">
<%=text1%>
</textarea><br>
<input type=submit value="����">
</form>
<br>


6. ��ȣ�� �̿��� ���� �ٿ�ε�
<pre>
&lt;a href="/XecureProxy/file/file.zip" >�ٿ�ε�&lt;/a>
</pre>
<a href="/XecureProxy/file/file.zip">�ٿ�ε�</a>

<br><br>
<br><br>
<center>
<br><a href='/ProxyStart/index.html'>ó�� ȭ������ </a>
</center>
</body>
</html>