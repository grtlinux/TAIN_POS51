@echo off
:: ------------------------------------------------------------------

set MAIN_CLASS=tain.kr.com.proj.pos51.v02.main.Pos51Main

:: ------------------------------------------------------------------

set JAVA_HOME=N:\PROG\jdk1.7.0_79
set JRE_HOME=%JAVA_HOME%

:: set JAVA_EXE=%JAVA_HOME%\bin\javaw.exe
set JAVA_EXE=%JAVA_HOME%\bin\java.exe

:: ------------------------------------------------------------------

set POS51_HOME=N:\TEMP\pos51

set LIB_HOME=%POS51_HOME%\lib

:: ------------------------------------------------------------------

set CP=
set CP=%CP%;%JAVA_HOME%\lib\tools.jar
set CP=%CP%;%JRE_HOME%\lib\rt.jar
set CP=%CP%;%JRE_HOME%\lib\resources.jar
set CP=%CP%;%JRE_HOME%\lib\jsse.jar
set CP=%CP%;%JRE_HOME%\lib\jce.jar
set CP=%CP%;%JRE_HOME%\lib\charsets.jar
set CP=%CP%;%JRE_HOME%\lib\ext\dnsns.jar
set CP=%CP%;%JRE_HOME%\lib\ext\localedata.jar
set CP=%CP%;%JRE_HOME%\lib\ext\sunjce_provider.jar
set CP=%CP%;%JRE_HOME%\lib\ext\sunmscapi.jar
set CP=%CP%;%JRE_HOME%\lib\ext\sunpkcs11.jar

set CP=%CP%;%LIB_HOME%\ant.jar
set CP=%CP%;%LIB_HOME%\commons-logging-1.2.jar
set CP=%CP%;%LIB_HOME%\commons-logging-adapters-1.1.jar
set CP=%CP%;%LIB_HOME%\commons-net-3.3.0.jar
set CP=%CP%;%LIB_HOME%\jnlp.jar
set CP=%CP%;%LIB_HOME%\log4j-1.2.17.jar
set CP=%CP%;%LIB_HOME%\tain-pos51-1.0.jar

:: ------------------------------------------------------------------

set OPTION=-Xms512m -Xmx1024m
set OPTION=%OPTION% -cp %CP%
set OPTION=%OPTION% -Ddev.serial=KK28RWYXBC1067AS
set OPTION=%OPTION% -Ddev.author=Kang_Seok
set OPTION=%OPTION% -Ddev.version=jdk1.7.0_79

:: ------------------------------------------------------------------

set OPTION=%OPTION% -Dtain.pos51.main.loop.wait.sec=60
set OPTION=%OPTION% -Dtain.pos51.01.send.fq.file.path=%POS51_HOME%/TEST/HANWA/send/DAT/YYYYMMDD
set OPTION=%OPTION% -Dtain.pos51.01.send.fq.file.name=OASPOS5101
set OPTION=%OPTION% -Dtain.pos51.01.send.in.file.charset=EUC-KR
set OPTION=%OPTION% -Dtain.pos51.01.send.in.file.path=%POS51_HOME%/TEST/HANWA/send/SEND/YYYYMMDD
set OPTION=%OPTION% -Dtain.pos51.01.send.in.file.name=S_POS_HWPOS000001_YYYYMMDD_SEQ
set OPTION=%OPTION% -Dtain.pos51.01.send.out.file.charset=EUC-KR
set OPTION=%OPTION% -Dtain.pos51.01.send.out.file.path=%POS51_HOME%/TEST/POST_AGENT/send
set OPTION=%OPTION% -Dtain.pos51.01.send.out.file.name=send_YYYYMMDDHHMMSS.txt
set OPTION=%OPTION% -Dtain.pos51.02.recv.in.file.charset=EUC-KR
set OPTION=%OPTION% -Dtain.pos51.02.recv.in.file.path=%POS51_HOME%/TEST/POST_AGENT/receive
set OPTION=%OPTION% -Dtain.pos51.02.recv.in.file.name=recv_YYYYMMDDHHMMSS.txt
set OPTION=%OPTION% -Dtain.pos51.02.recv.mv.file.path=%POS51_HOME%/TEST/POST_AGENT/received
set OPTION=%OPTION% -Dtain.pos51.02.recv.out.file.charset=EUC-KR
set OPTION=%OPTION% -Dtain.pos51.02.recv.out.file.path=%POS51_HOME%/TEST/HANWA/recv/RECV/YYYYMMDD
set OPTION=%OPTION% -Dtain.pos51.02.recv.out.file.name=R_POS_POSHW000002_YYYYMMDD_SEQ
set OPTION=%OPTION% -Dtain.pos51.02.recv.fq.file.path=%POS51_HOME%/TEST/HANWA/recv/DAT/YYYYMMDD
set OPTION=%OPTION% -Dtain.pos51.02.recv.fq.file.name=OARPOS5101
set OPTION=%OPTION% -Dtain.pos51.03.delv.in.file.charset=EUC-KR
set OPTION=%OPTION% -Dtain.pos51.03.delv.in.file.path=%POS51_HOME%/TEST/POST_AGENT/receive
set OPTION=%OPTION% -Dtain.pos51.03.delv.in.file.name=delv_YYYYMMDDHHMMSS.txt
set OPTION=%OPTION% -Dtain.pos51.03.delv.mv.file.path=%POS51_HOME%/TEST/POST_AGENT/received
set OPTION=%OPTION% -Dtain.pos51.03.delv.out.file.charset=EUC-KR
set OPTION=%OPTION% -Dtain.pos51.03.delv.out.file.path=%POS51_HOME%/TEST/HANWA/recv/RECV/YYYYMMDD
set OPTION=%OPTION% -Dtain.pos51.03.delv.out.file.name=R_POS_POSHW000003_YYYYMMDD_SEQ
set OPTION=%OPTION% -Dtain.pos51.03.delv.fq.file.path=%POS51_HOME%/TEST/HANWA/recv/DAT/YYYYMMDD
set OPTION=%OPTION% -Dtain.pos51.03.delv.fq.file.name=OARPOS5101

:: ------------------------------------------------------------------

@echo on

%JAVA_EXE% %OPTION%  %MAIN_CLASS%

::pause


