#!/bin/ksh

#------------------------------------------------------

MAIN_CLASS=tain.kr.com.proj.pos51.v02.main.Pos51Main

#------------------------------------------------------

JAVA_HOME=/usr/lib/jvm/java-1.7.0-openjdk-1.7.0.45.x86_64
JRE_HOME=$JAVA_HOME

JAVA_EXE=${JAVA_HOME}/bin/java

#------------------------------------------------------

POS51_HOME=/hw01/ibridge/KANG/pos51
LIB_HOME=${POS51_HOME}/lib

#------------------------------------------------------

CLASSPATH=${CLASSPATH}:${JAVA_HOME}/lib/tools.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/rt.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/resources.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/jsse.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/jce.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/charsets.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/ext/dnsns.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/ext/localedata.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/ext/sunjce_provider.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/ext/sunmscapi.jar
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/ext/sunpkcs11.jar

CLASSPATH=${CLASSPATH}:${LIB_HOME}/ant.jar
CLASSPATH=${CLASSPATH}:${LIB_HOME}/commons-net-3.3.jar
CLASSPATH=${CLASSPATH}:${LIB_HOME}/log4j-1.2.17.jar
CLASSPATH=${CLASSPATH}:${LIB_HOME}/tain-pos51-1.0.jar

#------------------------------------------------------

# OPTION="-Xss256K"
OPTION="-Xms512m -Xmx1024m"
OPTION="${OPTION} -Dname=Pos51"
OPTION="${OPTION} -Ddev.serial=KK28RWYXBC1067AS"
OPTION="${OPTION} -Ddev.author=Kang_Seok"
OPTION="${OPTION} -Ddev.version=jdk1.7.0_79"

#------------------------------------------------------

OPTION="${OPTION} -Dtain.pos51.main.loop.wait.sec=60"
OPTION="${OPTION} -Dtain.pos51.01.send.fq.file.path=${POS51_HOME}/TEST/HANWA/send/DAT/YYYYMMDD"
OPTION="${OPTION} -Dtain.pos51.01.send.fq.file.name=OASPOS5101"
OPTION="${OPTION} -Dtain.pos51.01.send.in.file.charset=EUC-KR"
OPTION="${OPTION} -Dtain.pos51.01.send.in.file.path=${POS51_HOME}/TEST/HANWA/send/SEND/YYYYMMDD"
OPTION="${OPTION} -Dtain.pos51.01.send.in.file.name=S_POS_HWPOS000001_YYYYMMDD_SEQ"
OPTION="${OPTION} -Dtain.pos51.01.send.out.file.charset=EUC-KR"
OPTION="${OPTION} -Dtain.pos51.01.send.out.file.path=${POS51_HOME}/TEST/POST_AGENT/send"
OPTION="${OPTION} -Dtain.pos51.01.send.out.file.name=send_YYYYMMDDHHMMSS.txt"
OPTION="${OPTION} -Dtain.pos51.02.recv.in.file.charset=EUC-KR"
OPTION="${OPTION} -Dtain.pos51.02.recv.in.file.path=${POS51_HOME}/TEST/POST_AGENT/receive"
OPTION="${OPTION} -Dtain.pos51.02.recv.in.file.name=recv_YYYYMMDDHHMMSS.txt"
OPTION="${OPTION} -Dtain.pos51.02.recv.mv.file.path=${POS51_HOME}/TEST/POST_AGENT/received"
OPTION="${OPTION} -Dtain.pos51.02.recv.out.file.charset=EUC-KR"
OPTION="${OPTION} -Dtain.pos51.02.recv.out.file.path=${POS51_HOME}/TEST/HANWA/recv/RECV/YYYYMMDD"
OPTION="${OPTION} -Dtain.pos51.02.recv.out.file.name=R_POS_POSHW000002_YYYYMMDD_SEQ"
OPTION="${OPTION} -Dtain.pos51.02.recv.fq.file.path=${POS51_HOME}/TEST/HANWA/recv/DAT/YYYYMMDD"
OPTION="${OPTION} -Dtain.pos51.02.recv.fq.file.name=OARPOS5101"
OPTION="${OPTION} -Dtain.pos51.03.delv.in.file.charset=EUC-KR"
OPTION="${OPTION} -Dtain.pos51.03.delv.in.file.path=${POS51_HOME}/TEST/POST_AGENT/receive"
OPTION="${OPTION} -Dtain.pos51.03.delv.in.file.name=delv_YYYYMMDDHHMMSS.txt"
OPTION="${OPTION} -Dtain.pos51.03.delv.mv.file.path=${POS51_HOME}/TEST/POST_AGENT/received"
OPTION="${OPTION} -Dtain.pos51.03.delv.out.file.charset=EUC-KR"
OPTION="${OPTION} -Dtain.pos51.03.delv.out.file.path=${POS51_HOME}/TEST/HANWA/recv/RECV/YYYYMMDD"
OPTION="${OPTION} -Dtain.pos51.03.delv.out.file.name=R_POS_POSHW000003_YYYYMMDD_SEQ"
OPTION="${OPTION} -Dtain.pos51.03.delv.fq.file.path=${POS51_HOME}/TEST/HANWA/recv/DAT/YYYYMMDD"
OPTION="${OPTION} -Dtain.pos51.03.delv.fq.file.name=OARPOS5101"

#------------------------------------------------------

# nohup ${JAVA_EXE} -cp ${CLASSPATH} ${OPTION} ${MAIN_CLASS} $1   > /dev/null 2>&1 &

${JAVA_EXE} -cp ${CLASSPATH} ${OPTION} ${MAIN_CLASS} $1

#------------------------------------------------------

