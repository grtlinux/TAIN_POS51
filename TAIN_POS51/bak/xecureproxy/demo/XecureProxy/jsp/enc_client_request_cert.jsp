<html>
<%@ page contentType="text/html; charset=euc-kr" %>
<br>
<body>

<br>

 
1. 암호페이지간의 이동<br>
<br>이미 암호세션을 맺고 있다면 상대경로를 이용하여 암호페이지간의 이동이 가능하다.
<pre>
&lt;a href="enc_server_response_cert.jsp" >&lt;/a>
</pre>
<a href="enc_server_response_cert.jsp" >이동
</a><br><br>


2. 다른 사이트로 이동

<pre>
&lt;a href="http://www.softforum.co.kr" >&lt;/a>
</pre>
<a href="http://www.softforum.co.kr" >이동

</a><br><br>


3. 암호를 이용한 클라이언트 FORM Request (GET)<br><br>

<pre>
&lt;form action="enc_server_response_cert.jsp?abc=def&amp;pop=hi" method="get" >
<br>&lt;input type=text name="text_field1" >&lt;br>
<br>&lt;input type=text name="text_field2">&lt;br>
<br>&lt;input type=submit value="전송">
<br>&lt;/form>
</pre>

<form action="enc_server_response_cert.jsp?abc=def&amp;pop=hi" method="get" >
<input type=text name="text_field1" ><br>
<input type=text name="text_field2"><br>
<input type=submit value="전송">
</form>
<br>

4. 암호를 이용한 클라이언트 FORM Request ( POST )<br><br>

<pre>
&lt;form action="enc_server_response_cert.jsp?abc=def&amp;pop=hi" method="post" >
<br>&lt;input type=text name="text_field1" >&lt;br>
<br>&lt;input type=text name="text_field2">&lt;br>
<br>&lt;input type=submit value="전송">
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
<input type=submit value="전송">
</form>
<br>


6. 암호를 이용한 파일 다운로드
<pre>
&lt;a href="/XecureProxy/file/file.zip" >다운로드&lt;/a>
</pre>
<a href="/XecureProxy/file/file.zip">다운로드</a>

<br><br>
<br><br>
<center>
<br><a href='/ProxyStart/index.html'>처음 화면으로 </a>
</center>
</body>
</html>