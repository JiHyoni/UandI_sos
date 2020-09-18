<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8" import="java.sql.*" %>
<% request.setCharacterEncoding("utf-8"); %>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>UandI-Web</title>
</head>
<body>
<h2> UandI - Web </h2>
<hr />
<ol>
</ol>
<h2> SOS 내역 </h2>
<%
	Connection conn = null;
	PreparedStatement pstmt =null;
	
	String jdbc_driver= "com.mysql.cj.jdbc.Driver";
	String jdbc_url="jdbc:mysql://localhost/testmydb?characterEncodint=UTF-8&&serverTimezone=UTC&useSSL=false";
	
	try{
		Class.forName(jdbc_driver);
		conn = DriverManager.getConnection(jdbc_url,"user1","98765");
		String sql = "select time,contents from sos;";
		pstmt = conn.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		
		int i = 1;
		while(rs.next()){
			out.println("<li>"+"# "+i+": "+rs.getString("time")+"</li>");
			out.println("<li>"+rs.getString("contents")+"<li/>");
			i++;
		}
		rs.close();
		pstmt.close();
		conn.close();
		// pstmt.setString(1, request.getParameter("username"));
		// pstmt.setString(2, request.getParameter("email"));

	}catch(Exception e){
		System.out.println(e);
	}


%>
</body>
</html>
