<%@ page import="java.lang.*" %>
<%@ page import="java.io.*" %>  
<%@ page import="java.security.cert.*" %>
<%@ page import="java.net.*" %>

<%@ page contentType="text/html; charset=euc-kr" %>
<html>
<head>

<title>암호화 데모 결과</title>
</head>
<body>
<p align='center'><big><strong>인증서 기반 암호화 결과화면입니다. </strong></big></p>




request.getRemoteAddr() : <%=request.getRemoteAddr() %><br>
request.getHeader(XECUREIP) : <%=request.getHeader("XECUREIP") %> <br>

<%

 try{
  
 String str;

 str = URLDecoder.decode(request.getHeader("XPCERT"));
 
 CertificateFactory cf = CertificateFactory.getInstance("X.509");
 
 StringBufferInputStream  dis = new StringBufferInputStream(str);
 int n = dis.available();
 byte[] bytes = new byte[n];
 dis.read(bytes, 0, n);
 
 ByteArrayInputStream bais = new ByteArrayInputStream(bytes);
 X509Certificate cert = (X509Certificate)cf.generateCertificate(bais);

%>

<center> <strong> Certificate Information  </center> </strong>
<table border='1' width='100%'>
<tr>
<td width='17%'><strong>Issuer DN</strong></td>
<td width='83%'><strong>
<%=cert.getIssuerDN().getName(); %>
</strong></td>
</tr>
<tr>
<td width='17%'><strong> Serial Number </strong></td>
<td width='83%'><strong>
<%=cert.getSerialNumber();%> 
</strong></td>
</tr>

<tr>
<td width='17%'><strong>Subject DN</strong></td>
<td width='83%'><strong>
<%=cert.getSubjectDN().getName(); %>
</strong></td>
</tr>

<tr>
<td width='17%'><strong>validity period</strong></td>
<td width='83%'><strong>
<%=cert.getNotAfter().toGMTString(); %>
</strong></td>
</tr>
</table>


<p align='center'><big><strong>암호화된 클라이언트 Request 복호화 결과입니다. </strong></big></p>

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


<p align='center'><a href='/XecureProxy/jsp/enc_client_request_cert.jsp'>이전 화면</a></p>

</body></html>


<%  
   } catch (Exception e){
	out.println(e.toString());
 }
%>