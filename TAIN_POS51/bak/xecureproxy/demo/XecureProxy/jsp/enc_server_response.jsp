<%@ page contentType="text/html; charset=euc-kr" %>
<html>
<head>

<title>��ȣȭ ���� ���</title>
</head>
<body>




<p align='center'><big><strong>��ȣȭ�� Ŭ���̾�Ʈ Request ��ȣȭ ����Դϴ�. </strong></big></p>
request.getRemoteAddr() : <%=request.getRemoteAddr() %><br>
request.getHeader(XECUREIP) : <%=request.getHeader("XECUREIP") %> <br>

<table border='1' width='100%'>
<tr>
<td width='17%'><strong>Decrypted QueryString :</strong></td>
<td width='83%'><strong>
<%=request.getQueryString() %>
</strong></td>
</tr>
<tr>
<td width='17%'><strong>Decrypted QueryString abc :</strong></td>
<td width='83%'><strong>
<%=request.getParameter("abc") %> 
</strong></td>
</tr>

<tr>
<td width='17%'><strong>Decrypted QueryString pop :</strong></td>
<td width='83%'><strong>
<%=request.getParameter("pop" ) %>
</strong></td>
</tr>
<tr>
<td width='17%'><strong>Decrypted text_field1 :</strong></td>
<td width='83%'><strong>
<%=request.getParameter("text_field1" ) %>
</strong></td>
</tr>
<tr>
<td width='17%'><strong>Decrypted text_field2 :</strong></td>
<td width='83%'><strong>
<%=request.getParameter("text_field2" ) %>
</strong></td>
</tr>
</table>

<p> </p>


<p align='center'><a href='/XecureProxy/jsp/enc_client_request.jsp'>���� ȭ��</a></p>

</body></html>
